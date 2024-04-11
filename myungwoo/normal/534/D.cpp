#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define all(v) (v).begin(), (v).end()

int N;
vector <int> num[MAXN];
multiset <int> val[3];

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		int k;
		scanf("%d", &k); num[k].push_back(i);
		val[k%3].insert(k);
	}
	vector <int> seq;
	bool imp = 0;
	for (int i=0,v=0;i<N;i++,v++){
		if (num[v].empty()){
			auto it = val[v%3].lower_bound(v);
			if (it == val[v%3].begin()){ imp = 1; break; }
			--it;
			v = *it;
		}
		int x = num[v].back();
		seq.push_back(x);
		num[v].pop_back();
		val[v%3].erase(val[v%3].find(v));
	}
	if (imp) puts("Impossible");
	else{
		puts("Possible");
		for (int v: seq) printf("%d ", v); puts("");
	}
}
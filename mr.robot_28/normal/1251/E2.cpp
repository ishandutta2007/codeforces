#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int t, n;
vector <int> v[N];

int main() {	
	int t;
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			v[i].clear();
		for(int i = 0; i < n; ++i){
			int x, s;
			scanf("%d %d", &x, &s);
			v[x].push_back(s);
		}		
		
		multiset <int > q;
		long long res = 0;
		int pref = n;
		int cnt = 0;
		for(int i = n - 1; i >= 0; --i){
			pref -= v[i].size();
			int need = i - pref;
			for(auto x : v[i]) q.insert(x);

			while(cnt < need){
				++cnt;
				res += *q.begin();				
				q.erase(q.begin());
			}
		}		

        	printf("%lld\n", res);
        }
	return 0;
}
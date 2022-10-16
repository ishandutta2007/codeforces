#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;

multimap<int, pii> opened;
multiset<int> _opened;

const int maxn = 100100;

ppi notes[maxn];
ppp actors[maxn];
int ans[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &notes[i].first.first, &notes[i].first.second);
		notes[i].second = i;
	}
	sort(notes, notes + n);

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i){
		scanf("%d%d%d", &actors[i].first.first, &actors[i].first.second, &actors[i].second.first);
		actors[i].second.second = i + 1;
	}

	sort(actors, actors + m);

	for (int i = 0, j = 0; i < n; ++i){
		for (;j < m && actors[j].first.first <= notes[i].first.first; ++j)
			opened.insert( {actors[j].first.second, actors[j].second} );

		auto it = opened.lower_bound(notes[i].first.second);
		
		if (it == opened.end()){
			printf("NO\n");
			exit(0);
		}
		else{
			int val = it->first;
			pii cur = it->second;
			ans[notes[i].second] = cur.second;
			cur.first--;
			opened.erase(it);			
			if (cur.first)
				opened.insert({val, cur});
		}
	}

	printf("YES\n");
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	putchar('\n');

	return 0;
}
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

std::vector<int> v[501000];
int p[501000];
std::set<int> st;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d", &n);
		for(int i = 1; i <= n + 1; i++) v[i].clear(), p[i] = 0;
		st.clear();
		bool ok = 0;
		for(int i = 1; i <= n; i++)
		{
			int r; scanf("%d", &r);
			if(r == -1) continue;
			auto k = st.upper_bound(i);
			if(k != st.end() && *k < r) ok = 1;
			st.insert(r);
			v[r].push_back(i);
		}
		if(ok) {puts("-1"); continue;}
		int tot = n + 1;
		for(int i = n + 1; i >= 1; i--)
		{
			if(!p[i]) p[i] = tot--;
			int S = v[i].size();
			for(int j = 0; j < S; j++) p[v[i][j]] = tot--;
		}
		for(int i = 1; i <= n; i++) printf("%d ", p[i]); puts("");
	}
}
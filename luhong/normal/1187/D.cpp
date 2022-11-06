#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define MN 301000
 
int c[MN], a[MN];
int n; 
std::vector<int> v[MN];
int h[MN];
 
void ins(int *c, int x, int v) {x = n - x + 1; for(int i = x; i <= n; i += i & -i) c[i] = std::min(c[i], v);}
int query(int *c, int x) {x = n - x + 1; int ans = 2e9; for(int i = x; i; i -= i & -i) ans = std::min(ans, c[i]); return ans;}
 
int main()
{
	memset(c, 0x3f, sizeof(c));
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n); 
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++)
		{
			int a; scanf("%d", &a);
			v[a].push_back(i);
		}
		bool ok = 0;
		for(int i = 1; i <= n; i++)
		{
			if(h[a[i]] >= v[a[i]].size()) {ok = 1; break;}
			int w = v[a[i]][h[a[i]]];
			if(query(c, w) < a[i]) {ok = 1; break;}
			ins(c, w, a[i]);
			h[a[i]]++;
		}
		if(ok) puts("NO");
		else puts("YES");
		for(int i = 1; i <= n; i++) c[i] = 2e9, v[i].clear(), h[i] = 0;
	}
}
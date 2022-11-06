#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MN 201000

typedef long long ll;

int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
int ch[MN][26], fail[MN], tot = 1;
int qq[MN], hh = 0, tt = 0;
char s[MN]; 
std::vector<int> v[MN];
int dfn[MN], siz[MN], D = 0;
ll Ans[501000], c[MN];

struct xxx{
	int x, k, t, id;
	xxx(){}
	xxx(int a, int b, int c, int d) {x = a; k = b; t = c; id = d;}
}q[1010000];

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

bool cmp(xxx a, xxx b) {return a.x < b.x;}

void add(int x) {for(int i = x; i <= D; i += i & -i) c[i]++;}
ll query(int x) {int ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}

void build_AC()
{
	for(int i = 0; i < 26; i++)
	{
		if(!ch[1][i]) ch[1][i] = 1;
		else fail[ch[1][i]] = 1, ins(fail[ch[1][i]], ch[1][i]), qq[tt++] = ch[1][i]; 
	}
	while(hh < tt)
	{
		int u = qq[hh++];
		for(int i = 0; i < 26; i++)
		{
			if(ch[u][i]) 
			{
				fail[ch[u][i]] = ch[fail[u]][i];
				ins(fail[ch[u][i]], ch[u][i]);
				qq[tt++] = ch[u][i];
			}
			else ch[u][i] = ch[fail[u]][i];
		}
	}
}

void dfs(int x)
{
	dfn[x] = ++D; siz[x] = 1;
	for(int i = h[x]; i; i = nxt[i]) dfs(to[i]), siz[x] += siz[to[i]];
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s); int len = strlen(s);
		int now = 1;
		for(int j = 0; j < len; j++)
		{
			if(!ch[now][s[j] - 'a']) ch[now][s[j] - 'a'] = ++tot;
			now = ch[now][s[j] - 'a'];
			v[i].push_back(now);
		}
	}
	
	build_AC();
	
	int tt = 0;
	for(int i = 1; i <= m; i++)
	{
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		if(l - 1 >= 1) q[++tt] = xxx(l - 1, k, -1, i);
		q[++tt] = xxx(r, k, 1, i); 
	}
	
	dfs(1); std::sort(q + 1, q + tt + 1, cmp);
	int k = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < v[i].size(); j++) add(dfn[v[i][j]]);
		while(k <= tt && q[k].x == i) 
		{
			int u = v[q[k].k][v[q[k].k].size() - 1];
			Ans[q[k].id] += q[k].t * (query(dfn[u] + siz[u] - 1) - query(dfn[u] - 1));
			k++;
		}
	}
	
	for(int i = 1; i <= m; i++) printf("%lld\n", Ans[i]);
}
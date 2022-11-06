#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
 
#define MN 101000
#define T 200
 
typedef long long ll;
 
struct xxx{
	int l, r, id;
};
 
int n, m;
int ch[MN][26], fail[MN], w[MN], tot = 1;
int q[MN], hh = 0, tt = 0;
int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
char s[MN];
std::vector<int> end[MN];
std::vector<char> c[MN];
std::vector<xxx> Q[MN], v[MN];
ll Ans[MN];
int dfn[MN], siz[MN], D = 0;
int tag[MN], a[MN], cnt[MN];
ll sum[MN], ans[MN];
 
void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}
 
void add(int x, int v)
{
	int bl = x / T;
	for(int i = bl + 1; i <= n / T; i++) tag[i] += v;
	for(int i = bl * T; i < (bl + 1) * T; i++) a[i] += tag[bl]; tag[bl] = 0;
	for(int i = x; i < (bl + 1) * T; i++) a[i] += v;
}
 
ll query(int x) {return tag[x / T] + a[x];}
 
void dfs(int x)
{
	for(int i = 0; i < end[x].size(); i++) add(end[x][i], 1);
	for(int i = 0; i < v[x].size(); i++) ans[v[x][i].id] += query(v[x][i].r) - query(v[x][i].l - 1);
	
	dfn[x] = ++D; siz[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
		dfs(to[i]), siz[x] += siz[to[i]];
		
	for(int i = 0; i < end[x].size(); i++) add(end[x][i], -1);
}
 
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s); int len = strlen(s);
		int now = 1;
		for(int j = 0; j < len; j++)
		{
			c[i].push_back(s[j]);
			if(!ch[now][s[j] - 'a']) ch[now][s[j] - 'a'] = ++tot;
			now = ch[now][s[j] - 'a'];
		}
		w[i] = now; end[now].push_back(i);
	}
	
	for(int i = 0; i < 26; i++)
	{
		if(ch[1][i])
		{
			fail[ch[1][i]] = 1;
			ins(1, ch[1][i]);
			q[tt++] = ch[1][i];
		}
		else ch[1][i] = 1;
	}
	
	while(hh < tt)
	{
		int u = q[hh++];
		for(int i = 0; i < 26; i++)
		{
			if(ch[u][i])
			{
				fail[ch[u][i]] = ch[fail[u]][i];
				ins(fail[ch[u][i]], ch[u][i]);
				q[tt++] = ch[u][i];
			}
			else ch[u][i] = ch[fail[u]][i];
		}
	}
	
	for(int i = 1; i <= m; i++)
	{
		int x; xxx q;
		scanf("%d%d%d", &q.l, &q.r, &x);
		q.id = i;
		if(c[x].size() <= T)
		{
			int now = 1;
			for(int j = 0; j < c[x].size(); j++)
			{
				now = ch[now][c[x][j] - 'a'];
				v[now].push_back(q);
			}
		}
		else Q[x].push_back(q);
	}
	
	dfs(1);
	
	for(int i = 1; i <= n; i++)
	{
		if(c[i].size() > T)
		{
			memset(cnt, 0, sizeof(cnt));
			memset(sum, 0, sizeof(sum));
			int now = 1;
			for(int j = 0; j < c[i].size(); j++)
			{
				now = ch[now][c[i][j] - 'a'];
				cnt[dfn[now]]++;
			}
			for(int j = 1; j <= tot; j++) cnt[j] += cnt[j - 1];
			for(int j = 1; j <= n; j++)
			{
				sum[j] = cnt[dfn[w[j]] + siz[w[j]] - 1] - cnt[dfn[w[j]] - 1];
				sum[j] += sum[j - 1];
			}
			for(int j = 0; j < Q[i].size(); j++) ans[Q[i][j].id] = sum[Q[i][j].r] - sum[Q[i][j].l - 1];
		}
	}
	
	for(int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
}
#include <cstdio>
#include <cstring> 

int h[1010000], nxt[2010000], K = 1, to[2010000]; 
int fail[1010000], tag[1010000], tot = 0, wz[1010000];
long long c[1010000], b[1010000];
int ch[1010000][26], q[1010000], H = 0, T = 0;
int dfn[1010000], ss = -1, siz[1010000], rdfn[1010000];
bool ok[1010000];
char s[1010000];

void ins(int u,int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v; }
void add(int x,int k)
{
	for(int i = x; i <= tot; i += i & -i)
		c[i] += k;
}
long long query(int x)
{
	long long ans = 0;
	for(int i = x; i; i -= i & -i)
		ans += c[i];
	return ans;
}
void dfs(int x)
{
	dfn[x] = ++ss; rdfn[ss] = x; siz[x] = 1;
	if(ss) add(ss, tag[ rdfn[ss] ] - tag[ rdfn[ss - 1] ]);
	for(int i = h[x]; i; i = nxt[i])
	{
		tag[to[i]] += tag[x];
		dfs(to[i]); 
		siz[x] += siz[to[i]];
	}
}
void build(int tt)
{
	scanf("%s", s);int len = strlen(s);
	int x = 0;
	for(int i = 0; i < len; i++)
	{
		if(!ch[x][s[i] - 'a']) ch[x][s[i] - 'a'] = ++tot;
		x = ch[x][s[i] - 'a'];
	}
	tag[x]++; wz[tt] = x; ok[x] = 1;
	for(int i = 0; i < len; i++) s[i] = '\0';
}
void build_AC()
{
	H = 0; T = 0; q[T++] = 0;
	while(H < T)
	{
		int u = q[H++];
		for(int i = 0; i < 26; i++)
		{
			if(!ch[u][i]) continue;
			int now = fail[u];
			while(now && !ch[now][i]) now = fail[now];
			if(ch[now][i] != ch[u][i]) fail[ ch[u][i] ] = ch[now][i], ins(ch[now][i], ch[u][i]);
			else fail[ ch[u][i] ] = 0, ins(0, ch[u][i]);
			q[T++] = ch[u][i];
		}
	}
}
long long Q()
{
	scanf("%s", s);int len = strlen(s);
	if(s[0] == '+')
	{
		int sum = 0; 
		for(int i = 1; i < len; i++)
			sum = sum * 10 + s[i] - '0';
		sum = wz[sum];
		if(!ok[sum]) ok[sum] = 1, add(dfn[sum], 1), add(dfn[sum] + siz[sum], -1); 
		return -233;
	}
	if(s[0] == '-')
	{
		int sum = 0; 
		for(int i = 1; i < len; i++)
			sum = sum * 10 + s[i] - '0';
		sum = wz[sum];
		if(ok[sum]) ok[sum] = 0, add(dfn[sum], -1), add(dfn[sum] + siz[sum], 1); 
		return -233;
	}
	int x = 0; long long ans = 0;
	for(int i = 1; i < len; i++)
	{
		while(x && !ch[x][s[i]-'a']) x = fail[x];
		x = ch[x][s[i]-'a'];
		ans += query(dfn[x]);
	}
	for(int i = 0; i < len; i++) s[i] = '\0';
	return ans;
}
int main()
{
	int q, n;scanf("%d%d", &q, &n);
	for(int i = 1; i <= n; i++)
		build(i);
	build_AC();
	dfs(0);
	for(int i = 1; i <= q; i++)
	{
		long long ans = Q();
		if(ans >= 0)printf("%lld\n", ans);
	}
	return 0;
}
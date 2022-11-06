#include <bits/stdc++.h>
#define pcc pair<char, char>
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define mp make_pair
#define pb push_back
#define ls rt << 1
#define rs rt << 1 | 1
#define F fisrt
#define S second
#define X first
#define Y second
#define inf 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ll long long
//#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
using namespace std;
namespace IO
{
const int sz = 1 << 15;
char inbuf[sz], outbuf[sz];
char *pinbuf = inbuf + sz;
char *poutbuf = outbuf;
inline char _getchar()
{
	if (pinbuf == inbuf + sz)fread(inbuf, 1, sz, stdin), pinbuf = inbuf;
	return *(pinbuf++);
}
inline void _putchar(char x)
{
	if (poutbuf == outbuf + sz)fwrite(outbuf, 1, sz, stdout), poutbuf = outbuf;
	*(poutbuf++) = x;
}
inline void flush()
{
	if (poutbuf != outbuf)fwrite(outbuf, 1, poutbuf - outbuf, stdout), poutbuf = outbuf;
}
}
//#define getchar IO::_getchar
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2e5 + 10;
const int mod = 1e9 + 7; 
constexpr int INF = 0x3f3f3f3f;
#define V 1000111
#define E 1000111
namespace maxflow
{

struct edge
{
	int to;
	int cap;
	edge(){}
	edge(int k1, int k2)
	{
		to=k1;
		cap=k2;
	}
};

int head[V], nxt[E<<1], it[E<<1], etot = 1, MX = 0;
edge e[E<<1];

void clear()
{
	std::memset(head, 0, sizeof(head));
	etot = 1;
	MX = 0;
}

void addedge(int u, int v, int cap)
{
	if(u > MX) MX = u;
	if(v > MX) MX = v;
	nxt[++etot] = head[u];
	head[u] = etot;
	e[etot] = edge(v, cap);
	nxt[++etot] = head[v];
	head[v] = etot;
	e[etot] = edge(u, 0);
}

int lvl[V];
bool bfs(int s,int t)
{
	static int q[V];
	
	std::memset(lvl, -1, sizeof(int) * (MX+1));
	lvl[s] = 0;
	int rr = 0;
	q[rr++] = s;
	
	for(int fr=0; fr<rr; fr++)
	{
		int x = q[fr];
		if(x==t) return true;
		for(int i=head[x]; i; i=nxt[i]) if(e[i].cap && lvl[e[i].to] == -1)
		{
			lvl[e[i].to] = lvl[x]+1;
			q[rr++] = e[i].to;
		}
	}
	return false;
}
int dfs(int x, int t, int f)
{
	if(x==t || f==0) return f;
	int ret = 0;
	for(int &i = it[x]; i; i=nxt[i]) if(e[i].cap && lvl[e[i].to] == lvl[x]+1)
	{
		int d = dfs(e[i].to, t, std::min(f, e[i].cap));
		e[i].cap -= d;
		e[i^1].cap += d;
		f -= d;
		ret += d;
		if(!f) break;
	}
	return ret;
}
int work(int s, int t)
{
	if(s > MX) MX = s;
	if(t > MX) MX = t;
	int flow = 0;
	while(bfs(s,t))
	{
		std::memcpy(it, head, sizeof(int) * (MX+1));
		flow += dfs(s, t, INF);
	}
	return flow;
}

} // namespace MaxFlow
char ch[210][210];
int down[210][210], Rt[210][210];

int main()
{
	int n = read();
	int m = read();
	rep(i, 1, n)
		scanf("%s", ch[i] + 1);
	int cnt = 0, tot1 = 0, tot2 = 0, tot = 0;
	rep(i, 1, n)
		rep(j, 1, m)
		if(ch[i][j] == '#')
		{
			if (ch[i + 1][j] == '#') down[i][j] = ++tot1;
			if (ch[i][j + 1] == '#') Rt[i][j] = ++tot2;
			++ tot;
		}
	int S = tot1 + tot2 + 1, T = S + 1;
	rep(i, 1, n)
		rep(j, 1, m)
		{
			if(down[i][j]) maxflow::addedge(S, down[i][j], 1);
			if(Rt[i][j]) maxflow::addedge(Rt[i][j] + tot1, T, 1);
			if(down[i][j] && Rt[i][j - 1]) maxflow::addedge(down[i][j], Rt[i][j-1] + tot1, 1);
			if(down[i][j] && Rt[i][j]) maxflow::addedge(down[i][j], Rt[i][j] + tot1, 1);
			if(down[i][j] && Rt[i + 1][j - 1]) maxflow::addedge(down[i][j], Rt[i+1][j-1] + tot1, 1);
			if(down[i][j] && Rt[i + 1][j]) maxflow::addedge(down[i][j], Rt[i+1][j] + tot1, 1);
		}
	
	printf("%d\n", tot - (tot1 + tot2 - maxflow::work(S, T)));

	return 0;
}
#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X headst
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

const int N = 1000010, mod = 1000000007;
const int INF = 1e9;

struct Edge
{
	int next, to, v;
}e[N];
int n, m, V, E, k, cnt = 1, h[2010], cur[2010];
int S, T;
int dis[610][610], pos[210];
int head[2010], ed, st, sd;


void ins(int u, int v, int w)
{
	e[++ cnt].next = head[u];
	e[cnt].to = v;
	e[cnt].v = w;
	head[u] = cnt;
}

void insert(int u, int v, int w)
{
	ins(u, v, w);
	ins(v, u, 0);
}

bool bfs()
{
	memset(h, -1, sizeof(h));
	h[S] = 0;
	queue<int> Q;
	Q.push(S);
	while(!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		for(int u = head[now]; u; u = e[u].next)
			if(h[e[u].to] == -1 && e[u].v)
			{
				h[e[u].to] = h[now] + 1;
				Q.push(e[u].to);
			}
	}
	return h[T] != -1;
}

int dfs(int x, int f)
{
	if(x == T) return f;
	int used = 0;
	for(int u = head[x]; u; u = e[u].next)
		if(h[e[u].to] == h[x] + 1 && e[u].v)
		{
			int w = dfs(e[u].to, min(f - used, e[u].v));
			used += w;
			e[u].v -= w;
			e[u ^ 1].v += w;
			if(f == used) return f;
		}
	if(!used) h[x] = -1;
	return used;
}

int Dinic()
{
	int res = 0;
	while (bfs()) 
		res += dfs(S, INF);
	return res;
}

bool check(int mid)
{
	memset(head, 0, sizeof head);
	cnt = 1;

	S = 0;
	T = V + n + 1;
	rep(i, 1, n) insert(S, i, 1);
	rep(i, 1, V) insert(n + i, T, 1);
	rep(i, 1, n)
		rep(j, 1, V)
			if (dis[pos[i]][j] <= mid) insert(i, n + j, 1);

	return Dinic() >= k;
}

int main()
{
	V = read();
	E = read();
	n = read();
	k = read();
	rep(i, 1, n)
		pos[i] = read();
    memset(dis, 0x3f, sizeof dis);
	while(E --)
	{
		int u, v, w;
		u = read();
		v = read();
		w = read();
		dis[u][v] = dis[v][u] = min(dis[u][v], w);
	}
	rep(i, 1, V) dis[i][i] = 0;
	rep(t, 1, V)
		rep(i, 1, V)
			rep(j, i + 1, V)
				dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][t] + dis[t][j]);
	int ans = -1, l = 0, r = 1731311;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}
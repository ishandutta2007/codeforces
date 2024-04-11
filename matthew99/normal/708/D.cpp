#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const LL OO = 0x3f3f3f3f3f3f3f3fLL;
const int oo = 0x3f3f3f3f;

const int max0 = 10000, max1 = 100000;

struct edge
{
    int id, g, w, nxt;
 
    edge() { }
    edge(const int &_id, const int &_g, const int &_w, const int &_nxt): id(_id), g(_g), w(_w), nxt(_nxt) { }
 
};
 
int st[max0 + 5], en = 0;
edge e[max1 + 5];
 
int N;
 
inline void add_edge(const int &x, const int &y, const int &z, const int &w)
{
    e[en] = edge(y, z, w, st[x]), st[x] = en++; 
}
 
inline void add_biedge(int x, int y, int z, const int &w)
{
    if (!z) return;
    if (z < 0) swap(x, y), z = -z;
    add_edge(x, y, z, w);
    add_edge(y, x, 0, -w);
}
 
int S, T;
 
LL ans = 0;
 
int SPFA()
{
    static LL dis[max0 + 5];
    static int q[max0 + 5];
    static bool vis[max0 + 5] = {0};
    static int pre[max0 + 5], Min[max0 + 5];
    int head = 0, rear = 0;
    memset(vis, 0, sizeof(vis[0]) * N);
    memset(dis, oo, sizeof(dis[0]) * N);
    q[rear++] = S;
    dis[S] = 0;
    Min[S] = oo;
    while (head != rear)
    {
        const int &x = q[head++];
        vis[x] = 0;
        if (head >= max0 + 1) head -= max0 + 1;
        for (int i = st[x]; i != -1; i = e[i].nxt)
        {
            if (!e[i].g) continue;
            const int &y = e[i].id;
            if (chkmin(dis[y], dis[x] + e[i].w))
            {
				Min[y] = min(Min[x], e[i].g);
				pre[y] = i;
				if (!vis[y])
				{
					vis[y] = 1;
					q[rear++] = y;
					if (rear >= max0 + 1) rear -= max0 + 1;
				}
			}
		}
	}
	if (dis[T] >= 0) return 0;
	int u = T;
	while (u != S)
	{
		e[pre[u]].g -= Min[T];
		e[pre[u] ^ 1].g += Min[T];
		u = e[pre[u] ^ 1].id;
	}
	ans += dis[T] * Min[T];
	return Min[T];
}

const int maxn = 100, maxm = 100;

int n, m;

int deg[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	scanf("%d%d", &n, &m);
	S = n, T = n + 1;
	N = n + 2;
	ans = 0;
	REP(i, 0, m)
	{
		int u, v, c, f;
		scanf("%d%d%d%d", &u, &v, &c, &f), --u, --v;
		deg[u] -= f, deg[v] += f;
		if (f > c)
		{
			ans += abs(c - f);
			add_biedge(u, v, oo, 2);
			add_biedge(v, u, f - c, 0);
			add_biedge(v, u, c, 1);
		}
		else
		{
			add_biedge(u, v, c - f, 1);
			add_biedge(u, v, oo, 2);
			add_biedge(v, u, f, 1);
		}
	}
	REP(i, 1, n - 1) 
	{ 
		ans += (LL)oo * abs(deg[i]); 
		if (deg[i] > 0) add_biedge(S, i, deg[i], -oo);
		else add_biedge(i, T, -deg[i], -oo);
	}
	add_biedge(S, 0, oo, 0);
	add_biedge(S, n - 1, oo, 0);
	add_biedge(0, T, oo, 0);
	add_biedge(n - 1, T, oo, 0);
	while (SPFA());
	cout << ans << endl;
	return 0;
}
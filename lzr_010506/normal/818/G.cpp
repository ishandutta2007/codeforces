#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
const int M = 1000000;
const int INF = 1e9;

int n, S, T, a[N], last[M], lm[N];
int head[N], nxt[M], to[M], flow[M], cost[M];

namespace MCMF
{
    int dis[N], sur[N], inq[N];
    queue<int> Q;

    bool SPFA()
    {
        memset(dis,60,sizeof(dis));
        Q.push(S);
		dis[S] = 0;

        while (!Q.empty())
        {
            int w = Q.front(); Q.pop();
            inq[w] = 0;
            for (int i = head[w]; i; i = nxt[i])
            {
                if (dis[to[i]] > dis[w] + cost[i] && flow[i])
                {
                    dis[to[i]] = dis[w] + cost[i];
                    sur[to[i]] = i;
                    if (!inq[to[i]]) inq[to[i]] = 1, Q.push(to[i]);
                }
            }
        }
        return dis[T] < INF;
    }

    inline int MaxFlow()
    {
        int ret_cost = 0;
        for (int f = INF,w, ttt = 1;ttt <= 4 && SPFA();++ ttt, f = INF)
        {
            for (w = T; w != S; w = to[sur[w] ^ 1]) f = min(f, flow[sur[w]]);
            for (w = T; w != S; w = to[sur[w] ^ 1]) flow[sur[w]] -= f, flow[sur[w] ^ 1] += f;
            ret_cost += dis[T] * f;
        }
        return -ret_cost;
    }
};

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline void insert(int u, int v, int f, int c)
{
	static int E = 1;
	to[++ E] = v; nxt[E] = head[u]; head[u] = E; flow[E] = f; cost[E] = c;
	to[++ E] = u; nxt[E] = head[v]; head[v] = E; flow[E] = 0; cost[E] = -c;
}

inline int id(int x, int t)
{
	return (x - 1) * 3 + t;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();

	S = 0; T = N - 1;
	for (int i = n; i; i --)
	{
		if (last[a[i]]) insert(id(i, 1), id(last[a[i]], 1), INF, 0);
		if (last[a[i] - 1]) insert(id(i, 2), id(last[a[i] - 1], 1), INF, 0);
		if (last[a[i] + 1]) insert(id(i, 2), id(last[a[i] + 1], 1), INF, 0);
		if (lm[a[i] % 7])
		{
			insert(id(i, 2), id(lm[a[i] % 7], 3), INF, 0);
			insert(id(i, 3), id(lm[a[i] % 7], 3), INF, 0);
		}
		insert(id(i, 1), id(i, 2), 1, -1);
		insert(id(i, 3), id(i, 1), INF, 0);
		insert(S, id(i, 1), INF, 0);
		insert(id(i, 2), T, INF, 0);
		last[a[i]] = i;
		lm[a[i] % 7] = i;
	}
	printf("%d\n", MCMF::MaxFlow());
	return 0;
}
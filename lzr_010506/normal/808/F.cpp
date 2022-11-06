#include <bits/stdc++.h>
#define N 110
#define inf 1 << 30
using namespace std;

int n, k, g, S, T;
int p[N], c[N], a[N], l[N];
int is[200010];
queue<int> Q;
int head[10010], nxt[10010], tot = 1;
struct edge
{
    int t, d;
}e[10010];

void build(int f, int t, int d)
{
    e[++ tot].d = d;
    e[tot].t = t;
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f, int t, int d)
{
    build(f, t, d);
    build(t, f, 0);
}

int Dep[10010];
queue<int> q;

bool bfs()
{
    while(q.size()) q.pop();
    memset(Dep, 0, sizeof(Dep));
    Dep[S] = 1;
    q.push(S);
    while(q.size())
    {
        int f = q.front();
        q.pop();
        for(int i = head[f]; i; i = nxt[i])
        {
            int v = e[i].t;
            if(!Dep[v] && e[i].d)
            {
                Dep[v] = Dep[f] + 1;
                q.push(v);
                if(v == T) return true;
            }
        }
    }
    return 0;
}

int dfs(int u, int flow)
{
    if(u == T || flow == 0) return flow;
    int rest = flow;
    for(int i = head[u]; i; i = nxt[i])
    {
        int v = e[i].t;
        if(Dep[v] == Dep[u] + 1 && e[i].d)
        {
            int f = dfs(v, min(rest, e[i].d));
            if(f > 0)
            {
                e[i].d -= f;
                e[i ^ 1].d += f;
                rest -= f;
                if(rest == 0) break;
            }
            else Dep[v] = 0;
        }
    }
    if(flow - rest == 0) Dep[u] = 0;
    return flow - rest;
}


int dinic()
{
    int ans = 0;
    while(bfs())
    {
        int tmp = dfs(S, inf);
        if(!tmp) break;
        ans += tmp;
    }
    return ans;
}


int main()
{
	for(int i = 2; i <= 200000; i ++)
		if(!is[i])
			for(int j = i + i; j <= 200000; j += i)
				is[j] = 1;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i ++)
		scanf("%d%d%d", &p[i], &c[i], &l[i]);
	int L = 1, R = 100, mid, ans = -1;
	while(L <= R)
	{
	    memset(head, 0, sizeof(head));
	    memset(nxt, 0, sizeof(nxt));
		mid = L + R >> 1;
		int g = 1;
		int mx = -1, mxn;
		for(int i = 1; i <= n; i ++)
			if(l[i] <= mid && c[i] == 1 && p[i] > mx) mx = p[i], mxn = i;
		for(int i = 1; i <= n; i ++)
			if(l[i] <= mid && (c[i] > 1 || i == mxn)) a[++ g] = i;
		S = 0;
		T = g + 1;
		for(int i = 1; i <= g; i ++)
			if(c[a[i]]  &1) insert(S, i, p[a[i]]);
			else insert(i, T, p[a[i]]);
		for(int i = 1; i <= g; i ++)
			if(c[a[i]] & 1)
				for(int j = 1; j <= g; j ++)
					if((~c[a[j]] & 1) && !is[c[a[i]] + c[a[j]]])
						insert(i, j, inf);
		int v = 0;
		for(int i = 1; i <= g; i ++) v += p[a[i]];
		v -= dinic();
		if(v >= k) R = (ans = mid) - 1;
		else L = mid + 1;
	}
	printf("%d\n",ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int siz = 2000005;
int n, m, tim, fa[siz], sz[siz], bk[siz], tot, ans[siz];
struct edge
{
	int x, y, s, t;
}e[siz];

map<pair<int, int>, int> pp;

inline bool cmp1(const edge &a, const edge &b)
{
    return a.s == b.s ? a.t < b.t : a.s < b.s;
}

inline bool cmp2(const edge &a, const edge &b)
{
    return a.t == b.t ? a.s < b.s : a.t < b.t;
}

inline int find(int u)
{
    while (fa[u] != u)u = fa[u]; return u;
}

inline void add(int a, int b)
{
    int A = find(a), B = find(b);
    if (sz[A] > sz[B]) fa[B] = A, sz[A] += sz[B], bk[++ tot] = B;
    else fa[A] = B, sz[B] += sz[A], bk[++ tot] = A;
}

inline bool adde(int a, int b)
{
    a --;
    b --;
    add(a << 1, b << 1 | 1);
    add(a << 1 | 1, b << 1);
    return find(a << 1) == find(a << 1 | 1);
}

inline void rec(int a)
{
    sz[fa[a]] -= sz[a];
	fa[a] = a;
}

void solve(int L, int R, int l, int r)
{
    for (int i = l; i <= r; i ++)
    	if (e[i].s <= L && e[i].t >= R)
    		if (adde(e[i].x, e[i].y))
    		{
        		for (int j = L; j <= R; j ++)
        			ans[j] = 1;
        		return;
        	}
        	else swap(e[i --], e[r --]);

    if (L == R) return;
    int top = tot, mid = (L + R) >> 1;
    {
    	sort(e + l, e + r + 1, cmp1);
    	int t = l;
    	while (t <= r && e[t].s <= mid) t ++;
    	solve(L, mid, l, t - 1);
    	while (tot > top) rec(bk[tot --]);
    }
    {
    	sort(e + l, e + r + 1, cmp2);
    	int t = r;
    	while (t >= l && e[t].t >= mid + 1) t --;
    	solve(mid + 1, R, t + 1, r);
    	while (tot > top) rec(bk[tot --]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2 * n; i ++)fa[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i ++)
    {
    	int x, y;
    	scanf("%d%d", &x, &y);
    	if(pp[make_pair(x, y)] == 0)
    	{
    		pp[make_pair(x, y)] = i;
    		e[i].x = x;
    		e[i].y = y;
    		e[i].s = i;
    		e[i].t = m + 1;
    	}
    	else
    	{
    		int pos = pp[make_pair(x, y)];
    		e[pos].t = i - 1;
    		pp[make_pair(x, y)] = 0;
    		e[i].x = x;
    		e[i].y = y;
    		e[i].s = 0;
    		e[i].t = 0;
    	}
    }
    solve(1, m, 1, m);
    for (int i = 1; i <= m; i ++)
    	puts(ans[i] ? "NO" : "YES");
    return 0;
}
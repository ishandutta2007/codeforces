#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll unsigned long long
#define X first
#define Y second
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
int h;
const int N = 200010;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
#define N 300000 + 10
#define M 1048576 + 10

int n, m, q, Dep, cnt, Last[N], T[N], Low[N], L[N], R[N], Ord[N], Dfn[N], Stack[N], Del[M];
ll Tree[M], Ans[N];
bool Flag[N];
vector <int> G[N];

void dfs(int z, int last)
{
	Dfn[z] = Low[z] = ++ Dep;
	Stack[++ Stack[0]] = z;
	Flag[z] = 1;
	for (int i = 0; i < G[z].size(); i ++)
	{
		int d = G[z][i];
		if (d == last) continue ;
		if (!Dfn[d])
			dfs(d, z), Low[z] = min(Low[z], Low[d]);
		else if (Flag[d])
			Low[z] = min(Low[z], Dfn[d]);
	}
	if (Dfn[z] == Low[z])
	{
		T[0] = 0;
		int j, Min = n, Max = 0;
		do
		{
			j = Stack[Stack[0] --];
			Min = min(Min, j);
			Max = max(Max, j);
			T[++ T[0]] = j;
		} while (j != z);
		if (Min != Max)
			Last[Max] = Min;
	}
}

bool cmp(int u, int v)
{
	return R[u] < R[v];
}

void apply(int rt, int l, int r, int k)
{
	Tree[rt] += 1LL * k * (r - l + 1);
	Del[rt] += k;
}

void push(int rt, int l, int r)
{
	if (Del[rt])
	{
		int mid = l + r >> 1;
		apply(ls, l, mid, Del[rt]);
		apply(rs, mid + 1, r, Del[rt]);
		Del[rt] = 0;
	}
}

void update(int rt)
{
	Tree[rt] = Tree[ls] + Tree[rs];
}

void Modify(int rt, int l, int r, int s, int t)
{
	if (l == s && r == t)
	{
		apply(rt, l, r, 1);
		return ;
	}
	push(rt, l, r);
	int mid = l + r >> 1;
	if (t <= mid) Modify(ls, l, mid, s, t);
	else if (s > mid) Modify(rs, mid + 1, r, s, t);
	else Modify(ls, l, mid, s, mid), Modify(rs, mid + 1, r, mid + 1, t);
	update(rt);
}

ll Query(int rt, int l, int r, int s, int t)
{
	if (l == s && r == t) return Tree[rt];
	push(rt, l, r);
	int mid = l + r >> 1;
	if (t <= mid) return Query(ls, l, mid, s, t);
	else if (s > mid) return Query(rs, mid + 1, r, s, t);
	else return Query(ls, l, mid, s, mid) + Query(rs, mid + 1, r, mid + 1, t);
}

int main()
{
	n = read();
	m = read();
	rep(i, 1, m)
	{
		int u = read();
		int v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep(i, 1, n)
		if (!Dfn[i])
			dfs(i, 0);
	rep(i, 1, n)
		Last[i] = max(Last[i], Last[i - 1]);
	scanf("%d", &q);
	for (int i = 1, l, r; i <= q; i ++)
	{
		scanf("%d%d", &l, &r);
		L[i] = l, R[i] = r;
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + q + 1, cmp);
	for (int i = 1, t = 1; i <= n; i ++)
	{
		Modify(1, 1, n, Last[i] + 1, i);
		for (; t <= q && R[Ord[t]] == i; t ++)
			Ans[Ord[t]] = Query(1, 1, n, L[Ord[t]], R[Ord[t]]);
	}
	for (int i = 1; i <= q; i ++)
		printf("%lld\n", Ans[i]);
	return 0;
}
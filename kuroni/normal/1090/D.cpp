#include <cstdio>
#include <set>
const int N = 1e5+1;
int a[N], b[N];
struct TEdge 
{ 
	int u, v; 
	TEdge(int _u, int _v) : u(_u), v(_v) {}
};
inline long long sqr(int x) 
{ 
	return 1LL * x * x;
}
inline bool operator < (TEdge lhs, TEdge rhs)
{
	if (lhs.u + lhs.v != rhs.u + rhs.v)
		return lhs.u + lhs.v < rhs.u + rhs.v;
	return sqr(lhs.u - lhs.v) < sqr(rhs.u - rhs.v);
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	std::set<TEdge> edge_set;
	TEdge tmp(1, 2);
	for (int i = 1; i <= m; ++i)
	{
		int a, b; scanf("%d%d", &a, &b);
		edge_set.insert(TEdge(a, b));
		while (edge_set.count(tmp))
			if (++tmp.v > n)
				tmp.v = ++tmp.u + 1;
	}
	if (tmp.v > n || tmp.u > n)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for (int i = 1, cnt = 0; i <= n; ++i)
		if (i != tmp.u && i != tmp.v)
			a[i] = ++cnt;
	a[tmp.u] = n - 1;
	a[tmp.v] = n;
	for (int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 1, cnt = 0; i <= n; ++i)
		if (i != tmp.u && i != tmp.v)
			b[i] = ++cnt;
	b[tmp.u] = n;
	b[tmp.v] = n;
	for (int i = 1; i <= n; ++i)
		printf("%d ", b[i]);
	return 0;
}
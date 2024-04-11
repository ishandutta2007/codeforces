#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, ii> iiii;

const int Maxn = 200005;
const int Inf = 2000000007;

int n;
iiii my[Maxn];
iiii L[Maxn], R[Maxn];

iiii Union(const iiii &a, const iiii &b)
{
	iiii c;
	c.first.first = max(a.first.first, b.first.first);
	c.first.second = max(a.first.second, b.first.second);
	c.second.first = min(a.second.first, b.second.first);
	c.second.second = min(a.second.second, b.second.second);
	return c;
}

bool Ok(const iiii &c)
{
	return c.first.first <= c.second.first && c.first.second <= c.second.second;
}

void Print(const iiii &c)
{
	printf("%d %d\n", c.first.first, c.first.second);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &my[i].first.first, &my[i].first.second, &my[i].second.first, &my[i].second.second);
		if (i == 0) L[i] = my[i];
		else L[i] = Union(L[i - 1], my[i]);
	}
	R[n - 1] = my[n - 1];
	for (int i = n - 2; i >= 0; i--)
		R[i] = Union(R[i + 1], my[i]);
	if (Ok(R[1])) Print(R[1]);
	else if (Ok(L[n - 2])) Print(L[n - 2]);
	else for (int i = 1; i + 1 < n; i++) {
		iiii g = Union(L[i - 1], R[i + 1]);
		if (Ok(g)) { Print(g); break; }
	}
	return 0;
}
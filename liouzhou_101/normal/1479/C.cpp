#include <bits/stdc++.h>
 
using namespace std;
 
vector<tuple<int, int, int>> edges;
 
void addedge(int x, int y, int z)
{
	edges.push_back({ x, y, z });
}
 
int solve(int L, int R)
{
	if (L > 1)
	{
		int k = solve(1, R - L + 1);
		addedge(k, k + 1, L - 1);
		return k + 1;
	}
	if ((R & -R) == R) // if L == 1 and R is a power of 2
	{
		int k = __builtin_ctz(R);
		addedge(1, 2, 1);
		for (int i = 3; i <= k + 2; ++i)
		{
			addedge(1, i, 1);
			for (int j = 2; j < i; ++j)
				addedge(j, i, 1 << (j - 2));
		}
		return k + 2;
	}
	int k = 0;
	while (1 << (k + 1) <= R - 1) ++k;
	solve(1, 1 << k);
	addedge(1, k + 3, 1);
	for (int i = 0; i <= k; ++i)
		if ((R - 1) >> i & 1)
			addedge(i + 2, k + 3, 1 + ((R - 1) >> (i + 1) << (i + 1)));
	return k + 3;
}
 
int main()
{
	int L, R;
	scanf("%d%d", &L, &R);
	puts("YES");
	int n = solve(L, R);
	printf("%d %d\n", n, (int)edges.size());
	for (auto [x, y, z] : edges) printf("%d %d %d\n", x, y, z);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n;
vector <int> neigh[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += neigh[i].size() == 1;
	printf("%d\n", res);
	return 0;
}
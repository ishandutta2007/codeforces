#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	int mx = 100005;
	for (int i = 0; i < m; i++) {
		int l, r; scanf("%d %d", &l, &r);
		mx = min(mx, r - l + 1);
	}
	printf("%d\n", mx);
	for (int i = 0; i < n; i++)
		printf("%d%c", i % mx, i + 1 < n? ' ': '\n');
	return 0;
}
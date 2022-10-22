#include <bits/stdc++.h>
using namespace std;

const int Maxn = 32;

int m, n;
int my[Maxn];

int Get(int y)
{
	printf("%d\n", y);
	fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		my[i] = Get(1);
		if (my[i] == 0) return 0;
	}
	int lef = 1, rig = m;
	int pnt = 0;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		int res = Get(mid) * my[pnt];
		pnt = (pnt + 1) % n;
		if (res == 0) return 0;
		else if (res > 0) lef = mid + 1;
		else rig = mid - 1;
	}
	return 0;
}
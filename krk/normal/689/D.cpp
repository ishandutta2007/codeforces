#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxk = 18;
const int Inf = 2000000000;

int n;
int mx[Maxn][Maxk], mn[Maxn][Maxk];
ll res;

int Status(int l, int r)
{
	int curmx = -Inf, curmn = Inf;
	for (int i = Maxk - 1; i >= 0; i--) if (l + (1 << i) <= r + 1) {
		curmx = max(curmx, mx[l][i]);
		curmn = min(curmn, mn[l][i]);
		l += 1 << i;
		if (curmx > curmn) return 1;
	}
	return curmx < curmn? -1: 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &mx[i][0]);
	for (int i = 0; i < n; i++)
		scanf("%d", &mn[i][0]);
	for (int j = 1; j < Maxk; j++)
		for (int i = 0; i + (1 << j) <= n; i++) {
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
		}
	for (int i = 0; i < n; i++) {
		int lef = i, rig = n - 1;
		int lower = i - 1;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (Status(i, mid) == -1) { lower = mid; lef = mid + 1; }
			else rig = mid - 1;
		}
		lef = i, rig = n - 1;
		int upper = n;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (Status(i, mid) == 1) { upper = mid; rig = mid - 1; }
			else lef = mid + 1;
		}
		res += upper - lower - 1;
	}
	printf("%I64d\n", res);
	return 0;
}
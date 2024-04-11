#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 400005;

int T;
int n;
bool was[Maxm];
int b[Maxn];
int a[Maxn];

bool checkMin(int x)
{
	for (int i = 0; i < x; i++)
		if (b[i] > a[n - x + i]) return false;
	return true;
}

bool checkMax(int x)
{
	for (int i = 0; i < x; i++)
		if (b[n - x + i] < a[i]) return false;
	return true;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		fill(was, was + 2 * n + 1, false);
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
			was[b[i]] = true;
		}
		sort(b, b + n);
		int pnt = 0;
		for (int i = 1; i <= 2 * n; i++)
			if (!was[i]) a[pnt++] = i;
		int lef = 0, rig = n;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (checkMin(mid)) lef = mid + 1;
			else rig = mid - 1;
		}
		int R = rig;
		lef = 0, rig = n;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (checkMax(mid)) lef = mid + 1;
			else rig = mid - 1;
		}
		int L = n - rig;
		printf("%d\n", max(0, R - L + 1));
	}
    return 0;
}
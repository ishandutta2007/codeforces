#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200015;

int n, L;
int a[Maxn], b[Maxn];
int delt[Maxn];

void Insert(int l, int r)
{
	if (r - l + 1 < 0) return;
	if (r - l + 1 >= n) {
		delt[0]++; delt[n]--;
		return;
	}
	while (l < 0) { l += n; r += n; }
	if (r < n) { delt[l]++; delt[r + 1]--; return; }
	delt[l]++; delt[n]--;
	delt[0]++; delt[r - n + 1]--;
}

int getLeft(int val)
{
	int pval = L + val;
	int ind = lower_bound(a, a + n, pval) - a;
	if (ind < n) return ind - n;
	ind = lower_bound(a, a + n, val) - a;
	if (ind < n) return ind;
	int nval = val - L;
	ind = lower_bound(a, a + n, nval) - a;
	return n + ind; 
}

int getRight(int val)
{
	int nval = val - L;
	int ind = upper_bound(a, a + n, nval) - a - 1;
	if (ind >= 0) return n + ind;
	ind = upper_bound(a, a + n, val) - a - 1;
	if (ind >= 0) return ind;
	int pval = L + val;
	ind = upper_bound(a, a + n, pval) - a - 1;
	return ind - n;
}

bool Solve(int x)
{
	fill(delt, delt + Maxn, 0);
	for (int i = 0; i < n; i++) {
		int lef = b[i] - x, rig = b[i] + x;
		Insert(getLeft(lef) - i, getRight(rig) - i);
	}
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur += delt[i];
		if (cur >= n) return true;
	}
	return false;
}

int main()
{
	scanf("%d %d", &n, &L);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	sort(a, a + n); sort(b, b + n);
	int lef = 0, rig = L - 1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Solve(mid)) rig = mid - 1;
		else lef = mid + 1;
	}
	cout << rig + 1 << endl;
	return 0;
}
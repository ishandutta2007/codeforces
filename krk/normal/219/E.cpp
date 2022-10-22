#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Maxi = 1000005;

int n, m;
int pl[Maxi];
int lef[Maxm], rig[Maxm], fre[Maxm];

void Create(int v, int l, int r)
{
	fre[v] = r - l + 1;
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
	}
}

void Union(int v, int l, int r, int m)
{
	if (fre[2 * v] == m - l + 1 && fre[2 * v + 1] == r - m) fre[v] = r - l + 1;
	else if (fre[2 * v] == m - l + 1) {
			lef[v] = lef[2 * v + 1]; rig[v] = rig[2 * v + 1];
			fre[v] = lef[2 * v + 1] - l;
		} else if (fre[2 * v + 1] == r - m) {
			lef[v] = lef[2 * v]; rig[v] = rig[2 * v];
			fre[v] = r - rig[2 * v];
		} else {
			lef[v] = lef[2 * v]; rig[v] = rig[2 * v + 1];
			fre[v] = max(lef[2 * v + 1] - rig[2 * v] - 1, max(fre[2 * v], fre[2 * v + 1]));
		}
}

int bestPlace(int v, int l, int r)
{
	if (l == r) return l;
	else {
		int m = l + r >> 1;
		if ((fre[2 * v] + 1) / 2 >= (fre[v] + 1) / 2)
			return bestPlace(2 * v, l, m);
		int nl = fre[2 * v] == m - l + 1? l - 1: rig[2 * v], nr = fre[2 * v + 1] == r - m? r + 1: lef[2 * v + 1];
		if ((nr - nl) / 2 >= (fre[2 * v + 1] + 1) / 2)
			return (nl + nr) / 2;
		return bestPlace(2 * v + 1, m + 1, r);
	}
}

int bestPlace()
{
	if (fre[1] == n) return 1;
	if (lef[1] - 1 >= (fre[1] + 1) / 2 && lef[1] - 1 >= n - rig[1]) return 1;
	if (n - rig[1] > (fre[1] + 1) / 2) return n;
	return bestPlace(1, 1, n);
}

void Insert(int v, int l, int r, int x)
{
	if (l == x && r == x) { lef[v] = l; rig[v] = r; fre[v] = 0; }
	else {
		int m = l + r >> 1;
		if (x <= m) Insert(2 * v, l, m, x);
		else Insert(2 * v + 1, m + 1, r, x);
		Union(v, l, r, m);
	}
}

void Remove(int v, int l, int r, int x)
{
	if (l == x && r == x) fre[v] = 1;
	else {
		int m = l + r >> 1;
		if (x <= m) Remove(2 * v, l, m, x);
		else Remove(2 * v + 1, m + 1, r, x);
		Union(v, l, r, m);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	Create(1, 1, n);
	while (m--) {
		int t, id; scanf("%d %d", &t, &id);
		if (t == 1) {
			pl[id] = bestPlace();
			printf("%d\n", pl[id]);
			Insert(1, 1, n, pl[id]);
		} else Remove(1, 1, n, pl[id]);
	}
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m, a;
int b[Maxn];
int p[Maxn];
int r, s;

bool Less(const int &a, const int &b) { return a > b; }

bool Enough(int tk, int &mn)
{
	ll payed = 0ll, need = 0ll;
	for (int i = 0; i < tk; i++)
		if (b[tk - 1 - i] < p[i]) { payed += b[tk - 1 - i]; need += p[i] - b[tk - 1 - i]; }
		else payed += p[i];
	if (need > a) return false;
	mn = max(0ll, payed - (a - need));
	return true;
}

int main()
{
	scanf("%d %d %d", &n, &m, &a);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &p[i]);
	sort(b, b + n, Less); sort(p, p + m);
	int lef = 1, rig = min(n, m);
	while (lef <= rig) {
		int mid = lef + rig >> 1, got;
		if (Enough(mid, got)) { r = mid; s = got; lef = mid + 1; }
		else rig = mid - 1;
	}
	printf("%d %d\n", r, s);
	return 0;
}
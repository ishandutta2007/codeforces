#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 4005;

int x, k;
ii p[Maxn];
int mn, mx;

int main()
{
	scanf("%d %d", &x, &k);
	p[0] = ii(0, 0);
	for (int i = 1; i <= k; i++) {
		int a, b, c; scanf("%d %d", &a, &b);
		if (a == 1) { scanf("%d", &c); p[i] = ii(b, c); }
		else p[i] = ii(b, b);
	}
	p[k + 1] = ii(x, x);
	sort(p + 1, p + k + 1);
	for (int i = 1; i <= k + 1; i++) {
		mn += (p[i].first - p[i - 1].second) / 2;
		mx += p[i].first - p[i - 1].second - 1;
	}
	printf("%d %d\n", mn, mx);
	return 0;
}
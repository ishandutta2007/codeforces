#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n, m, dx, dy;
int inrow[Maxn];
int has[Maxn];

int main()
{
	scanf("%d %d %d %d", &n, &m, &dx, &dy);
	if (n == 1) { printf("0 0\n"); return 0; }
	int r = 0, c = 0;
	for (int i = 1; i < n; i++) {
		r = (r + dx) % n; c = (c + dy) % n;
		inrow[r] = c;
	}
	while (m--) {
		int x, y; scanf("%d %d", &x, &y);
		int w = (y - inrow[x] + n) % n;
		has[w]++;
	}
	int best = 0;
	for (int i = 0; i < n; i++)
		if (has[i] > has[best]) best = i;
	printf("0 %d\n", best);
	return 0;
}
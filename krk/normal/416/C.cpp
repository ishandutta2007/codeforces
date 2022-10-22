#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

struct cpi {
	int c, p, i;
	cpi(int c = 0, int p = 0, int i = 0): c(c), p(p), i(i) {}
	bool operator <(const cpi &oth) const {
		return c < oth.c;
	}
};

int n;
cpi I[Maxn];
int k;
int r[Maxn], mx[Maxn], ind[Maxn];
int res, money;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &I[i].c, &I[i].p); I[i].i = i;
	}
	sort(I, I + n);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &r[i]); mx[i] = ind[i] = -1;
	}
	for (int i = n - 1; i >= 0; i--) {
		int best = -1;
		for (int j = 0; j < k; j++)
			if (I[i].c <= r[j] && (best == -1 || mx[j] < mx[best]))
				best = j;
		if (best != -1 && mx[best] < I[i].p)  {
			if (mx[best] == -1) { res++; money += I[i].p; }
			else money += I[i].p - mx[best];
			mx[best] = I[i].p; ind[best] = I[i].i;
		}
	}
	printf("%d %d\n", res, money);
	for (int i = 0; i < k; i++) if (ind[i] != -1)
		printf("%d %d\n", ind[i] + 1, i + 1);
	return 0;
}
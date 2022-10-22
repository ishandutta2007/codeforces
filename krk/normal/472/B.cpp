#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 2005;

int n, k;
int freq[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int f; scanf("%d", &f);
		freq[f - 1]++;
	}
	int pnt = Maxn - 1;
	while (pnt >= 0) {
		while (pnt >= 0 && freq[pnt] == 0) pnt--;
		if (pnt < 0) break;
		res += 2 * pnt;
		int ct = k;
		while (pnt >= 0 && ct > 0) {
			int tk = min(ct, freq[pnt]);
			ct -= tk; freq[pnt] -= tk;
			if (freq[pnt] == 0) pnt--;
		}
	}
	printf("%d\n", res);
	return 0;
}
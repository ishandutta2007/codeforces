#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxl = 100005;
const int Maxd = 205;
const int Inf = 1000000000;

int n;
int l[Maxl];
int has[Maxd][Maxl], tot[Maxd];
int res = Inf;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &l[i]);
	for (int i = 0; i < n; i++) {
		int d; scanf("%d", &d);
		has[d][l[i]]++; tot[d]++;
	}
	int cur = 0;
	for (int i = Maxl - 1; i >= 0; i--) {
		int add = 0, cnt = 0;
		for (int j = 0; j < Maxd; j++) {
			cnt += has[j][i]; tot[j] -= has[j][i];
			add += j * has[j][i];
		}
		if (cnt) {
			int cand = 0;
			int rem = max(n - 2 * cnt + 1, 0);
			for (int j = 0; j < Maxd; j++) {
				int tk = min(rem, tot[j]); rem -= tk;
				cand += tk * j;
			}
			res = min(res, cur + cand);
		}
		cur += add; n -= cnt;
	}
	printf("%d\n", res);
	return 0;
}
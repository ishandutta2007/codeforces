#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 10000007;

int mn[Maxn];
int n;
int cnt[Maxn];
int m;

int main()
{
	for (int i = 2; i < Maxn; i++) if (mn[i] == 0)
		for (int j = i; j < Maxn; j += i) mn[j] = i;
	scanf("%d", &n);
	while (n--) {
		int x; scanf("%d", &x);
		int lst = -1;
		while (x != 1) {
			int p = mn[x]; x /= p;
			if (lst != p) { cnt[p]++; lst = p; }
		}
	}
	for (int i = 2; i < Maxn; i++)
		cnt[i] += cnt[i - 1];
	scanf("%d", &m);
	while (m--) {
		int l, r; scanf("%d %d", &l, &r);
		int U = min(Maxn - 1, r), L = min(Maxn - 1, l - 1);
		printf("%d\n", cnt[U] - cnt[L]);
	}
	return 0;
}
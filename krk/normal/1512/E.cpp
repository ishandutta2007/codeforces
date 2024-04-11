#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int T;
int n, l, r, s;
bool tk[Maxn];
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &n, &l, &r, &s);
		fill(tk, tk + n + 1, false);
		int L = l, sz = r - l + 1;
		int mx = n;
		if ((1 + sz) * sz / 2 <= s && s <= (2 * mx - sz + 1) * sz / 2) {
			while (sz > 0) {
				while (mx > sz && (2 * (mx - 1) - sz + 1) * sz / 2 >= s)
					mx--;
				a[L++] = mx; sz--;
				s -= mx;
				tk[mx] = true; mx--;
			}
			int pnt = 1;
			for (int i = 1; i < l; i++) {
				while (tk[pnt]) pnt++;
				a[i] = pnt++;
			}
			for (int i = r + 1; i <= n; i++) {
				while (tk[pnt]) pnt++;
				a[i] = pnt++;
			}
			for (int i = 1; i <= n; i++)
				printf("%d%c", a[i], i + 1 <= n? ' ': '\n');
		} else printf("-1\n");
	}
    return 0;
}
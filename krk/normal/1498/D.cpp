#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxm = 100005;
const int lim = 100000;

int n, m;
int res[Maxm];
bool tk[Maxm];

int main()
{
	scanf("%d %d", &n, &m);
	fill(res, res + m + 1, Maxm);
	res[0] = 0;
	for (int T = 1; T <= n; T++) {
		fill(tk, tk + m + 1, false);
		int t;
		ll x, y; scanf("%d %I64d %I64d", &t, &x, &y);
		if (t == 1) {
			ll add = (x + lim - 1) / lim;
			for (int i = 0; i <= m; i++) if (!tk[i]) {
				int lst = -Maxm;
				for (ll ind = 0, j = i; j <= m && !tk[j]; ind++, j += add) {
					tk[j] = true;
					if (ind - lst <= y && res[j] >= Maxm)
						res[j] = T;
					if (res[j] < T) lst = ind;
				}
			}
		} else {
			for (int i = 0; i <= m; i++) if (!tk[i]) {
				int lst = -Maxm;
				for (ll ind = 0, j = i; j <= m && !tk[j]; ind++, j = (j * ll(x) + lim - 1) / lim) {
					tk[j] = true;
					if (ind - lst <= y && res[j] >= Maxm)
						res[j] = T;
					if (res[j] < T) lst = ind;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d%c", res[i] < Maxm? res[i]: -1, i + 1 <= m? ' ': '\n');
    return 0;
}
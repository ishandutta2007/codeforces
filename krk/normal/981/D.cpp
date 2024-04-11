#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 60;
const int Maxn = 52;

int n, k;
ll a[Maxn];
ll res;
bool ok[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int b = Maxb - 1; b >= 0; b--) {
		fill((bool*)ok, (bool*)ok + Maxn * Maxn, false);
		ok[0][0] = true;
		for (int i = 0; i < k; i++)
			for (int j = 0; j < n; j++) if (ok[i][j]) {
				ll sum = 0;
				for (int l = j; l < n; l++) {
					sum += a[l];
					if ((res & sum) == res)
						if (sum & 1ll << ll(b)) ok[i + 1][l + 1] = true;
				}
			}
		if (ok[k][n]) res |= 1ll << ll(b);
	}
	cout << res << endl;
	return 0;
}
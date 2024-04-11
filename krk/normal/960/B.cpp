#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int Maxm = 2000005;

int n, k1, k2;
int a[Maxn], b[Maxn];
int cnt[Maxm];
ll res;

int main()
{
	scanf("%d %d %d", &n, &k1, &k2);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		cnt[abs(a[i] - b[i])]++;
	}
	int tot = k1 + k2;
	for (int i = Maxm - 1; i > 0 && tot > 0; i--) if (cnt[i] > 0) {
		int tk = min(cnt[i], tot); cnt[i] -= tk; tot -= tk;
		cnt[i - 1] += tk;
	}
	tot %= 2;
	if (tot > 0) cnt[1]++;
	for (int i = 1; i < Maxm; i++) if (cnt[i] > 0)
		res += ll(cnt[i]) * ll(i) * i;
	cout << res << endl;
	return 0;
}
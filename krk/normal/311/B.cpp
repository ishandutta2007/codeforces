#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll Inf = 1000000000000000000ll;
const int Maxp = 105;
const int Maxn = 100005;

int n, m, p;
int d[Maxn];
int a[Maxn];
ll sum[Maxn];
ll dp[Maxp][Maxn];
ll Qf[Maxp][Maxn], Qs[Maxp][Maxn];
int s[Maxp], e[Maxp];

void Insert(int i, ll a, ll b)
{
	if (e[i] - s[i] >= 2) {
		ld cur = ld(Qs[i][e[i] - 1] - b) / ld(a - Qf[i][e[i] - 1]);
		while (e[i] - s[i] >= 2) {
			ld nxt = ld(Qs[i][e[i] - 2] - b) / ld(a - Qf[i][e[i] - 2]);
			if (cur > nxt) break;
			cur = nxt; e[i]--;
		}
	}
	Qf[i][e[i]] = a; Qs[i][e[i]] = b; e[i]++;
}

ll Get(int i, ll x)
{
	while (s[i] + 1 < e[i] && Qf[i][s[i] + 1] * x + Qs[i][s[i] + 1] <= Qf[i][s[i]] * x + Qs[i][s[i]]) s[i]++;
	return s[i] == e[i]? Inf: Qf[i][s[i]] * x + Qs[i][s[i]];
}

int main()
{
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &d[i]); d[i] += d[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		int h, t; scanf("%d %d", &h, &t);
		a[i] = t - d[h];
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + a[i];
	dp[0][0] = 0; Insert(0, 0ll, 0ll);
	for (int j = 1; j <= m; j++)
		for (int i = 1; i <= p; i++) {
			dp[i][j] = ll(a[j]) * ll(j) - sum[j] + Get(i - 1, a[j]);
			Insert(i, -j, dp[i][j] + sum[j]);
		}
	printf("%I64d\n", dp[p][m]);
	return 0;
}
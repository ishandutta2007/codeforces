#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 200005;
const int Inf = 1000000000;

int n, m;
int a[Maxn];
int pos[Maxm];
int L[Maxm], R[Maxm];
ii mon[Maxn];
int lens[Maxn];
int mlen;
int dp[Maxn][2];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		int s; scanf("%d", &s);
		pos[s]++;
	}
	R[Maxm - 1] = Inf;
	for (int i = Maxm - 2; i >= 0; i--)
		R[i] = pos[i]? i: R[i + 1];
	L[0] = -Inf;
	for (int i = 1; i < Maxm; i++) {
		L[i] = pos[i]? i: L[i - 1];
		pos[i] += pos[i - 1];
	}
	mlen++; mon[mlen] = ii(a[0], a[0]); lens[mlen] = 1;
	for (int i = 1; i < n; i++)
		if (mon[mlen].second + 1 == a[i]) { mon[mlen].second++; lens[mlen]++; }
		else {
			mlen++; mon[mlen] = ii(a[i], a[i]); lens[mlen] = lens[mlen - 1] + 1;
		}
	fill((int*)dp, (int*)dp + Maxn * 2, -Inf); dp[1][0] = 0;
	for (int i = 1; i <= mlen; i++) {
		if (i > 1) {
			int sum = mon[i - 1].second - mon[i - 1].first + 1;
			int stars = pos[mon[i].first - 1] - pos[mon[i].first - sum - 1];
			int k = i - 1;
			int C = lens[i - 1] - mon[i].first;
			while (k != -1) {
				dp[i][1] = max(dp[i][1], dp[k][0] + stars);
				int g = L[mon[i].first - sum - 1];
				if (g == -Inf) break;
				k = upper_bound(lens, lens + k, g + C) - lens;
				if (k == 0) break;
				sum = lens[i - 1] - lens[k - 1];
				stars = pos[mon[i].first - 1] - pos[mon[i].first - sum - 1];
			}
		}
		int bet = max(dp[i][0], dp[i][1]);
		int sum = mon[i].second - mon[i].first + 1;
		int stars = pos[mon[i].first + sum - 1] - pos[mon[i].first - 1];
		int k = i;
		int C = lens[i - 1] - mon[i].first;
		while (k != -1) {
			dp[k + 1][0] = max(dp[k + 1][0], bet + stars);
			int g = R[mon[i].first + sum];
			if (g == Inf) break;
			k = upper_bound(lens + k + 1, lens + mlen + 1, g + C) - lens;
			if (k > mlen) break;
			sum = lens[k] - lens[i - 1];
			stars = pos[mon[i].first + sum - 1] - pos[mon[i].first - 1];
		}
	}
	printf("%d\n", dp[mlen + 1][0]);
	return 0;
}
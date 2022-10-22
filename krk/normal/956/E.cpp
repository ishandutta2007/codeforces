#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;
const int Inf = 1000000000;

bool dpp[Maxn];
int dp[Maxn];
int n, l, r;
int a[Maxn];
int b[Maxn];
vector <int> seq;
int best[Maxn];
int res;

int main()
{
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	dpp[0] = true;
	for (int i = 0; i < n; i++) if (b[i] == 0)
		for (int j = Maxn - 1 - a[i]; j >= 0; j--) if (dpp[j])
			dpp[j + a[i]] = true;
	for (int i = 0; i < n; i++) if (b[i] == 1)
		seq.push_back(a[i]);
	sort(seq.begin(), seq.end());
	int pnt = 0;
	int col = 0;
	for (int i = 0; i < Maxn; i++) {
		while (pnt < seq.size() && col + seq[pnt] <= i) {
			col += seq[pnt]; pnt++;
		}
		best[i] = pnt;
	}
	for (int i = 0; i < Maxn; i++)
		dp[i] = dpp[i]? 0: Inf;
	for (int i = l; i <= r; i++) if (dpp[i])
		res = max(res, min(int(seq.size()), best[r - i] + 1));
	for (int i = int(seq.size()) - 1; i >= 0; i--) {
		for (int j = Maxn - 1; j >= seq[i]; j--) {
			dp[j] = min(dp[j], dp[j - seq[i]] + 1);
			if (l <= j && j <= r && dp[j] < Inf) {
				bool has = dp[j] < int(seq.size()) - i;
				res = max(res, min(i + has, best[r - j] + has));
			}
		}
	}
	printf("%d\n", res);
	return 0;
}
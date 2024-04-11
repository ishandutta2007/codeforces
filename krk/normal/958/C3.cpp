#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 500005;
const int Maxk = 105;
const int Maxs = Maxk * Maxk;

int n, k, p;
int a[Maxn];
int md[Maxn];
int dp[Maxk][Maxs];
vector <int> bymod[Maxk];
vector <ii> seq[Maxn];
int res = Inf;

int main()
{
	scanf("%d %d %d", &n, &k, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		md[i] = (md[i - 1] + a[i]) % p;
	}
	for (int i = n; i > 0; i--)
		bymod[md[i]].push_back(i);
	fill((int*)dp, (int*)dp + Maxk * Maxs, Inf);
	dp[0][0] = 1; seq[1].push_back(ii(0, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < seq[i].size(); j++) {
			int kk = seq[i][j].first, cur = seq[i][j].second;
			if (dp[kk][cur] != i) continue;
			if (kk == k - 1) {
				int cand = cur + (md[n] - md[i - 1] + p) % p;
				res = min(res, cand);
			} else for (int j = 0; j < p; j++) {
				int ncur = cur + j;
				int look = (md[i - 1] + j) % p;
				if (!bymod[look].empty() && bymod[look].back() + 1 < dp[kk + 1][ncur]) {
					dp[kk + 1][ncur] = bymod[look].back() + 1;
					seq[bymod[look].back() + 1].push_back(ii(kk + 1, ncur));
				}
			}
		}
		bymod[md[i]].pop_back();
	}
	printf("%d\n", res);
	return 0;
}
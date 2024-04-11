#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) y = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 100000000000000005
#define MOD 1000000007
#define MAXN 1000

#define FILE

int t, k;
int n, m;
// int dp[MAXN][MAXN];

int main() {
#ifdef FILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif //FILE
	scanf("%d%d", &t, &k);
	while (t--) {
		scanf("%d%d", &n, &m);
		if (n > m) swap(n, m);
		int polar = (m - n) % 2;
		n--;
		if (k == 1) {
			if (polar) printf("+\n");
			else {
				if (n % 2 == 0) printf("-\n");
				else printf("+\n");
			}
		} else {
			int rem = n % ((k + 1) * 2);
			if (polar) {
				if (rem <= k * 2 && rem >= k + 1) printf("-\n");
				else printf("+\n");
			} else {
				if (rem >= 0 && rem < k) printf("-\n");
				else printf("+\n");
			}
		}
		// 		RREP (i, n, 1) {
		// 			RREP (j, m, 1) {
		// 				int a = -1, b = -1, c = -1;
		// 				if (i + k <= n && j + k <= m) a = dp[i + k][j + k];
		// 				if (i + 1 <= n) b = dp[i + 1][j];
		// 				if (j + 1 <= m) c = dp[i][j + 1];
		// 				REP (k, 0, 5) {
		// 					if (k != a && k != b && k != c) {
		// 						dp[i][j] = k;
		// 						break;
		// 					}
		// 				}
		// 			}
		// 		}
		// 		REP (i, 1, n + 1) {
		// 			REP (j, 1, m + 1) {
		// 				printf("%d ", dp[i][j]);
		// 			}
		// 			printf("\n");
		// 		}
	}
}

/*
   1 3
   5 5
   */
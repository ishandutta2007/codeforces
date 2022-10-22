#include <bits/stdc++.h> 
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
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
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int t;
int n;
ll k;
ll dp[MAXN];
vi ans;
int out;

int main() {
	scanf("%d", &t);
	dp[0] = dp[1] = 1;
	REP (i, 2, MAXN) {
		dp[i] = dp[i - 1] * 2;
		if (dp[i] > LINF) {
			out = i;
			break;
		}
	}
	while (t--) {
		scanf("%d%lld", &n, &k);
		ans.clear();
		while (n) {
			if (n - 1 >= out) {
				n--;
				ans.pb(1);
			} else {
				int lo = 1, hi = n, mid;
				while (lo < hi) {
					mid = hi + lo >> 1;
					ll sm = 0;
					bool ex = 0;
					REP (j, n - mid, n) {
						if (sm >= k - dp[j]) {
						   	ex = 1;
							break;
						}
						sm += dp[j];
					}
					if (ex) {
						hi = mid;
					} else {
						lo = mid + 1;
					}
				}
				REP (j, n - hi + 1, n) {
					k -= dp[j];
				}
				n -= hi;
				ans.pb(hi);
			}
		}
		if (k != 1) {
			printf("-1\n");
		} else {
			int cur = 1;
			for (int i : ans) {
				RREP (j, i, 1) {
					printf("%d ", cur + j - 1);
				}
				cur += i;
			}
			printf("\n");
		}
	}
	return 0;
}
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
#define MAXN 105
#define MAX 200005
#define MAXA 2005

int n;
int a[MAXN];
bitset<MAX> dp;

int main() {
	scanf("%d", &n);
	int sum = 0;
	REP (i, 0, n) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if (sum % 2 == 1) {
		printf("0\n");
		return 0;
	}
	sum /= 2;
	dp[0] = 1;
	REP (i, 0, n) {
		dp |= dp << a[i];
	}
	if (dp[sum]) {
		printf("1\n");
		for (int k = 0; (1 << k) <= MAXA; k++) {
			REP (i, 0, n) {
				if (a[i] % (1 << k) == 0 && a[i] % (1 << k + 1) != 0) {
					printf("%d\n", i + 1);
					return 0;
				}
			}
		}
	} else {
		printf("0\n");
	}
	return 0;
}
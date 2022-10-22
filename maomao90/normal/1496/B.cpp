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
int n, k;
int a[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		REP (i, 0, n) scanf("%d", &a[i]);
		if (k == 0) {
			printf("%d\n", n);
			continue;
		}
		sort(a, a + n);
		if (a[n - 1] == n - 1) {
			printf("%d\n", n + k);
		} else {
			int mex = -1, mx = a[n - 1];
			REP (i, 0, n) {
				if (a[i] != i) {
					mex = i;
					break;
				}
			}
			int mid = (mx + mex - 1) / 2 + 1;
			bool has = 0;
			REP (i, 0, n) {
				if (a[i] == mid) has = 1;
			}
			if (has) printf("%d\n", n);
			else printf("%d\n", n + 1);
		}
	}
	return 0;
}
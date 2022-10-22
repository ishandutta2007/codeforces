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

int t;
int n, x;
int w[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &x);
		REP (i, 0, n) scanf("%d", &w[i]);
		int sum = 0;
		REP (i, 0, n) {
			sum += w[i];
			if (sum == x) {
				REP (j, i + 1, n) {
					if (w[j] != w[i]) {
						swap(w[j], w[i]);
						break;
					}
				}
			}
		}
		if (sum == x) {
			printf("NO\n");
		} else {
			printf("YES\n");
			REP (i, 0, n) printf("%d ", w[i]);
			printf("\n");
		}
	}
	return 0;
}
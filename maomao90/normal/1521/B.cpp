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

#define INF 2000000000
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int t;
int n;
int a[MAXN];
vector<tuple<int, int, int, int>> ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
		}
		ans.clear();
		a[0] = 1;
		a[n + 1] = 1;
		REP (i, 1, n) {
			if (a[i] > a[i + 1]) {
				int x = a[i + 1];
				while (__gcd(a[i - 1], x) != 1 || __gcd(x, a[i + 1]) != 1) {
					x++;
				}
				assert(x <= INF);
				a[i] = x;
				ans.pb(i, i + 1, x, a[i + 1]);
			} else {
				int y = a[i];
				while (__gcd(a[i], y) != 1) {
					y++;
				}
				assert(y <= INF);
				a[i + 1] = y;
				ans.pb(i, i + 1, a[i], y);
			}
		}
		printf("%d\n", (int) ans.size());
		for (auto [w, x, y, z] : ans) {
			printf("%d %d %d %d\n", w, x, y, z);
		}
	}
	return 0;
}
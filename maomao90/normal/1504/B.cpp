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
#define MAXN 300005

int t;
int n;
char a[MAXN], b[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", &a);
		scanf(" %s", &b);
		int diff = 0;
		bool same = a[0] == b[0];
		a[n] = b[n] = 1;
		bool pos = 1;
		REP (i, 0, n + 1) {
			if (same != (a[i] == b[i])) {
				if (diff != 0) {
					pos = 0;
					break;
				}
			}
			diff += a[i] == '0' ? 1 : -1;
			same = a[i] == b[i];
		}
		if (pos) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
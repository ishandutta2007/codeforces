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
ii rc[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%d", &rc[i].FI);
		}
		REP (i, 1, n + 1) {
			scanf("%d", &rc[i].SE);
		}
		sort(rc + 1, rc + n + 1);
		rc[0] = MP(1, 1);
		int ans = 0;
		REP (i, 1, n + 1) {
			int curr = rc[i - 1].FI, curc = rc[i - 1].SE;
			if ((rc[i - 1].FI + rc[i - 1].SE) % 2 == 0) {
				curr++;
			}
			int diff = rc[i].SE - rc[i - 1].SE;
			curr += diff;
			curc += diff;
			if (curr > rc[i].FI) {
				ans += rc[i].SE - rc[i - 1].SE;
				continue;
			}
			int extra = (rc[i].FI - curr + 1) / 2;
			ans += extra;
		}
		printf("%d\n", ans);
	}
	return 0;
}
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
int n;
int a[MAXN], b[MAXN];
int tme[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) scanf("%d%d", &a[i], &b[i]);
		REP (i, 1, n + 1) scanf("%d", &tme[i]);
		int cur = 0;
		REP (i, 1, n + 1) {
			cur += a[i] - b[i - 1] + tme[i];
			if (i != n) {
				cur += (b[i] - a[i] - 1) / 2 + 1;
				mxto(cur, b[i]);
			}
		}
		printf("%d\n", cur);
	}
	return 0;
}
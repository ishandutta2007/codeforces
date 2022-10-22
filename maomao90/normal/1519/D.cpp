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
#define MAXN 5005

int n;
ll a[MAXN], b[MAXN];
ll pre[MAXN];
ll rot[MAXN][MAXN];

ll sum(int s, int e, ll* arr) {
	if (s > e) return 0;
	if (s == 0) return arr[e];
	return arr[e] - arr[s - 1];
}

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%lld", &a[i]);
	}
	REP (i, 0, n) {
		scanf("%lld", &b[i]);
	}
	REP (i, 0, n) {
		pre[i] = a[i] * b[i];
		if (i != 0) {
			pre[i] += pre[i - 1];
		}
	}
	reverse(a, a + n);
	REP (i, 0, n) {
		REP (j, 0, n) {
			int v = (j + i) % n;
			rot[i][j] = a[v] * b[j];
			if (j != 0) rot[i][j] += rot[i][j - 1];
		}
	}
	ll ans = 0;
	REP (i, 0, n) {
		RREP (j, i, 0) {
			int off = (n - i - 1 - j + n) % n;
			mxto(ans, sum(0, j - 1, pre) + sum(i + 1, n - 1, pre) + sum(j, i, rot[off]));
		}
	}
	printf("%lld\n", ans);
	return 0;
}
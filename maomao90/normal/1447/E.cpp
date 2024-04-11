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
#define MAXK 30

int n;
int a[MAXN];

int dp(int l, int r, int k) {
	if (l >= r) return 0;
	if (l + 1 == r) return 1;
	assert(k != -1);
	int mid = r;
	REP (i, l, r) {
		if ((a[i] & (1 << k)) != 0) {
			mid = i;
			break;
		}
	}
	REP (i, mid, r) {
		a[i] ^= (1 << k);
	}
	if (mid == r || mid == l) return dp(l, r, k - 1);
	return max(dp(l, mid, k - 1), dp(mid, r, k - 1)) + 1;
}

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	printf("%d\n", n - dp(0, n, MAXK));
	return 0;
}
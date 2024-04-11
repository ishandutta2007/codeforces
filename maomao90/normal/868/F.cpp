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
#define MAXN 100005

int n, k;
int a[MAXN];
ll dp[MAXN], prv[MAXN];
int gl = 1, gr = 0, occ[MAXN];
ll curcost;

ll cost(int l, int r) {
	while (r > gr) {
		curcost += occ[a[++gr]]++;
	}
	while (l < gl) {
		curcost += occ[a[--gl]]++;
	}
	while (r < gr) {
		curcost -= --occ[a[gr--]];
	}
	while (l > gl) {
		curcost -= --occ[a[gl++]];
	}
	return curcost;
}

void dnc(int l, int r, int optl, int optr) {
	if (l > r) return;
	int mid = l + r >> 1;
	ll mn = LINF; int opt = -1;
	REP (i, max(0, optl), min(optr, mid - 1) + 1) {
		ll tmp = prv[i] + cost(i + 1, mid);
		if (tmp < mn) {
			opt = i;
			mn = tmp;
		}
	}
	dp[mid] = mn;
	dnc(l, mid - 1, optl, opt);
	dnc(mid + 1, r, opt, optr);
}

int main() {
	scanf("%d%d", &n, &k);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
	}
	REP (i, 1, n + 1) {
		prv[i] = LINF;
	}
	REP (i, 0, k + 1) {
		dnc(1, n, 0, n);
		swap(dp, prv);
	}
	printf("%lld\n", dp[n]);
	return 0;
}
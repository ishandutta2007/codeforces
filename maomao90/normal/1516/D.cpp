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

int n, q;
int a[MAXN];
bool isprime[MAXN];
vi primes;
vi factors[MAXN];
int prv[MAXN], p[20][MAXN];

int main() {
	scanf("%d%d", &n, &q);
	REP (i, 1, n + 1) scanf("%d", &a[i]);
	REP (i, 2, MAXN) isprime[i] = 1;
	for (ll i = 2; i * i * i * i < MAXN; i++) {
		if (!isprime[i]) continue;
		for (ll j = i * i; j * j < MAXN; j += i) {
			isprime[j] = 0;
		}
	}
	for (int i = 2; i * i < MAXN; i++) {
		if (isprime[i]) primes.pb(i);
	}
	REP (i, 1, n + 1) {
		for (int j : primes) {
			if (a[i] % j == 0) {
				factors[i].pb(j);
			}
			while (a[i] % j == 0) {
				a[i] /= j;
			}
		}
		if (a[i] != 1) factors[i].pb(a[i]);
	}
	memset(prv, -1, sizeof prv);
	memset(p, -1, sizeof p);
	REP (i, 1, n + 1) {
		for (int j : factors[i]) {
			if (prv[j] != -1) {
				if (p[0][prv[j]] == -1) {
					p[0][prv[j]] = i;
				}
			}
			prv[j] = i;
		}
	}
	RREP (i, n - 1, 1) {
		if (p[0][i + 1] != -1) p[0][i] = min(p[0][i + 1], p[0][i]);
		if (p[0][i] == -1) p[0][i] = p[0][i + 1];
	}
	REP (k, 1, 20) {
		REP (i, 1, n + 1) {
			if (p[k - 1][i] == -1) p[k][i] = -1;
			else p[k][i] = p[k - 1][p[k - 1][i]];
		}
	}
	REP (i, 0, q) {
		int l, r; scanf("%d%d", &l, &r);
		int cur = l;
		int ans = 0;
		RREP (k, 19, 0) {
			if (p[k][cur] != -1 && p[k][cur] <= r) {
				cur = p[k][cur];
				ans += (1 << k);
			}
		}
		ans++;
		printf("%d\n", ans);
	}
	return 0;
}
// time-limit: 4000
// problem-url: https://codeforces.com/contest/1622/problem/F

// Dear friends, since God so loved us, we also ought to love one another
// 1 John 4:11
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
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
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 1000005

int n;
int lp[MAXN];
ll hsh[MAXN];
vi primes;
map<ll, int> mp;

int main() {
	mt19937_64 rnd(234901);
	scanf("%d", &n);
	REP (i, 2, n + 1) {
		if (lp[i] == 0) {
			lp[i] = i;
			hsh[i] = rnd();
			primes.pb(i);
		}
		debug("%d: %lld\n", i, hsh[i]);
		for (int j = 0; j < primes.size() && primes[j] <= lp[i] && 
				(ll) primes[j] * i <= n; j++) {
			int x = primes[j] * i;
			lp[x] = primes[j];
			hsh[x] = hsh[primes[j]] ^ hsh[i];
			debug(" %d %lld\n", x, hsh[x]);
		}
	}
	ll tot = 0;
	REP (i, 2, n + 1) {
		hsh[i] ^= hsh[i - 1];
		tot ^= hsh[i];
		mp[hsh[i]] = i;
		debug("%d: %lld\n", i, hsh[i]);
	}
	debug("%lld\n", tot);
	if (tot == 0) {
		printf("%d\n", n);
		REP (i, 1, n + 1) {
			printf("%d ", i);
		}
		printf("\n");
		return 0;
	}
	REP (i, 1, n + 1) {
		if ((tot ^ hsh[i]) == 0) {
			printf("%d\n", n - 1);
			REP (j, 1, n + 1) {
				if (j == i) continue;
				printf("%d ", j);
			}
			printf("\n");
			return 0;
		}
	}
	REP (i, 1, n + 1) {
		if (mp[tot ^ hsh[i]]) {
			assert(tot ^ hsh[i] ^ hsh[mp[tot ^ hsh[i]]] == 0);
			printf("%d\n", n - 2);
			REP (j, 1, n + 1) {
				if (j == i || j == mp[tot ^ hsh[i]]) continue;
				printf("%d ", j);
			}
			printf("\n");
			return 0;
		}
	}
	printf("%d\n", n - 3);
	REP (i, 1, n + 1) {
		if (i == 2 || i == (n - 1) / 2 || i == n) continue;
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}
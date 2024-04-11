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
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 998244353
#define MAXN 200005
#define MAX 40000000
#define MAXL 50

ll d;
int q;
bool isp[MAX];
int cnt[MAXL];
ll c[MAXL][MAXL];
vll primes;

int main() {
	scanf("%lld", &d);
	REP (i, 0, MAXL) {
		c[i][0] = c[i][i] = 1;
		REP (j, 1, i) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
		}
	}
	for (int i = 2; (ll) i * i <= d; i++) {
		isp[i] = 1;
	}
	for (int i = 2; (ll) i * i * i * i <= d; i++) {
		if (!isp[i]) continue;
		for (int j = i * i; (ll) j * j <= d; j += i) {
			isp[j] = 0;
		}
	}
	ll tmp = d;
	for (int i = 2; (ll) i * i <= d; i++) {
		if (isp[i] && d % i == 0) {
			primes.pb(i);
			while (tmp % i == 0) {
				tmp /= i;
			}
		}
	}
	if (tmp != 1) primes.pb(tmp);
	scanf("%d", &q);
	while (q--) {
		ll u, v; scanf("%lld%lld", &u, &v);
		REP (i, 0, primes.size()) {
			cnt[i] = 0;
		}
		REP (i, 0, primes.size()) {
			while (u % primes[i] == 0) {
				u /= primes[i];
				cnt[i]++;
			}
			while (v % primes[i] == 0) {
				v /= primes[i];
				cnt[i]--;
			}
			//debug("%d %lld: %d\n", i, primes[i], cnt[i]);
		}
		int tot = 0;
		ll ans = 1;
		REP (i, 0, primes.size()) {
			if (cnt[i] > 0) continue;
			tot += -cnt[i];
			ans = ans * c[tot][-cnt[i]] % MOD;
		}
		tot = 0;
		REP (i, 0, primes.size()) {
			if (cnt[i] < 0) continue;
			tot += cnt[i];
			ans = ans * c[tot][cnt[i]] % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
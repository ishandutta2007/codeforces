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
#define MAXN 100005

int t;
int n;
char s[MAXN];
ll fact[MAXN], ifact[MAXN];

ll fpow(ll b, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) {
			res = res * b % MOD;
		}
		b = b * b % MOD;
		p >>= 1;
	}
	return res;
}
ll inv(ll a) {
	return fpow(a, MOD - 2);
}
ll c(ll n, ll r) {
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

int main() {
	fact[0] = 1;
	REP (i, 1, MAXN) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	ifact[MAXN - 1] = inv(fact[MAXN - 1]);
	RREP (i, MAXN - 2, 0) {
		ifact[i] = ifact[i + 1] * (i + 1) % MOD;
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", s);
		int zeros = 0, grps = 0;
		bool prv = 0;
		REP (i, 0, n) {
			if (s[i] == '1' && prv) {
				grps++;
			}
			if (s[i] == '0') {
				zeros++;
				prv = 0;
			} else {
				prv ^= 1;
			}
		}	
		printf("%lld\n", c(zeros + grps, grps));
	}
	return 0;
}
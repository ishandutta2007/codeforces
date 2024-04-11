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
#define MAXN 200005

int t;
ll k, x;

bool isPos(ll v) {
	ll mn = min(k, v);
	ll cur = mn * (mn + 1) / 2;
	if (v > k) {
		cur += mn * (mn - 1) / 2;
		ll diff = v - k;
		ll c = k - diff - 1;
		cur -= c * (c + 1) / 2;
	}
	return cur >= x;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &k, &x);
		ll lo = 0, hi = k * 2 - 1, mid;
		while (lo < hi) {
			mid = lo + hi >> 1;
			if (isPos(mid)) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		printf("%lld\n", hi);
	}
	return 0;
}
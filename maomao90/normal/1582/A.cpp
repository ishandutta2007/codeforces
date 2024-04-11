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
ll a, b, c;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld%lld", &a, &b, &c);
		ll sm = a + 2 * b + 3 * c;
		REP (i, 0, sm + 1) {
			ll t = sm - i;
			if (t % 2 == 1) continue;
			ll mn = min(c, t / 3);
			t -= mn * 3;
			mn = min(b, t / 2);
			t -= mn * 2;
			mn = min(a, t);
			t -= mn;
			if (t == 0) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
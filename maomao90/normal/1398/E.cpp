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
#define MOD 1000000007
#define MAXN 200005

int n;
multiset<int, greater<int>> ot;
multiset<int> ex, light;
ll ans;

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		int t, d; scanf("%d%d", &t, &d);
		ans += d;
		if (d > 0) {
			ot.insert(d);
			if (t == 1) {
				auto ptr = light.insert(d);
				if (ptr == light.begin()) {
					ot.erase(ot.find(d));
					if (next(ptr) != light.end()) {
						ot.insert(*next(ptr));
					}
				}
			}
		} else {
			d = -d;
			if (t == 1) {
				auto ptr = light.erase(light.find(d));
				if (ptr == light.begin()) {
					if (ptr != light.end()) {
						int v = *ptr;
						if (!ex.empty() && v >= *ex.begin()) {
							ans -= v;
							ex.erase(ex.find(v));
						} else {
							ot.erase(ot.find(v));
						}
					}
				} else {
					if (!ex.empty() && d >= *ex.begin()) {
						ans -= d;
						ex.erase(ex.find(d));
					} else {
						ot.erase(ot.find(d));
					}
				}
			} else {
				if (!ex.empty() && d >= *ex.begin()) {
					ans -= d;
					ex.erase(ex.find(d));
				} else {
					ot.erase(ot.find(d));
				}
			}
		}
		if (!ot.empty()) {
			int v = *ot.begin();
			ans += v;
			ex.insert(v);
			ot.erase(ot.begin());
			v = *ex.begin();
			ans -= v;
			ot.insert(v);
			ex.erase(ex.begin());
		}
		while (ex.size() < light.size() && !ot.empty()) {
			int v = *ot.begin();
			ans += v;
			ex.insert(v);
			ot.erase(ot.begin());
		}
		while (ex.size() > light.size()) {
			int v = *ex.begin();
			ans -= v;
			ot.insert(v);
			ex.erase(ex.begin());
		}
		printf("%lld\n", ans);
	}
	return 0;
}
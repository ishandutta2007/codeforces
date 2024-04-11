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
int n;
int lp[MAXN];
vi divs, primes;
vector<vi> cla;
int used[MAXN];
vi ans;

int main() {
	scanf("%d", &t);
	REP (i, 2, MAXN) {
		lp[i] = i;
	}
	REP (i, 2, MAXN) {
		if (lp[i] != i) continue;
		primes.pb(i);
		for (ll j = (ll) i * i; j < MAXN; j += i) {
			mnto(lp[j], i);
		}
	}
	while (t--) {
		scanf("%d", &n);
		divs.clear();
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				divs.pb(i);
			}
		}
		for (int i = 2; i * i < n; i++) {
			if (n % i == 0) {
				divs.pb(n / i);
			}
		}
		int t = n;
		cla.clear();
		REP (i, 0, divs.size()) {
			used[i] = 0;
		}
		while (t > 1) {
			int u = -1;
			for (int i : primes) {
				if (t % i == 0) {
					u = i;
					break;
				}
			}
			if (u == -1) {
				u = t;
			}
			while (t % u == 0) {
				t /= u;
			}
			vi v;
			REP (i, 0, divs.size()) {
				if (used[i] || divs[i] % u != 0) continue;
				used[i] = 1;
				v.pb(divs[i]);
			}
			cla.pb(v);
		}
		ans.clear();
		int res = 0;
		REP (i, 0, cla.size()) {
			vi v = cla[i];
			if (i + 1 != cla.size()) {
				bool found = 0;
				REP (j, 0, v.size()) {
					if (v[j] % cla[i + 1][0] == 0) {
						swap(v[j], v[v.size() - 1]);
						found = 1;
						break;
					}
				}
				if (!found) res = 1;
			}
			for (int x : v) {
				ans.pb(x);
			}
		}
		ans.pb(n);
		for (int i : ans) {
			printf("%d ", i);
		}
		printf("\n");
		printf("%d\n", res);
	}
	return 0;
}
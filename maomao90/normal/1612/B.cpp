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
int n, a, b;
bool used[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &a, &b);
		REP (i, 1, n + 1) {
			used[i] = 0;
		}
		vi lft, rht;
		REP (i, 1, a) {
			used[i] = 1;
			rht.pb(i);
		}
		used[a] = 1;
		lft.pb(a);
		RREP (i, n, b + 1) {
			if (used[i]) continue;
			used[i] = 1;
			lft.pb(i);
		}
		if (!used[b]) {
			rht.pb(b);
		}
		REP (i, a + 1, b) {
			if (rht.size() < n / 2) {
				rht.pb(i);
			} else {
				lft.pb(i);
			}
		}
		int mn = INF;
		for (int i : lft) {
			mnto(mn, i);
			debug("%d ", i);
		}
		debug("\n");
		int mx = -INF;
		for (int i : rht) {
			mxto(mx, i);
			debug("%d ", i);
		}
		debug("\n");
		if (lft.size() != n / 2 || rht.size() != n / 2 || mn != a || mx != b) {
			printf("-1\n");
		} else {
			for (int i : lft) {
				printf("%d ", i);
			}
			for (int i : rht) {
				printf("%d ", i);
			}
			printf("\n");
		}
	}
	return 0;
}
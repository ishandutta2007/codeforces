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

int n, m, q;
char tmp[MAXN];
string s[MAXN];
int pref[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, n) {
		scanf(" %s", tmp);
		s[i] = tmp;
	}
	REP (i, 0, n - 1) {
		REP (j, 0, m - 1) {
			if (s[i][j + 1] == 'X' && s[i + 1][j] == 'X') {
				pref[j] = 1;
			}
		}
	}
	REP (i, 1, m) {
		debug("%d: %d\n", i, pref[i]);
		pref[i] += pref[i - 1];
	}
	scanf("%d", &q);
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		l--; r--;
		int d = (r == 0 ? 0 : pref[r - 1]) - (l == 0 ? 0 : pref[l - 1]);
		if (d == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
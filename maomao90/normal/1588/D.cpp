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
#define MAXN 15
#define MAXC 120

int t;
int n;
char s[MAXN][MAXC];
vi mp[MAXN][55];

int ctoi(char c) {
	if (c < 'a') {
		return c - 'A';
	} else {
		return c - 'a' + 26;
	}
}

char itoc(int i) {
	if (i < 26) {
		return 'A' + i;
	} else {
		return 'a' + i - 26;
	}
}

int memo[55][1030];
ii p[55][1030];
int dp(int i, int msk) {
	if (memo[i][msk] != -1) return memo[i][msk];
	p[i][msk] = MP(-1, -1);
	int res = 1;
	string ress = string(1, itoc(i));
	REP (c, 0, 53) {
		bool pos = 1;
		int nmsk = 0;
		REP (j, 0, n) {
			bool on = msk & (1 << j);
			if (mp[j][i].size() < on + 1) {
				return memo[i][msk] = 0;
			}
			int r = mp[j][i][on] + 1;
			int f = -1;
			REP (k, 0, mp[j][c].size()) {
				if (mp[j][c][k] >= r) {
					f = k;
					break;
				}
			}
			if (f == -1) {
				pos = 0;
			} else if (f == 1) {
				nmsk |= 1 << j;
			}
		}
		if (pos) {
			if (mxto(res, 1 + dp(c, nmsk))) {
				p[i][msk] = MP(c, nmsk);
			}
		}
	}
	return memo[i][msk] = res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			REP (j, 0, 55) {
				mp[i][j].clear();
			}
		}
		REP (i, 0, n) {
			scanf(" %s", s[i]);
			int m = strlen(s[i]);
			REP (j, 0, m) {
				mp[i][ctoi(s[i][j])].pb(j);
			}
		}
		memset(memo, -1, sizeof memo);
		int ans = 0;
		string anss = "";
		ii u = MP(-1, -1);
		REP (i, 0, 53) {
			if (mxto(ans, dp(i, 0))) {
				u = MP(i, 0);
			}
		}
		while (u.FI != -1) {
			anss += itoc(u.FI);
			u = p[u.FI][u.SE];
		}
		printf("%d\n", ans);
		printf("%s\n", anss.c_str());
	}
	return 0;
}
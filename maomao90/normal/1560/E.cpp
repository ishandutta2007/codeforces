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
#define MAXN 500005

int t;
char s[MAXN];
int occ[30];
int req[30];
char ans[MAXN], ord[30];
bool used[30];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf(" %s", s);
		int n = strlen(s);
		int dis = 0;
		memset(occ, 0, sizeof occ);
		memset(ord, 0, sizeof ord);
		memset(used, 0, sizeof used);
		memset(req, 0, sizeof req);
		REP (i, 0, n) {
			if (occ[s[i] - 'a']++ == 0) {
				dis++;
			}
		}
		int i = n - 1;
		bool pos = 1;
		RREP (a, dis - 1, 0) {
			char add = '-';
			RREP (j, i, 0) {
				if (!used[s[j] - 'a']) {
					add = s[j];
					break;
				}
			}
			used[add - 'a'] = 1;
			ord[a] = add;
			if (occ[add - 'a'] % (a + 1) != 0) {
				pos = 0;
				break;
			}
			if (a == 0) break;
			req[add - 'a'] = occ[add - 'a'] / (a + 1);
			int mn = INF;
			REP (c, 0, 30) {
				int times = req[c];
				if (times == 0) continue;
				RREP (j, i, 0) {
					if (s[j] == c + 'a') {
						if (--times == 0) {
							mnto(mn, j - 1);
							break;
						}
					}
				}
			}
			i = mn;
		}
		if (!pos) {
			printf("-1\n");
			continue;
		}
		REP (j, 0, i + 1) {
			ans[j] = s[j];
		}
		memset(used, 0, sizeof used);
		ans[i + 1] = 0;
		int sze = strlen(ans);
		string o = ans;
		REP (i, 0, dis) {
			used[ord[i] - 'a'] = 1;
			REP (j, 0, sze) {
				if (used[ans[j] - 'a']) continue;
				o += ans[j];
			}
		}
		if (o.size() != n) {
			pos = 0;
		} else {
			REP (i, 0, n) {
				if (o[i] != s[i]) pos = 0;
			}
		}
		if (!pos) {
			printf("-1\n");
			continue;
		}
		printf("%s %s\n", ans, ord);
	}
	return 0;
}
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
#define MAXC 30

int t;
int n, m;
char tmp[MAXN];
string s[MAXN];
int cnt[MAXN][MAXC];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 0, n) {
			scanf(" %s", tmp);
			s[i] = tmp;
		}
		REP (i, 0, m) {
			REP (j, 0, MAXC) {
				cnt[i][j] = 0;
			}
		}
		REP (i, 0, n) {
			REP (j, 0, m) {
				cnt[j][s[i][j] - 'a']++;
			}
		}
		REP (i, 0, n - 1) {
			scanf(" %s", tmp);
			REP (j, 0, m) {
				cnt[j][tmp[j] - 'a']--;
			}
		}
		string ans;
		ans.clear();
		REP (i, 0, m) {
			REP (j, 0, MAXC) {
				if (cnt[i][j] != 0) {
					ans += j + 'a';
				}
			}
		}
		printf("%s\n", ans.c_str());
	}
	return 0;
}
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
#define MAXN 20
#define MAXK 11

int t;
char s[MAXN];
int n, k;

char ans[MAXK];
int memo[MAXK][1 << MAXK][2];
bool dp(int u, int msk, bool same, int remk) {
	if (remk < 0) return 0;
	if (u == n) return 1;
	if (memo[u][msk][same] != -1) {
		return memo[u][msk][same];
	}
	//debug(" %d %s %d %d\n", u, bitset<10>(msk).to_string().c_str(), same, remk);
	if (same) {
		REP (i, s[u] - '0', 10) {
			int nmsk = msk | (1 << i);
			bool used = msk & (1 << i);
			if (dp(u + 1, nmsk, i == (s[u] - '0'), remk - (!used))) {
				ans[u] = i + '0';
				return 1;
			}
		}
	} else {
		REP (i, 0, 10) {
			int nmsk = msk | (1 << i);
			bool used = msk & (1 << i);
			if (dp(u + 1, nmsk, 0, remk - (!used))) {
				ans[u] = i + '0';
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf(" %s", s);
		scanf("%d", &k);
		n = strlen(s);
		memset(memo, -1, sizeof memo);
		memset(ans, 0, sizeof ans);
		dp(0, 0, 1, k);
		printf("%s\n", ans);
	}
	return 0;
}
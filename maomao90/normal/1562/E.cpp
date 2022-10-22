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
#define MAXN 5005

const char endc = 'a' - 1;

int t;
int n;
char s[MAXN];
int cp[MAXN][MAXN];
int dp[MAXN];

int c[MAXN], p[MAXN], cn[MAXN], pn[MAXN], cnt[MAXN];
void buildsuf() {
	s[n] = endc;
	n++;
	REP (i, 0, n) {
		cnt[i] = 0;
	}
	REP (i, 0, n) {
		cnt[s[i] - endc]++;
	}
	REP (i, 1, 30) {
		cnt[i] += cnt[i - 1];
	}
	REP (i, 0, n) {
		p[--cnt[s[i] - endc]] = i;
	}
	REP (i, 0, 30) {
		cnt[i] = 0;
	}
	int cl = 0;
	REP (i, 0, n) {
		if (i == 0 || s[p[i - 1]] != s[p[i]]) {
			cl++;
		}
		c[p[i]] = cl - 1;
	}
	for (int k = 0; (1 << k) < n; k++) {
		REP (i, 0, n) {
			pn[i] = p[i] - (1 << k) + n;
			if (pn[i] >= n) pn[i] -= n;
			cnt[c[i]]++;
		}
		REP (i, 1, cl) {
			cnt[i] += cnt[i - 1];
		}
		RREP (i, n - 1, 0) {
			p[--cnt[c[pn[i]]]] = pn[i];
		}
		REP (i, 0, cl) {
			cnt[i] = 0;
		}
		cl = 0;
		REP (i, 0, n) {
			if (i != 0) {
				ii prv = MP(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]), 
				   nxt = MP(c[p[i]], c[(p[i] + (1 << k)) % n]);
				if (prv != nxt) {
					cl++;
				}
			} else {
				cl++;
			}
			cn[p[i]] = cl - 1;
		}
		swap(c, cn);
	}
	n--;
}
int lcp[MAXN];
void buildlcp() {
	int jmp = 0;
	REP (i, 0, n) {
		if (c[i] == n) {
			lcp[c[i]] = 0;
			jmp = 0;
			continue;
		}
		int j = p[c[i] + 1];
		while (i + jmp < n && j + jmp < n && s[i + jmp] == s[j + jmp]) {
			jmp++;
		}
		lcp[c[i]] = jmp;
		if (jmp > 0) jmp--;
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", s);
		buildsuf();
		buildlcp();
		REP (i, 1, n + 1) {
			int cur = INF;
			REP (j, i + 1, n + 1) {
				mnto(cur, lcp[j - 1]);
				int a = p[i], b = p[j];
				if (a > b) swap(a, b);
				cp[a][b] = cur;
			}
		}
		int ans = 0;
		REP (i, 0, n) {
			dp[i] = n - i;
			REP (j, 0, i) {
				int jmp = cp[j][i];
				if (s[j + jmp] < s[i + jmp]) {
					mxto(dp[i], dp[j] + n - i - jmp);
				}
			}
			mxto(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
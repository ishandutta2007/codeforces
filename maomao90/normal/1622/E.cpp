// time-limit: 2000
// problem-url: https://codeforces.com/contest/1622/problem/E

// Dear friends, since God so loved us, we also ought to love one another
// 1 John 4:11
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
#define MAXN 10
#define MAXM 10005
#define BUF 11

int t;
int n, m;
int x[MAXN + 5];
char s[MAXN + 5][MAXM];
int cnt[MAXM];
vi srt[MAXN * 2 + 5];
int ans;
vi ap;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		ans = -INF;
		REP (i, 0, n) {
			scanf("%d", &x[i]);
		}
		REP (i, 0, n) {
			scanf(" %s", s[i]);
		}
		REP (i, 0, 1 << n) {
			REP (j, 0, n + BUF + 5) {
				srt[j].clear();
			}
			memset(cnt, 0, sizeof cnt);
			REP (j, 0, n) {
				int c = (i >> j & 1) ? -1 : 1;
				REP (k, 0, m) {
					cnt[k] += c * (s[j][k] == '1');
				}
			}
			REP (j, 0, m) {
				srt[cnt[j] + BUF].pb(j);
			}
			int ptr = m;
			int res = 0;
			vi p(m, 0);
			RREP (j, n + BUF + 1, 0) {
				for (int k : srt[j]) {
					p[k] = ptr;
					res += (j - BUF) * ptr;
					ptr--;
				}
			}
			REP (j, 0, n) {
				int c = (i >> j & 1) ? 1 : -1;
				res += x[j] * c;
			}
			if (mxto(ans, res)) {
				ap = p;
			}
		}
		for (int i : ap) {
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
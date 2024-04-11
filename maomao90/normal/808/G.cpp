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
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 100005
#define MAX 4000
#define MAXC 26

int n, m;
char s[MAXN];
char t[MAXN];
vector<vi> dp, pos;

int z[MAX];
void buildz(char *s) {
	int n = strlen(s);
	z[0] = 0;
	REP (i, 1, n) {
		int j = z[i - 1];
		while (j != 0 && s[j] != s[i]) {
			j = z[j - 1];
		}
		z[i] = j + (s[i] == s[j]);
	}
}
int aut[MAX][MAXC + 5];
void buildaut(char *s) {
	int n = strlen(s);
	REP (i, 0, n + 1) {
		REP (j, 0, MAXC) {
			if (i != 0 && s[i] != j + 'a') {
				aut[i][j] = aut[z[i - 1]][j];
			} else {
				aut[i][j] = i + (s[i] == j + 'a');
			}
		}
	}
}

int main() {
	scanf(" %s", s);
	scanf(" %s", t);
	n = strlen(s); m = strlen(t);
	if (n < m) {
		printf("0\n");
		return 0;
	}
	buildz(t);
	buildaut(t);
	dp.assign(n + 5, vi(m + 5, 0));
	pos.assign(n + 5, vi(m + 5, 0));
	if (s[0] == '?') {
		REP (i, 0, MAXC) {
			int a = aut[0][i];
			pos[0][a] = 1;
			dp[0][a] = a == m;
		}
	} else {
		int a = aut[0][s[0] - 'a'];
		pos[0][a] = 1;
		dp[0][a] = a == m;
	}
	REP (i, 1, n) {
		REP (j, 0, m + 1) {
			if (!pos[i - 1][j]) continue;
			//printf("%d %d:", i, j);
			if (s[i] == '?') {
				REP (c, 0, MAXC) {
					int a = aut[j][c];
					pos[i][a] = 1;
					mxto(dp[i][a], dp[i - 1][j] + (a == m));
					//printf(" %d", a);
				}
				//printf("\n");
			} else {
				int a = aut[j][s[i] - 'a'];
				//printf(" %d\n", a);
				pos[i][a] = 1;
				mxto(dp[i][a], dp[i - 1][j] + (a == m));
			}
		}
	}
	int ans = 0;
	REP (j, 0, m + 1) {
		mxto(ans, dp[n - 1][j]);
	}
	printf("%d\n", ans);
	return 0;
}
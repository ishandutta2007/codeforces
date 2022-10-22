// time-limit: 2000
// problem-url: https://codeforces.com/contest/1622/problem/D

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
#define MOD 998244353
#define MAXN 5005

int n, k;
char s[MAXN];
ll c[MAXN][MAXN];
ll ans;

int main() {
	scanf("%d%d", &n, &k);
	scanf(" %s", s);
	if (k == 0) {
		printf("1\n");
		return 0;
	}
	int cnt = 0;
	REP (i, 0, n) {
		cnt += s[i] == '1';
	}
	if (cnt < k) {
		printf("1\n");
		return 0;
	}
	REP (i, 0, n + 1) {
		c[i][0] = c[i][i] = 1;
		REP (j, 1, i) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
		}
	}
	int prv = 0, pfi = -1;
	REP (i, 0, n) {
		if (s[i] == '0') continue;
		int cnt = 0;
		int id = -1;
		int fi = -1, lst = -1;
		REP (j, i, n) {
			cnt += s[j] == '1';
			if (cnt == k && lst == -1) {
				lst = j - 1;
			} 
			if (cnt == 1 && fi == -1) {
				fi = j + 1;
			}
			if (cnt > k) {
				id = j - 1;
				break;
			}
		}
		if (cnt == k) {
			id = n - 1;
		}
		if (id == -1) {
			break;
		}
		int l = id - prv + 1;
		ans = (ans + c[l][k]) % MOD;
		if (prv != 0) {
			debug("%d: %d %d\n", i, lst, pfi);
			ans = (ans - c[lst - pfi + 1][k - 1] + MOD) % MOD;
		}
		prv = i + 1;
		pfi = fi;
	}
	printf("%lld\n", ans);
	return 0;
}
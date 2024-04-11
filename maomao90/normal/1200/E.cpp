#include <bits/stdc++.h> 
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
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
#define MAX 1000005

struct shash {
	string s;
	vll h[2];
	ll m[2] = {1000000007, 1000000009};
	ll p[2] = {257, 373};
	static ll pw[2][MAX];
	static bool precomp;

	shash() {}
	shash(string s) {
		if (!precomp) {
			doprecomp();
		}
		append(s);
	}
	void append(char a) {
		s += a;
		REP (i, 0, 2) {
			int j = s.size() - 1;
			h[i].pb(0);
			h[i][j] = ((j == 0 ? 0 : h[i][j - 1]) + pw[i][j] * s[j]) % m[i];
		}
	}
	void append(string a) {
		REP (i, 0, a.size()) {
			append(a[i]);
		}
	}
	pll getHash(int l, int r) {
		pll res = MP(0, 0);
		REP (i, 0, 2) {
			ll diff = (h[i][r] - (l == 0 ? 0 : h[i][l - 1]) + m[i]) % m[i];
			diff = diff * pw[i][MAX - l - 1] % m[i];
			if (i == 0) res.FI = diff;
			else res.SE = diff;
		}
		return res;
	}
	void doprecomp() {
		precomp = 1;
		REP (i, 0, 2) {
			pw[i][0] = 1;
			REP (j, 1, MAX) {
				pw[i][j] = pw[i][j - 1] * p[i] % m[i];
			}
		}
	}
};

bool shash::precomp;
ll shash::pw[2][MAX];

int n;
string s[MAXN];
shash sh[MAXN];
shash cur;
string ans;

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		char temp[MAX]; scanf(" %s", &temp);
		s[i] = temp;
	}
	REP (i, 0, n) {
		sh[i] = shash(s[i]);
	}
	ans = s[0];
	cur.append(s[0]);
	REP (i, 1, n) {
		int hi = min(s[i].size(), ans.size()) - 1;
		int prv = -1;
		//printf("%d\n", i);
		RREP (j, hi, 0) {
			bool same = sh[i].getHash(0, j) ==
			   	cur.getHash(ans.size() - j - 1, ans.size() - 1);
			// printf(" %c %c, %c %c\n", s[i][0], s[i][j], ans[ans.size() - j - 1], ans[ans.size() - 1]);
			if (same) {
				prv = j;
				break;
			}
		}
		REP (j, prv + 1, s[i].size()) {
			ans += s[i][j];
			cur.append(s[i][j]);
		}
	}
	printf("%s\n", ans.c_str());
	return 0;
}
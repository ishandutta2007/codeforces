// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;
 
#ifndef DEBUG
#define cerr if (0) cerr
#endif
 
const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 200005;

int t;
int n;
string s;
int psm[MAXN];
vi vec[MAXN];

int solve(int l, int r) {
    if (l > r) {
	return 0;
    }
    //cout << l << ' ' << r << '\n';
    int p = psm[l] - 1;
    auto ptr = upper_bound(ALL(vec[p + n]), l);
    int ans = 1;
    int prv = l;
    while (ptr != vec[p + n].end() && *ptr <= r) {
	//cout << ' ' << prv + 1 << ' ' << *ptr - 1 << '\n';
	ans += solve(prv + 1, *ptr - 1);
	prv = *ptr + 1;
	++ptr;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
	cin >> n;
	cin >> s;
	REP (i, 0, 2 * n) {
	    psm[i] = s[i] == '(' ? 1 : -1;
	    if (i) {
		psm[i] += psm[i - 1];
	    }
	}
	REP (i, 0, 2 * n + 5) {
	    vec[i].clear();
	}
	REP (i, 0, 2 * n) {
	    vec[psm[i] + n].pb(i);
	}
	cout << solve(0, 2 * n - 1) << '\n';
    }
    return 0;
}
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
int n, m;
int a[MAXN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
	cin >> n >> m;
	if (n == 1) {
	    cout << "Yes\n";
	    cout << m << '\n';
	    continue;
	}
	if (n % 2 == 0) {
	    if (m % 2 != 0) {
		cout << "No\n";
		continue;
	    }
	    REP (i, 0, n) {
		a[i] = 1;
	    }
	    a[n - 1] = a[n - 2] = (m - (n - 2)) / 2;
	    if (a[n - 1] <= 0) {
		cout << "No\n";
		continue;
	    }
	} else {
	    REP (i, 0, n) {
		a[i] = 1;
	    }
	    a[n - 1] = (m - (n - 1));
	    if (a[n - 1] <= 0) {
		cout << "No\n";
		continue;
	    }
	}
	cout << "Yes\n";
	REP (i, 0, n) {
	    cout << a[i] << ' ';
	}
	cout << '\n';
    }
    return 0;
}
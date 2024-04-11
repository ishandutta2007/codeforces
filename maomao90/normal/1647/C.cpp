// time-limit: 1000
// problem-url: https://codeforces.com/contest/1647/problem/C

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
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

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 105

int t;
int n, m;
string s[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n >> m;
        REP (i, 0, n) {
            cin >> s[i];
        }
        if (s[0][0] == '1') {
            cout << -1 << '\n';
            continue;
        }
        vector<tuple<int, int, int, int>> ans;
        REP (i, 0, n) {
            RREP (j, m - 1, 1) {
                if (s[i][j] != '1') continue;
                ans.pb(MT(i + 1, j, i + 1, j + 1));
            }
        }
        RREP (i, n - 1, 0) {
            if (s[i][0] != '1') continue;
            ans.pb(MT(i, 1, i + 1, 1));
        }
        cout << ans.size() << '\n';
        for (auto [a, b, c, d] : ans) {
            cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
        }
    }
    return 0;
}
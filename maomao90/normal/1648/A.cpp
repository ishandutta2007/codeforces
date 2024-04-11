// time-limit: 2000
// problem-url: https://codeforces.com/contest/1648/problem/A

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
#define MAXN 100005

int n, m;
vi grid[MAXN];
map<int, int> tot, mp;
ll ans;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> m;
    REP (i, 0, n) {
        grid[i].resize(m);
        REP (j, 0, m) {
            cin >> grid[i][j];
            tot[grid[i][j]]++;
        }
    }
    mp = tot;
    REP (i, 0, n) {
        REP (j, 0, m) {
            ans += (ll) i * (mp[grid[i][j]] - 1);
            ans -= (ll) i * (tot[grid[i][j]] - mp[grid[i][j]]);
            mp[grid[i][j]]--;
        }
    }
    mp = tot;
    REP (i, 0, m) {
        REP (j, 0, n) {
            ans += (ll) i * (mp[grid[j][i]] - 1);
            ans -= (ll) i * (tot[grid[j][i]] - mp[grid[j][i]]);
            mp[grid[j][i]]--;
        }
    }
    cout << -ans << '\n';
    return 0;
}
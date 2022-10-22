// time-limit: 2000
// problem-url: https://codeforces.com/contest/1472/problem/F

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
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
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
map<int, vi> mp;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n >> m;
        mp.clear();
        REP (i, 0, m) {
            int r, c; cin >> r >> c;
            mp[c].pb(r);
        }
        int p = 0, pr = -1;
        bool fit = 1;
        bool pos = 1;
        for (auto [c, v] : mp) {
            if (v.size() == 2) {
                if (!fit) {
                    pos = 0;
                    break;
                }
            } else {
                int r = v[0];
                if (fit) {
                    pr = 3 - r;
                    fit = 0;
                } else {
                    if (r == pr && (c - p) % 2 == 0) {
                        fit = 1;
                    } else if (r != pr && (c - p) % 2 == 1) {
                        fit = 1;
                    } else {
                        pos = 0;
                        break;
                    }
                }
            }
            p = c;
        }
        if (pos && fit) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
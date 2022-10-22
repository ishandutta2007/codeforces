// time-limit: 1000
// problem-url: https://codeforces.com/contest/1685/problem/C

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

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int mn = 0;
        ii mx = {-1, -1};
        REP (i, 0, 2 * n) {
            psm[i] = s[i] == '(' ? 1 : -1;
            if (i) {
                psm[i] += psm[i - 1];
            }
            mnto(mn, psm[i]);
            mxto(mx, ii{psm[i], i});
        }
        int gx = mx.SE;
        if (mn >= 0) {
            cout << 0 << '\n';
            continue;
        }
        int fi = -1, se = -1;
        REP (i, 0, 2 * n) {
            if (psm[i] < 0) {
                if (fi == -1) {
                    fi = i;
                }
                se = i;
            }
        }
        mx = {0, -1};
        RREP (i, fi - 1, 0) {
            mxto(mx, {psm[i], i});
        }
        fi = mx.SE + 1;
        mx = {-1, -1};
        REP (i, se, 2 * n) {
            mxto(mx, {psm[i], i});
        }
        se = mx.SE;
        cerr << fi << ' ' << se << '\n';
        reverse(s.begin() + fi, s.begin() + se + 1);
        mn = 0;
        REP (i, 0, 2 * n) {
            psm[i] = s[i] == '(' ? 1 : -1;
            if (i) {
                psm[i] += psm[i - 1];
            }
            mnto(mn, psm[i]);
        }
        if (mn >= 0) {
            cout << 1 << '\n';
            cout << fi + 1 << ' ' << se + 1 << '\n';
            continue;
        }
        cout << 2 << '\n';
        cout << 1 << ' ' << gx + 1 << '\n';
        cout << gx + 2 << ' ' << 2 * n << '\n';
    }
    return 0;
}
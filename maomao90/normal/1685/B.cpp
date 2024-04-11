// time-limit: 1000
// problem-url: https://codeforces.com/contest/1685/problem/B

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
int a, b, c, d;
string s;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        cin >> s;
        int acnt = 0, bcnt = 0;
        REP (i, 0, SZ(s)) {
            bool b = s[i] == 'A';
            acnt += b;
            bcnt += b ^ 1;
        }
        if (acnt != a + c + d) {
            cout << "NO\n";
            continue;
        }
        assert(bcnt == b + c + d);
        int ab = 0, ba = 0;
        REP (i, 0, SZ(s) - 1) {
            if (s[i] == 'A' && s[i + 1] == 'B') {
                ab++;
            }
        }
        priority_queue<int, vi, greater<int>> bapq;
        priority_queue<int> abpq, xxpq;
        REP (i, 0, SZ(s) - 1) {
            if (i - 1 < 0 || s[i - 1] == s[i]) {
                int k = SZ(s);
                REP (j, i + 1, SZ(s)) {
                    if (s[j] == s[j - 1]) {
                        k = j;
                        break;
                    }
                }
                if (s[i] == s[k - 1]) {
                    xxpq.push(k - i);
                } else if (s[i] == 'A') {
                    abpq.push(k - i);
                } else {
                    bapq.push(k - i);
                }
                i = k - 1;
            }
        }
        while (!bapq.empty()) {
            int x = bapq.top(); bapq.pop();
            int pot = x / 2;
            int mn = min(d - ba, pot);
            ba += mn;
            ab -= mn;
            if (mn == pot) {
                ab++;
            }
            if (ba == d) {
                break;
            }
        }
        if (ba >= d && ab >= c) {
            cout << "YES\n";
            continue;
        }
        while (!xxpq.empty()) {
            int x = xxpq.top(); xxpq.pop();
            int pot = (x - 1) / 2;
            int mn = min(d - ba, pot);
            ba += mn;
            ab -= mn;
            if (ba == d) {
                break;
            }
        }
        if (ba >= d && ab >= c) {
            cout << "YES\n";
            continue;
        }
        while (!abpq.empty()) {
            int x = abpq.top(); abpq.pop();
            int pot = (x - 1) / 2;
            int mn = min(d - ba, pot);
            ba += mn;
            ab -= mn + 1;
            if (ba == d) {
                break;
            }
        }
        if (ba >= d && ab >= c) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}
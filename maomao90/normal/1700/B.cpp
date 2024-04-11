// time-limit: 2000
// problem-url: https://codeforces.com/contest/1700/problem/B

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
int a[MAXN];
int ans[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        int on = n;
        cin >> s;
        REP (i, 0, n) {
            ans[i] = 0;
        }
        REP (i, 0, n) {
            a[i] = s[n - i - 1] - '0';
        }
        a[n] = 0;
        a[n - 1]++;
        ans[n - 1] = 1;
        if (a[n - 1] == 10) {
            a[n - 1] = 0;
            a[n] = 1;
        }
        if (a[n] != 0) {
            REP (i, 0, n) {
                ans[i] = 0;
            }
            REP (i, 0, n) {
                a[i] = s[n - i - 1] - '0';
            }
            a[n] = 0;
            a[n - 1]++;
            ans[n - 1] = 1;
            if (a[n - 1] == 10) {
                a[n - 1] = 0;
                a[n] = 1;
            }
            if (a[0] == 0) {
                a[0]++;
                ans[0]++;
            } else if (a[0] > 1) {
                int d = 11 - a[0];
                a[0] = 1;
                a[1]++;
                ans[0] += d;
            }
            REP (i, 1, n) {
                if (a[i] > 9) {
                    a[i] -= 10;
                    a[i + 1]++;
                }
            }
            n++;
        }
        REP (i, 0, n / 2) {
            int d = abs(a[i] - a[n - i - 1]);
            if (a[i] > a[n - i - 1]) {
                ans[n - i - 1] += d;
            } else {
                ans[i] += d;
            }
        }
        bool pos = 1;
        RREP (i, on - 1, 0) {
            if (ans[i] > 9) {
                pos = 0;
            }
        }
        if (!pos) {
            n = on;
            REP (i, 0, n) {
                ans[i] = 0;
            }
            REP (i, 0, n) {
                a[i] = s[n - i - 1] - '0';
            }
            a[n] = 0;
            a[n - 1]++;
            ans[n - 1] = 1;
            if (a[n - 1] == 10) {
                a[n - 1] = 0;
                a[n] = 1;
            }
            REP (i, 0, n) {
                if (a[i] == 9) {
                    a[i] = 0;
                    a[i + 1]++;
                    ans[i] = 1;
                } else if (a[i] > 9) {
                    a[i] -= 10;
                    a[i + 1]++;
                }
            }
            if (a[n] != 0) {
                REP (i, 0, n) {
                    ans[i] = 0;
                }
                REP (i, 0, n) {
                    a[i] = s[n - i - 1] - '0';
                }
                a[n] = 0;
                a[n - 1]++;
                ans[n - 1] = 1;
                if (a[n - 1] == 10) {
                    a[n - 1] = 0;
                    a[n] = 1;
                }
                if (a[0] == 0) {
                    a[0]++;
                    ans[0]++;
                } else if (a[0] > 1) {
                    int d = 11 - a[0];
                    a[0] = 1;
                    a[1]++;
                    ans[0] += d;
                }
                REP (i, 1, n) {
                    if (a[i] == 9) {
                        a[i] = 0;
                        a[i + 1]++;
                        ans[i] = 1;
                    } else if (a[i] > 9) {
                        a[i] -= 10;
                        a[i + 1]++;
                    }
                }
                n++;
            }
            REP (i, 0, n / 2) {
                int d = abs(a[i] - a[n - i - 1]);
                if (a[i] > a[n - i - 1]) {
                    ans[n - i - 1] += d;
                } else {
                    ans[i] += d;
                }
            }
            if (ans[on - 1] == 0) {
                ans[on - 1]++;
                if (n - on != on - 1) {
                    ans[n - on]++;
                }
            }
        }
        RREP (i, on - 1, 0) {
            assert(ans[i] <= 9);
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}
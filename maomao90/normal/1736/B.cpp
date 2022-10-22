// time-limit: 1000
// problem-url: https://codeforces.com/contest/1736/problem/B

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
int a[MAXN];
int b[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 0, n) {
            cin >> a[i];
        }
        b[0] = a[0];
        REP (i, 1, n) {
            for (int j = a[i]; ; j += a[i]) {
                if (j % a[i - 1] == 0) {
                    b[i] = j;
                    break;
                }
            }
        }
        b[n] = a[n - 1];
        bool pos = 1;
        REP (i, 0, n) {
            if (__gcd(b[i], b[i + 1]) != a[i]) {
                pos = 0;
                break;
            }
        }
        if (pos) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
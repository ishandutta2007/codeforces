// time-limit: 1000
// problem-url: https://codeforces.com/contest/1685/problem/A

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
int a[MAXN], b[MAXN];

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
        sort(a, a + n);
        if (n % 2 == 3) {
            cout << "NO\n";
        }
        REP (i, 0, n / 2) {
            b[i * 2] = a[i];
        }
        REP (i, 0, n / 2) {
            b[i * 2 + 1] = a[i + n / 2];
        }
        bool pos = 1;
        REP (i, 0, n) {
            int prv = i == 0 ? n - 1 : i - 1;
            int nxt = (i + 1) % n;
            if (b[prv] < b[i] && b[i] > b[nxt]) {
                continue;
            }
            if (b[prv] > b[i] && b[i] < b[nxt]) {
                continue;
            }
            pos = 0;
            break;
        }
        if (pos) {
            cout << "YES\n";
            REP (i, 0, n) {
                cout << b[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
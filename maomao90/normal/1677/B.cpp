// time-limit: 1000
// problem-url: https://codeforces.com/contest/1677/problem/B

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
const int MAXN = 1000005;

int t;
int n, m;
string s;
bool used[MAXN];
int ans[MAXN];
vector<vi> psm;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin >> s;
        REP (i, 0, m + 5) {
            used[i] = 0;
        }
        int cur = 0;
        REP (i, 0, n) {
            REP (j, 0, m) {
                int id = i * m + j;
                if (s[id] == '1') {
                    if (!used[j]) {
                        used[j] = 1;
                        cur++;
                    }
                }
                ans[id] = cur;
            }
        }
        psm.clear();
        psm.resize(n);
        REP (i, 0, n) {
            psm[i] = vi(m, 0);
        }
        int p = -INF;
        REP (i, 0, n * m) {
            if (s[i] == '0') continue;
            p = i - p;
            REP (j, max(0, m - p), m) {
                if (i + j >= n * m) {
                    break;
                }
                assert((p + j) / m != 0);
                psm[(i + j) / m][(i + j) % m]++;
            }
            p = i;
        }
        REP (i, 0, n) {
            REP (j, 0, m) {
                if (i) {
                    psm[i][j] += psm[i - 1][j];
                }
                ans[i * m + j] += psm[i][j];
            }
        }
        REP (i, 0, n * m) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
// time-limit: 1000
// problem-url: https://codeforces.com/contest/1296/problem/E2

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

int n;
string s;
bool has[30][30], tmp[30];
int col[MAXN];
int ans;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    cin >> s;
    REP (i, 0, n) {
        REP (k, 0, 26) {
            tmp[k] = 0;
        }
        REP (j, s[i] - 'a' + 1, 26) {
            REP (k, 0, 26) {
                tmp[k] |= has[j][k];
            }
        }
        int id = -1;
        REP (k, 0, 26) {
            if (tmp[k] == 0) {
                id = k;
                break;
            }
        }
        assert(id != -1);
        col[i] = id;
        has[s[i] - 'a'][id] = 1;
        mxto(ans, id);
    }
    cout << ans + 1 << '\n';
    REP (i, 0, n) {
        cout << col[i] + 1 << ' ';
    }
    cout << '\n';
    return 0;
}
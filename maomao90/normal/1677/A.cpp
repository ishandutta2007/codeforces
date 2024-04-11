// time-limit: 1500
// problem-url: https://codeforces.com/contest/1677/problem/A

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
const int MAXN = 5005;

int t;
int n;
int p[MAXN];

int fw[MAXN];
void incre(int i, int x) {
    for (; i <= n; i += i & -i) fw[i] += x;
}
int qry(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) res += fw[i];
    return res;
}
int qry(int s, int e) {
    return qry(e) - qry(s - 1);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 0, n) {
            cin >> p[i];
        }
        memset(fw, 0, sizeof fw);
        RREP (i, n - 1, 2) {
            incre(p[i], 1);
        }
        ll ans = 0;
        REP (c, 2, n) {
            incre(p[c], -1);
            int lft = p[0] < p[c];
            REP (b, 1, c) {
                int rht = qry(p[b] - 1);
                ans += lft * rht;
                cerr << b << ' ' << c << ": " << lft << ' ' << rht << '\n';
                if (p[b] < p[c]) {
                    lft++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
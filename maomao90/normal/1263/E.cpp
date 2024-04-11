// time-limit: 1000
// problem-url: https://codeforces.com/contest/1263/problem/E

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

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 1000005

int n;
string s;
char t[MAXN];

#define MLR int mid = lo + hi >> 1; int lc = u << 1, rc = u << 1 ^ 1
int mn[MAXN * 4], mx[MAXN * 4], lz[MAXN * 4];
void propo(int u, int lo, int hi) {
    if (lo == hi || lz[u] == 0) {
        return;
    }
    MLR;
    lz[lc] += lz[u];
    mn[lc] += lz[u];
    mx[lc] += lz[u];
    lz[rc] += lz[u];
    mn[rc] += lz[u];
    mx[rc] += lz[u];
    lz[u] = 0;
}
void incre(int s, int e, int x, int u = 1, int lo = 0, int hi = n - 1) {
    if (s <= lo && hi <= e) {
        lz[u] += x;
        mn[u] += x;
        mx[u] += x;
        return;
    }
    propo(u, lo, hi);
    MLR;
    if (s <= mid) {
        incre(s, e, x, lc, lo, mid);
    }
    if (e > mid) {
        incre(s, e, x, rc, mid + 1, hi);
    }
    mn[u] = min(mn[lc], mn[rc]);
    mx[u] = max(mx[lc], mx[rc]);
}
int qry(int p, int u = 1, int lo = 0, int hi = n - 1) {
    if (lo == hi) {
        return mx[u];
    }
    propo(u, lo, hi);
    MLR;
    if (p <= mid) {
        return qry(p, lc, lo, mid);
    } else {
        return qry(p, rc, mid + 1, hi);
    }
}

void revert(int i) {
    if (t[i] == '(') {
        incre(i, n - 1, -1);
    } else if (t[i] == ')') {
        incre(i, n - 1, 1);
    }
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    cin >> s;
    int j = 0;
    REP (i, 0, n) {
        if (s[i] == '(') {
            revert(j);
            incre(j, n - 1, 1);
            t[j] = '(';
        } else if (s[i] == ')') {
            revert(j);
            incre(j, n - 1, -1);
            t[j] = ')';
        } else if (s[i] == 'R') {
            j++;
        } else if (s[i] == 'L') {
            j--;
            if (j < 0) {
                j = 0;
            }
        } else {
            revert(j);
            t[j] = s[i];
        }
        if (mn[1] < 0 || qry(n - 1) != 0) {
            cout << -1 << ' ';
            continue;
        }
        cout << mx[1] << ' ';
    }
    cout << '\n';
    return 0;
}
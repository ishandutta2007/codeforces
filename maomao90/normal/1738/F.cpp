// time-limit: 2000
// problem-url: https://codeforces.com/contest/1738/problem/F

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
int d[MAXN];
bool done[MAXN];

int ask(int u) {
    cout << "? " << u << endl;
    int x; cin >> x;
    return x;
}

int cp;
int p[MAXN], rnk[MAXN], c[MAXN];
int findp(int u) {
    if (p[u] == u) return u;
    return p[u] = findp(p[u]);
}
bool join(int a, int b) {
    int pa = findp(a), pb = findp(b);
    if (pa == pb) {
        return 0;
    }
    c[pa] = c[pb];
    if (rnk[pa] < rnk[pb]) swap(pa, pb);
    if (rnk[pa] == rnk[pb]) rnk[pa]++;
    p[pb] = pa;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 1, n + 1) {
            cin >> d[i];
        }
        vi id(n, 0);
        iota(ALL(id), 1);
        sort(ALL(id), [&] (int l, int r) {
                return d[l] > d[r];
                });
        REP (i, 1, n + 1) {
            p[i] = i;
            rnk[i] = 0;
            c[i] = 0;
            done[i] = 0;
        }
        cp = 1;
        int u = id[0];
        for (int u : id) {
            if (done[u]) {
                continue;
            }
            c[u] = cp++;
            done[u] = 1;
            REP (k, 0, d[u]) {
                int v = ask(u);
                if (done[v]) {
                    join(u, v);
                    break;
                }
                join(v, u);
                done[v] = 1;
            }
        }
        cout << "!";
        REP (i, 1, n + 1) {
            cout << ' ' << c[findp(i)];
        }
        cout << endl;
    }
    return 0;
}
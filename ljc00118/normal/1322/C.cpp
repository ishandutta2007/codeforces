#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 5e5 + 5;

vector <int> adj[N];
vector < pair <vector <int>, ll> > g[N];
ll c[N], ans;
int T, n, m;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    srand(time(0));
    read(T);
    while (T--) {
        read(n); read(m);
        for (int i = 1; i <= n; i++) read(c[i]), adj[i].clear(), g[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            read(u); read(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            sort(adj[i].begin(), adj[i].end());
            g[adj[i].size()].push_back(make_pair(adj[i], c[i]));
        }
        ans = 0;
        for (int i = 1; i <= n; i++) {
            sort(g[i].begin(), g[i].end());
            for (int l = 0, r; l < (int)g[i].size(); l = r + 1) {
                r = l; ll sum = g[i][l].second;
                while (r + 1 < (int)g[i].size() && g[i][l].first == g[i][r + 1].first) ++r, sum += g[i][r].second;
                ans = gcd(ans, sum);
            }
        }
        print(ans, '\n');
    }
    return 0;
}
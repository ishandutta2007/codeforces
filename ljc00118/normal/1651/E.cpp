#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 3005;

vector <int> adj[N];
int u[N], v[N], vis[N], seq[N];
int n; ll ans;

int s2(int n) { return n * (n + 1) / 2; }

void solve() {
    for (int i = 1; i <= n * 2; i++) adj[i].clear();
    for (int i = 1; i <= n * 2; i++) {
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    for (int i = 1; i <= n; i++) {
        int l = adj[i][0] - n, r = adj[i][1] - n;
        if (l > r) swap(l, r);
        int x = i * (n - i + 1), y = s2(n) - s2(l - 1) - s2(r - l - 1) - s2(n - r);
        ans += 1ll * x * y;
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        seq[1] = i;
        seq[2] = adj[i][0];
        int len = 2;
        while (seq[len] != i) {
            vis[seq[len]] = 1;
            for (auto v : adj[seq[len]]) {
                if (v != seq[len - 1]) {
                    seq[++len] = v;
                    break;
                }
            }
        }
        --len;
        // for (int j = 1; j <= len; j++) cout << seq[j] << " ";
        // cout << endl;
        for (int j = 2; j <= len; j += 2) seq[j] -= n;
        for (int j = 1; j <= len; j += 2) {
            int l1 = seq[j], r1 = seq[j], l2 = n, r2 = 0;
            for (int k = 1; k <= len / 2 - 1; k++) {
                // fprintf(stderr, "j = %d, k = %d\n", j, k);
                int x = (j + k * 2 - 2) % len + 1;
                l2 = min(l2, seq[x]); r2 = max(r2, seq[x]);
                x = (x == len ? 1 : x + 1);
                l1 = min(l1, seq[x]); r1 = max(r1, seq[x]);
                ++x;
                int y = (j == 1 ? len : j - 1);
                // fprintf(stderr, "l1 = %d, r1 = %d, l2 = %d, r2 = %d, seq[x] = %d, seq[y] = %d, x = %d, y = %d\n", l1, r1, l2, r2, seq[x], seq[y], x, y);
                if ((seq[x] >= l2 && seq[x] <= r2) || (seq[y] >= l2 && seq[y] <= r2)) continue;
                ll res = l1 * (n - r1 + 1);
                {
                    int lim = 0;
                    if (seq[x] < l2) lim = max(lim, seq[x]);
                    if (seq[y] < l2) lim = max(lim, seq[y]);
                    res *= (l2 - lim);
                }
                {
                    int lim = n + 1;
                    if (seq[x] > r2) lim = min(lim, seq[x]);
                    if (seq[y] > r2) lim = min(lim, seq[y]);
                    res *= (lim - r2);
                }
                // fprintf(stderr, "res = %lld\n", res);
                ans -= res;
            }
        }
    }
}

int main() {
    read(n);
    for (int i = 1; i <= n * 2; i++) {
        read(u[i]); read(v[i]);
    }
    solve();
    for (int i = 1; i <= n * 2; i++) {
        u[i] = n * 2 - u[i] + 1;
        v[i] = n * 2 - v[i] + 1;
    }
    solve();
    print(ans / 2, '\n');
    return 0;
}
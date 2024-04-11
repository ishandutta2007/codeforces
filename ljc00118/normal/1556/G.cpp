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

const int N = 2e5 + 5;

vector <int> adj[N];
ll a[N], b[N], l[N], r[N];
int opt[N], id[N], ban[N], f[N], ans[N];
char c[10];
int n, m, len;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

bool cmp(int i, int j) { return l[i] < l[j]; }

void add(ll L, ll R, int _ban) {
    for (int i = n; i >= 0; i--) {
        if (((R + 1) >> i) != (L >> i)) {
            ll pos = (((R + 1) >> i) << i) - 1;
            ++len; l[len] = L; r[len] = pos; ban[len] = _ban;
            if (pos != R) {
                ++len;
                l[len] = pos + 1;
                r[len] = R;
                ban[len] = _ban;
            }
            break;
        }
    }
}

void insert(int u) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (!ban[v]) {
            f[find(u)] = find(v);
            // fprintf(stderr, "u = %d, v = %d\n", u, v);
        }
    }
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        scanf("%s", c + 1); read(a[i]); read(b[i]);
        opt[i] = (c[1] == 'a');
        if (opt[i] == 0) {
            ++len;
            l[len] = a[i]; r[len] = b[i];
        }
    }
    {
        static ll tl[N], tr[N], tlen;
        for (int i = 1; i <= len; i++) id[i] = i;
        sort(id + 1, id + len + 1, cmp);
        for (int i = 1; i <= len; i++) {
            tl[i] = l[id[i]];
            tr[i] = r[id[i]];
        }
        tlen = len; len = 0;
        tr[0] = -1;
        for (int i = 1; i <= tlen; i++) {
            if (tr[i - 1] + 1 <= tl[i] - 1) {
                add(tr[i - 1] + 1, tl[i] - 1, 0);
            }
            add(tl[i], tr[i], 1);
        }
        if (tr[tlen] != (1ll << n) - 1) add(tr[tlen] + 1, (1ll << n) - 1, 0);
    }
    for (int bit = 0; bit < n; bit++) {
        for (int i = 1, j = 1; i <= len; i++) {
            ll pos = -1;
            if ((l[i] >> bit) & 1) pos = l[i];
            else pos = ((l[i] >> bit) + 1) << bit;
            if (l[i] <= pos && pos <= r[i]) {
                while (pos - (1ll << bit) > r[j]) ++j;
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        for (int i = 1, j = 1; i <= len; i++) {
            ll pos = -1;
            if (((l[i] >> bit) & 1) == 0) pos = l[i];
            else pos = ((l[i] >> bit) + 1) << bit;
            if (l[i] <= pos && pos <= r[i]) {
                while (pos + (1ll << bit) > r[j]) ++j;
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= len; i++) f[i] = i;
    for (int i = 1; i <= len; i++) {
        if (!ban[i]) {
            insert(i);
        }
    }
    // for (int i = 1; i <= len; i++) {
    //     fprintf(stderr, "l[%d] = %lld, r[%d] = %lld, ban[%d] = %d\n", i, l[i], i, r[i], i, ban[i]);
    // }
    for (int i = m; i >= 1; i--) {
        if (opt[i] == 0) {
            int pos = lower_bound(r + 1, r + len + 1, b[i]) - r;
            while (pos && l[pos] >= a[i]) {
                ban[pos] = 0;
                insert(pos);
                --pos;
            }
        }
        if (opt[i] == 1) {
            int p1 = lower_bound(r + 1, r + len + 1, a[i]) - r;
            int p2 = lower_bound(r + 1, r + len + 1, b[i]) - r;
            // fprintf(stderr, "p1 = %d, p2 = %d\n", p1, p2);
            if (find(p1) == find(p2)) ans[i] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (opt[i] == 1) {
            print(ans[i], '\n');
        }
    }
    return 0;
}
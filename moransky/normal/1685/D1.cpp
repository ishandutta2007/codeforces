// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}


const int N = 205;

// 
struct DSU{
    int f[N], sz[N];
    void init(int n) { for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1; }
    int inline find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    void inline merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x, y);
        sz[y] += sz[x], f[x] = y;
    }
} t;


int n, p[N], a[N], lp[N], pos[N];

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(p[i]), lp[i] = p[i];
        t.init(n);
        for (int i = 1; i <= n; i++) t.merge(i, p[i]);
        int ct = 0;
        for (int i = 1; i <= n; i++) if (t.find(i) == i) ct++;
        while (1) {
            bool o = 0;
            t.init(n);
            for (int i = 1; i <= n; i++) t.merge(i, p[i]), pos[p[i]] = i;
            for (int i = 1; i < n; i++) {
                if (t.find(i) != t.find(i + 1)) {
                    o = 1;
                    int A = pos[i], B = pos[i + 1];
                    swap(p[A], p[B]);
                    break;
                }
            }
            if (!o) break;
        }
        a[n] = 1;
        int t = 0;
        for (int i = 1; i <= n; i++)
            t += abs(p[i] - lp[i]);
        //cout << t <<"??\n";
        assert(t == 2 * (ct - 1));
        for (int i = n - 1; i; i--)
            a[i] = p[a[i + 1]];
        for (int i = 1; i <= n; i++) printf("%d ", a[i]);
        puts("");
    }
    return 0;
}
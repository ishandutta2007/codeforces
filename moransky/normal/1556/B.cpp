// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, a[N], c[N], p[N];

LL ans = 9e18;

void inline add(int x, int k) {
    for (; x <= n; x += x & -x) c[x] += k;
}

int inline ask(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += c[x];
    return res;
}

vector<int> d[2];

void inline get() {
    LL res = 0;
    for (int i = n; i; i--) {
        res += ask(p[i]);
        add(p[i], 1);
    }
    for (int i = 1; i <= n; i++) c[i] = 0;
    chkMin(ans, res);
}

void inline w0() { 
    int v = 0;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (!v) p[i] = d[0][x++];
        else p[i] = d[1][y++];
        v ^= 1;
    }
    get();
}

void inline w1() {
    int v = 1;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (!v) p[i] = d[0][x++];
        else p[i] = d[1][y++];
        v ^= 1;
    }
    get();
}
 
int main() {
    int T; read(T);
    while (T--) {
        read(n); d[0].clear(), d[1].clear(); ans = 9e18;
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            d[a[i] & 1].pb(i);
        }
        int s1 = d[0].size(), s2 = d[1].size();
        if (abs(s1 - s2) > 1) puts("-1");
        else {
            if (d[0].size() == d[1].size()) {
                w0(), w1();
            } else if (d[0].size() > d[1].size()){
                w0();
            } else {
                w1();
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
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

typedef pair<LL, int> PLI;

const int N = 1e4 + 5, P = 1e9 + 7;

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}

int k, inv[N];

LL n;
 
vector<PLI> d;

void inline preInv(int n) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = ((LL)P - P / i) * inv[P % i] % P;
}

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

void inline div(LL x) {
    for (LL i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int c = 0;
            while (x % i == 0) x /= i, c++;
            d.pb(mp(i, c));
        }
    }
    if (x > 1) d.pb(mp(x, 1));
}

int f[51][N];

int inline calc(LL x, int p) {
    int o = x % P;
    f[p][k] = 1;
    int res = 0;
    for (int i = p; i >= 0; i--) {
        for (int j = k; j >= 0; j--) {
            for (int x = i; x <= p; x++) {
                add(f[i][j], 1ll * f[x][j + 1] * inv[x + 1] % P);
            }
        }
        add(res, 1ll * f[i][0] * power(o, i) % P);
    }
   for (int i = 0; i <= p; i++)
        for (int j = 0; j <= k; j++) f[i][j] = 0;
    return res;
}

int main() {
    preInv(1e4);
    read(n), read(k);
    div(n);
    int ans = 1;
    for (PLI t: d) ans = 1ll * ans * calc(t.fi, t.se) % P;
    printf("%d\n", ans);
    return 0;
}
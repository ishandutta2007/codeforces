#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (int i = 0; s[i]; ++i) putchar(s[i]); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const ll maxn = 1010, mod = 998244353;
ll n, m, a[maxn], deg[maxn];
typedef vector <pll> vp;
vp b[maxn];
ll fix(ll x) {
    while (x > mod * 2) x -= mod;
    return x;
}
vi e[maxn];

void work() {
    read(n, m);
    for (int i = 1; i <= n; ++i) read(a[i]), b[i].push_back({0, a[i]});
    for (int i = 1; i <= m; ++i) {
        int x, y; read(x, y);
        e[x].push_back(y), deg[y]++;
    }
    queue <int> q;
    for (int i = 1; i <= n; ++i) if (!deg[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vp vec;
        sort(b[u].begin(), b[u].end());
        for (pll p : b[u])
            if (vec.size() && vec.back().fir + vec.back().sec >= p.fir)
                vec.back().sec = fix(vec.back().sec += p.sec);
            else vec.push_back(p);
        b[u] = vec;
        for (int v : e[u]) {
            for (pll p : vec) b[v].emplace_back(p.fir + 1, p.sec);
            if (--deg[v] == 0) q.push(v);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (!e[i].size()) {
            ll ans = (b[i].back().fir + b[i].back().sec) % mod;
            if (!b[i].back().sec) ans = 0;
            write(ans, '\n');
        }
    for (int i = 1; i <= n; ++i)
        deg[i] = 0, b[i].resize(0), e[i].resize(0);
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}
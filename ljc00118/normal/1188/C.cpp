#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() { *this = hash_map_t(mod); }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 1005, md = 998244353;

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += md;
    return x;
}

int f[N][N], s[N][N];
int a[N], now[N], Ans[(int)1e5 + 5];
int n, k, ans, last;

int main() {
    read(n); read(k);
    for(register int i = 1; i <= n; i++) read(a[i]), now[i] = i - 1;
    sort(a + 1, a + n + 1);
    for(register int i = 1; i <= 1e5; i++) {
        for(register int j = 1; j <= n; j++) while(now[j] && a[j] - a[now[j]] < i) --now[j];
        for(register int j = 1; j <= n; j++) {
            for(register int t = 0; t <= k; t++) {
                f[j][t] = s[j][t] = 0;
            }
        }
        int sum = 0;
        for(register int j = 0; j <= n; j++) s[j][0] = 1;
        for(register int j = 1; j <= n; j++) {
            for(register int t = 1; t <= k; t++) {
                f[j][t] = s[now[j]][t - 1];
                s[j][t] = add(s[j - 1][t], f[j][t]);
            }
        }
        for(register int j = 1; j <= n; j++) sum = add(sum, f[j][k]);
        if(!sum) break;
        Ans[i] = sum;
    }
    for(register int i = 1; i < 1e5; i++) Ans[i] = sub(Ans[i], Ans[i + 1]);
    for(register int i = 1; i <= 1e5; i++) ans = add(ans, 1ll * Ans[i] * i % md);
    print(ans, '\n');
    return 0;
}
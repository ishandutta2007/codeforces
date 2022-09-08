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
 
const int md = 998244353;
 
inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}
 
inline int mul(int x, int y) { return 1ll * x * y % md; }
 
set <ll> f[15][65][65];
int dp[65][65][65], val[65][65];
char c[15];
int a[15];
int n, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
 
inline int calc(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a';
    if(c >= 'A' && c <= 'Z') return c - 'A' + 26;
    return c - '0' + 52;
}
 
inline int calc(int a, int b, int c) {
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);
    return dp[a][b][c];
}
 
int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        scanf("%s", c + 1);
        int len = strlen(c + 1);
        ll now = 0, fac = 1;
        for(register int j = 2; j <= len - 1; j++) {
            now += calc(c[j]) * fac;
            fac *= 62;
        }
        f[len][calc(c[1])][calc(c[len])].insert(now);
        ll las = now; now = 0; fac = 1;
        for(register int j = len - 1; j >= 2; j--) {
            now += calc(c[j]) * fac;
            fac *= 62;
        }
        if(now != las || c[1] != c[len]) f[len][calc(c[len])][calc(c[1])].insert(now);
    }
    for(register int i = 3; i <= 10; i++) {
        for(register int j = 0; j <= 61; j++) {
            for(register int k = 0; k <= 61; k++) {
                val[j][k] = (int)f[i][j][k].size();
            }
        }
        memset(dp, 0, sizeof(dp));
        for(register int a = 0; a <= 61; a++) {
            for(register int b = 0; b <= 61; b++) {
                for(register int c = b; c <= 61; c++) {
                    for(register int d = c; d <= 61; d++) {
                        dp[b][c][d] = add(dp[b][c][d], mul(val[a][b], mul(val[a][c], val[a][d])));
                    }
                }
            }
        }
        for(register int a = 0; a <= 61; a++) {
            for(register int b = a + 1; b <= 61; b++) {
                for(register int c = b + 1; c <= 61; c++) {
                    for(register int d = c + 1; d <= 61; d++) {
                        sum1 = add(sum1, mul(mul(calc(a, b, c), calc(a, b, d)), mul(calc(a, c, d), calc(b, c, d))));
                    }
                }
            }
        }
        for(register int a = 0; a <= 61; a++) {
            for(register int b = a + 1; b <= 61; b++) {
                for(register int c = b + 1; c <= 61; c++) {
                    register int d = a;
                    sum2 = add(sum2, mul(mul(calc(a, b, c), calc(a, b, d)), mul(calc(a, c, d), calc(b, c, d))));
                    d = b;
                    sum2 = add(sum2, mul(mul(calc(a, b, c), calc(a, b, d)), mul(calc(a, c, d), calc(b, c, d))));
                    d = c;
                    sum2 = add(sum2, mul(mul(calc(a, b, c), calc(a, b, d)), mul(calc(a, c, d), calc(b, c, d))));
                }
            }
        }
        for(register int a = 0; a <= 61; a++) {
            for(register int b = a + 1; b <= 61; b++) {
                register int c = a, d = a;
                sum3 = add(sum3, mul(mul(calc(a, b, c), calc(a, b, d)), mul(calc(a, c, d), calc(b, c, d))));
                d = b;
                sum5 = add(sum5, mul(mul(calc(a, b, c), calc(a, b, d)), mul(calc(a, c, d), calc(b, c, d))));
                c = b;
                sum3 = add(sum3, mul(mul(calc(a, b, c), calc(a, b, d)), mul(calc(a, c, d), calc(b, c, d))));
            }
        }
        for(register int a = 0; a <= 61; a++) {
            register int b = a, c = a, d = a;
            sum4 = add(sum4, mul(mul(calc(a, b, c), calc(a, b, d)), mul(calc(a, c, d), calc(b, c, d))));
        }
    }
    print((1ll * sum1 * 24 + 1ll * sum2 * 12 + 1ll * sum3 * 4 + sum4 + 1ll * sum5 * 6) % md, '\n');
    return 0;
}
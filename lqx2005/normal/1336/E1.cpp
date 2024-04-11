#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int LG = 35, N = 10, P = 998244353;
int n, m, tot = 0;
LL lb[LG], base[LG];
int ans[LG + 5];
int f[LG + 5][1 << N], g[LG + 5][1 << N], h[LG + 5][1 << N];

int qpow(int a, int b, int c = 1) {for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) c = 1ll * c * a % P; return c; } 

void ins(LL x) {
    for(int i = m - 1; i >= 0; i--) {
        if(!(x >> i & 1)) continue;
        if(lb[i]) x ^= lb[i];
        else return void(lb[i] = x);
    }
    return;
}

void prework() {
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            if(lb[j] >> i & 1) {
                lb[j] ^= lb[i];
            }
        }
    }
    tot = 0;
    for(int i = 0; i < m; i++) if(lb[i]) base[tot++] = lb[i];
    return;
}

void FWT(int *f, int n, int t) {
    for(int i = 2; i <= n; i <<= 1) {
        for(int j = 0; j < n; j += i) {
            for(int k = 0; k < (i >> 1); k++) {
                int x = f[j + k], y = f[j + k + (i >> 1)];
                f[j + k] = (x + y) % P, f[j + k + (i >> 1)] = (x - y + P) % P;
            }
        }
    }
    if(t == -1) {
        int ivn = qpow(n, P - 2);
        for(int i = 0; i < n; i++) f[i] = 1ll * f[i] * ivn % P;
    }
    return;
}

void dfs(int now, LL msk) {
    if(now == tot) {
        ans[__builtin_popcountll(msk)]++;
        return;
    }
    dfs(now + 1, msk);
    dfs(now + 1, msk ^ base[now]);
    return;
}

void main1() {
    dfs(0, 0);
    return;   
}

void dfs1(int now, int msk, int cnt) {
    if(now == tot / 2) return f[cnt][msk]++, void();
    dfs1(now + 1, msk, cnt);
    dfs1(now + 1, msk ^ base[now], cnt + 1);
    return;
}

void dfs2(int now, int msk, int cnt) {
    if(now == tot) return g[cnt][msk]++, void();
    dfs2(now + 1, msk, cnt);
    dfs2(now + 1, msk ^ base[now], cnt + 1);
    return;
}

void main2() {
    for(int i = 0; i < tot; i++) {
        int msk = 0;
        for(int j = m - 1; j >= 0; j--) if(!lb[j]) msk = (msk << 1) | (base[i] >> j & 1);
        base[i] = msk;
    }
    dfs1(0, 0, 0), dfs2(tot / 2, 0, 0);
    for(int i = 0; i <= tot / 2; i++) FWT(f[i], 1 << (m - tot), 1);
    for(int i = 0; i <= tot - tot / 2; i++) FWT(g[i], 1 << (m - tot), 1);
    for(int i = 0; i <= tot / 2; i++) {
        for(int j = 0; j <= tot - tot / 2; j++) {
            for(int k = 0; k < (1 << (m - tot)); k++) {
                (h[i + j][k] += 1ll * f[i][k] * g[j][k] % P) %= P;
            }
        }
    }
    for(int i = 0; i <= m; i++) {
        FWT(h[i], (1 << (m - tot)), -1);
        for(int j = 0; j < (1 << (m - tot)); j++) {
            int c = __builtin_popcount(j);
            (ans[c + i] += h[i][j]) %= P;
        }
    }
    return;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        LL x;
        scanf("%lld", &x);
        ins(x);
    }
    prework();
    if(tot <= 25) main1();
    else main2();
    int pw2 = qpow(2, n - tot);
    for(int i = 0; i <= m; i++) ans[i] = 1ll * ans[i] * pw2 % P;
    for(int i = 0; i <= m; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;   
}
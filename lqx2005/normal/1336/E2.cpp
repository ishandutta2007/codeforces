#include <bits/stdc++.h>
#define LL long long
#define _cnt(x) (int)__builtin_popcountll(x)
using namespace std;
const int LG = 53, P = 998244353;
int n, m, tot = 0;
int C[LG + 5][LG + 5];
LL A[LG], B[LG], base[LG];
int ans[LG + 5], cnt[LG + 5];

int qpow(int a, int b, int c = 1) {for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) c = 1ll * c * a % P; return c; } 

void ins(LL x) {
    for(int i = m - 1; i >= 0; i--) {
        if(!(x >> i & 1)) continue;
        if(A[i]) x ^= A[i];
        else return void(A[i] = x);
    }
    return;
}

void init(LL A[], LL base[]) {
    tot = 0;
    for(int i = 0; i < m; i++) if(A[i]) base[tot++] = A[i];
    return;
}

void prework() {
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            if(A[j] >> i & 1) {
                A[j] ^= A[i];
            }
        }
    }
    tot = 0;
    for(int i = 0; i < m; i++) {
        if(A[i]) continue;
        B[tot] |= (1ll << i);
        for(int j = 0; j < m; j++) if(A[j]) B[tot] |= ((A[j] >> i & 1) << j);
        tot++;
    }
    return;
}

void dfs(int now, LL msk) {
    if(now == tot) {
        cnt[_cnt(msk)]++;
        return;
    }
    dfs(now + 1, msk);
    dfs(now + 1, msk ^ base[now]);
    return;
}

void main1() {
    dfs(0, 0);
    for(int i = 0; i <= m; i++) ans[i] = cnt[i];
    return;   
}

void main2() {
    prework();
    init(B, base);
    dfs(0, 0);
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k <= j; k++) {
                int tmp = 1ll * C[i][k] * C[m - i][j - k] % P * cnt[i] % P;
                if(k & 1) tmp = (P - tmp) % P;
                (ans[j] += tmp) %= P;
            }
        }
    }
    int ipw = qpow(qpow(2, tot), P - 2);
    for(int i = 0; i <= m; i++) ans[i] = 1ll * ans[i] * ipw % P;
    return;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= m; i++) C[i][0] = 1;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
        }
    }
    for(int i = 1; i <= n; i++) {
        LL x;
        scanf("%lld", &x);
        ins(x);
    }
    init(A, base);
    int pw2 = qpow(2, n - tot);
    if(tot <= 27) main1();
    else main2();
    for(int i = 0; i <= m; i++) ans[i] = 1ll * ans[i] * pw2 % P;
    for(int i = 0; i <= m; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;   
}
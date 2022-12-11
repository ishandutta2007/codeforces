// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 200010, maxm = 500010;

#define lowbit(x) ((x)&(-(x)))

int n, m, u, t, pn, max, sqn;
int a[maxn], b[maxn], miu[maxm], pri[maxn], spl[maxn][10], cnt[maxm], lg2[maxm], sum[maxm];
bool use[maxn], vis[maxm];
ll ans;

void init() {
    
    for (int i = 0; i < 10; i++)
        lg2[1 << i] = i;
    
    miu[1] = 1;
    for (int i = 2; i <= max; i++) {
        if (!vis[i]) {
            pri[++pri[0]] = i;
            if (i <= sqn) pn = pri[0];
            miu[i] = -1;
        }
        for (int j = 1; j <= pri[0] && i * pri[j] <= max; j++) {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) break;
            miu[i * pri[j]] = -miu[i];
        }
    }
    
}

void add(int u) {
//	printf("add => %d\n", u);
    sum[0] = 1;
    ans += cnt[1], cnt[1]++;
    for (int i = 1; i < (1 << spl[u][0]); i++) {
        sum[i] = sum[i ^ lowbit(i)] * spl[u][lg2[lowbit(i)] + 1];
//		printf("> %d\n", sum[i]);
        ans += cnt[sum[i]] * miu[sum[i]];
        cnt[sum[i]]++;
    }
}

void del(int u) {
//	printf("del => %d\n", u);
    sum[0] = 1;
    cnt[1]--, ans -= cnt[1];
    for (int i = 1; i < (1 << spl[u][0]); i++) {
        sum[i] = sum[i ^ lowbit(i)] * spl[u][lg2[lowbit(i)] + 1];
//		printf("> %d\n", sum[i]);
        cnt[sum[i]]--;
        ans -= cnt[sum[i]] * miu[sum[i]];
    }
}

int main() {
    
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] = read();
        max = std::max(a[i], max);
    }
    sqn = sqrt(max) + 1;
    
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= pn; j++)
            if (b[i] % pri[j] == 0) {
                spl[i][++spl[i][0]] = pri[j];
                while (b[i] % pri[j] == 0)
                    b[i] /= pri[j];
            }
        if (b[i] ^ 1) spl[i][++spl[i][0]] = b[i];
    }
    
    for (int i = 1; i <= m; i++) {
        t = read(), use[t] ^= 1;
        if (use[t]) add(t);
        else del(t);
        printf("%lld\n", ans);
    }
    
    return 0;
}


//sajdfsdflkj
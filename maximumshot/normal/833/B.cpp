#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 35005;

int n, kk;
int dp[51][N];
int cnt[N];
int tot = 0;
int a[N];

int get() {
    return tot;
}

void add(int x) {
    if(cnt[x] == 0) tot++;
    cnt[x]++;
}

void del(int x) {
    if(cnt[x] == 0) return;
    if(cnt[x] == 1) tot--;
    cnt[x]--;
}

void clear() {
    for(int i = 0;i < N;i++) {
        cnt[i] = 0;
    }
    tot = 0;
}

void dfs(int k, int l, int r, int optL, int optR) { // optL .. r
    if(l > r) return;
    int m = (l + r) / 2;

    for(int j = m + 1;j <= r;j++) del(a[j]);

    // optL .. m

    int pos = -1;

    for(int j = optL;j <= min(m, optR);j++) {
        if(dp[k][m] < dp[k - 1][j - 1] + get()) {
            dp[k][m] = dp[k - 1][j - 1] + get();
            pos = j;
        }
        del(a[j]);
    }

    // min(m, optR) + 1 .. m

    for(int j = optL;j <= min(m, optR);j++) {
        add(a[j]);
    }

    // optL .. m

    if(pos == -1) {
        for(int j = m + 1;j <= r;j++) {
            add(a[j]);
        }
        // optL .. r
        dfs(k, l, m - 1, optL, optR);
        dfs(k, m + 1, r, optL, optR);
        return;
    }

    del(a[m]);

    dfs(k, l, m - 1, optL, pos);

    // optL .. m - 1

    add(a[m]);

    // optL .. m

    for(int j = optL;j < pos;j++) del(a[j]);

    // pos .. m

    for(int j = m + 1;j <= r;j++) add(a[j]);

    // pos .. r

    dfs(k, m + 1, r, pos, optR);

    for(int j = optL;j < pos;j++) add(a[j]);

    // optL .. r
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &kk);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0;i < 2;i++) {
        for(int j = 0;j < N;j++) {
            dp[i][j] = -inf;
        }
    }

    clear();

    dp[0][0] = 0;

    for(int i = 1;i <= n;i++) {
        add(a[i]);
        dp[1][i] = get();
    }

    for(int k = 2;k <= kk;k++) {
        clear();
        for(int i = 1;i <= n;i++) {
            add(a[i]);
        }
        dfs(k, 1, n, 1, n);
    }

    printf("%d\n", dp[kk][n]);

    return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1000100;
const int INF = 1e9;

int n, m, a[MAXN], qry[MAXN], pre[MAXN], suf[MAXN], dp[MAXN], num[MAXN], cnt, sze;
bool b[MAXN], rem[MAXN];

void calc(int cur) {
    if (dp[cur] != -1) return;
    if (pre[cur] == 0) {
        dp[cur] = INF;
        return;
    }
    calc(cur - pre[cur]);
    dp[cur] = dp[cur - pre[cur]] + 1;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d", &a[i]); a[i]--;
        b[a[i]] = 1;
    }
    pre[0] = b[0];
    for (int i=1; i<n; i++) pre[i] = pre[i-1] + b[i];
    for (int i=0; i<n; i++) scanf("%d", &qry[i]);
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<m; i++) dp[a[i]] = 1;
    for (int i=0; i<n; i++) {
        if (dp[i] == -1) calc(i);
    }
    for (int i=n-1; i>=0; i--) {
        suf[i] = suf[i+1] + (qry[i] == -1);
    }
    for (int i=0; i<n; i++) {
        if (qry[i] == -1) sze -= pre[sze-1];
        else {
            num[cnt++] = qry[i]; sze++;
            if (dp[sze-1] <= suf[i]) rem[cnt-1] = 1;
        }
    }
    bool good = 0;
    for (int i=0; i<cnt; i++) {
        if (rem[i]) continue;
        good = 1;
        printf("%d", num[i]);
    }
    if (!good) printf("Poor stack!\n");
    return 0;
}
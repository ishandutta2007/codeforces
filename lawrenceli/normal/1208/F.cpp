#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int maxn = 1000100;
const int maxlg = 21;
const int maxa = 1<<maxlg;

int n;
int a[maxn];
pii dp[maxa]; // dp[i] is max 2 indices j s.t. a[j] is superset of i

// updates dp[i] with dp[j]
int tmp[4];
void upd(int i, int j) {
    tmp[0] = dp[i].first; tmp[1] = dp[i].second;
    tmp[2] = dp[j].first; tmp[3] = dp[j].second;
    sort(tmp, tmp+4);
    int cnt = unique(tmp, tmp+4) - tmp;
    
    if (cnt == 1) dp[i] = pii(-1, tmp[cnt-1]);
    else dp[i] = pii(tmp[cnt-2], tmp[cnt-1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < maxn; i++)
        dp[i] = pii(-1, -1);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[a[i]] = pii(dp[a[i]].second, i);
    }

    for (int i = maxa - 1; i >= 0; i--) {
        for (int j = 0; j < maxlg; j++)
            if (i & (1<<j))
                upd(i ^ 1<<j, i);
    }

    int cur = 0;
    for (int i = maxlg-1; i >= 0; i--) {
        // try to flip the ith bit on
        cur |= 1<<i;
        bool good = false;
        for (int j = 0; j < n; j++) {
            int need = cur & ~a[j];
            if (dp[need].first > j) {
                good = true;
                break;
            }
        }

        if (!good) cur &= ~(1<<i);
    }

    printf("%d\n", cur);
}
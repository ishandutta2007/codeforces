#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, k;
char str[Maxn];
int nxt[Maxn][2], prv[Maxn][2];

int getStatus(int l, int r, int col)
{
    int res = 0;
    for (int i = 0; i < 2; i++) {
        int fir = nxt[1][i];
        if (l <= fir && fir <= r)
            fir = nxt[r + 1][i];
        if (i == col) fir = min(fir, l);
        int lst = prv[n][i];
        if (l <= lst && lst <= r)
            lst = prv[l - 1][i];
        if (i == col) lst = max(lst, r);
        if (fir > lst) res = 2;
        else if (lst - fir + 1 <= k) res = max(res, 1);
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", str + 1);
    nxt[n + 1][0] = nxt[n + 1][1] = n + 1;
    for (int i = n; i > 0; i--) {
        nxt[i][0] = nxt[i + 1][0];
        nxt[i][1] = nxt[i + 1][1];
        nxt[i][str[i] - '0'] = i;
    }
    for (int i = 1; i <= n; i++) {
        prv[i][0] = prv[i - 1][0];
        prv[i][1] = prv[i - 1][1];
        prv[i][str[i] - '0'] = i;
    }
    for (int i = 1; i + k <= n + 1; i++)
        if (getStatus(i, i + k - 1, 0) == 2 || getStatus(i, i + k - 1, 1) == 2) {
            printf("tokitsukaze\n"); return 0;
        }
    for (int i = 1; i + k <= n + 1; i++)
        if (getStatus(i, i + k - 1, 0) == 0 || getStatus(i, i + k - 1, 1) == 0) {
            printf("once again\n"); return 0;
        }
    printf("quailty\n");
    return 0;
}
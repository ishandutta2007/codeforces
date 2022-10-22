#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1505;

int n, s, m, k;
int a[Maxn];
int L[Maxn], R[Maxn];
int myR[Maxn];
int dp[Maxn][Maxn];

bool Check(int x)
{
    vector <int> un;
    for (int i = 1; i <= n; i++)
        if (a[i] <= x) un.push_back(i);
    if (un.size() < k) return false;
    for (int i = 0; i < un.size(); i++)
        myR[i] = -1;
    for (int i = 1; i <= s; i++) {
        int lef = lower_bound(un.begin(), un.end(), L[i]) - un.begin();
        int rig = upper_bound(un.begin(), un.end(), R[i]) - un.begin() - 1;
        if (lef <= rig) myR[lef] = max(myR[lef], rig);
    }
    for (int i = 1; i < un.size(); i++)
        myR[i] = max(myR[i - 1], myR[i]);
    fill((int*)dp, (int*)dp + Maxn * Maxn, -Maxn);
    dp[0][0] = 0;
    for (int i = 0; i < un.size(); i++)
        for (int j = 0; j <= m; j++) if (dp[i][j] >= 0) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (myR[i] >= i && j < m)
                dp[myR[i] + 1][j + 1] = max(dp[myR[i] + 1][j + 1], dp[i][j] + myR[i] + 1 - i);
        }
    int res = 0;
    for (int j = 0; j <= m; j++)
        res = max(res, dp[un.size()][j]);
    return res >= k;
}

int main()
{
    scanf("%d %d %d %d", &n, &s, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= s; i++)
        scanf("%d %d", &L[i], &R[i]);
    int lef = 0, rig = 1000000000;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Check(mid)) rig = mid - 1;
        else lef = mid + 1;
    }
    printf("%d\n", rig + 1 > 1000000000? -1: rig + 1);
    return 0;
}
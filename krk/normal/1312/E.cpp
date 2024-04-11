#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int n;
int a[Maxn];
int dp[Maxn][Maxn];

int Get(int l, int r)
{
    if (dp[l][r] == -1) {
        vector <int> S;
        for (int i = l; i <= r; i++) {
            int num = a[i];
            while (!S.empty() && S.back() == num) { num++; S.pop_back(); }
            S.push_back(num);
        }
        dp[l][r] = S.size();
        for (int i = l; i < r; i++)
            dp[l][r] = min(dp[l][r], Get(l, i) + Get(i + 1, r));
    }
    return dp[l][r];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    fill((int*)dp, (int*)dp + Maxn * Maxn, -1);
    printf("%d\n", Get(0, n - 1));
    return 0;
}
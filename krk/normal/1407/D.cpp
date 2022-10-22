#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n;
int h[Maxn];
vector <int> A, B;
int dp[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    A.push_back(1); B.push_back(1);
    for (int i = 2; i <= n; i++) {
        dp[i] = 1000000000;
        bool forb = false;
        while (!A.empty() && h[A.back()] >= h[i]) {
            if (h[A.back()] == h[i]) forb = true;
            dp[i] = min(dp[i], dp[A.back()] + 1);
            A.pop_back();
        }
        if (!A.empty() && !forb)
            dp[i] = min(dp[i], dp[A.back()] + 1);
        A.push_back(i);
        forb = false;
        while (!B.empty() && h[B.back()] <= h[i]) {
            if (h[B.back()] == h[i]) forb = true;
            dp[i] = min(dp[i], dp[B.back()] + 1);
            B.pop_back();
        }
        if (!B.empty() && !forb)
            dp[i] = min(dp[i], dp[B.back()] + 1);
        B.push_back(i);
    }
    printf("%d\n", dp[n]);
    return 0;
}
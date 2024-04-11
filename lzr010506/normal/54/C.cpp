#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 1010;
ull cal(ull n)
{
    ull ans = 0,x = 1,y = 1;
    while(x <= n) 
    {
        ans += min(y,n - x + 1);
        x *= 10;
        y *= 10;
    }
    return ans;
}

double dp[N][N];

int main()
{
    int n;
    long long L,R;
    cin >> n;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++) 
    {
        cin >> L >> R;
        double p = (cal(R) - cal(L - 1)) * 1.0 / (R - L + 1);
        for(int j = 0; j < i; j ++) 
        {
            dp[i][j] += (1 - p) * dp[i - 1][j];
            dp[i][j + 1] += p * dp[i - 1][j];
        }
    }
    int m;
    cin >> m;
    double ans = 0;
    for(int i = 0; i <= n; i ++)
        if(i * 100 >= n * m) ans += dp[n][i];
    printf("%.20lf\n",ans);
    return 0;
}
#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;

signed main()
{
   // ifstream cin("rt.txt.txt");
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
   // cout.tie(0);
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1 << "\n";
        cout << "o";
        return 0;
    }
    int dp[n + 1][n + 1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = 1e9;
        }
    }
    for(int k = 1; 2 * k - 1 <= n; k++)
    {
        dp[k * 2 - 1][k] = k;
    }
    pair <int, int> p[n + 1][n + 1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int t = 1; t < j; t++)
            {
                if(2 * t - 1 + i <= n && dp[i][j] < dp[2 * t - 1 + i][t])
                {
                    dp[2 * t - 1 + i][t] = dp[i][j];
                    p[2 * t - 1 + i][t] = {i, j};
                }
            }
        }
    }
    int a = 0;
    for(int i = 1; i <= n; i++)
    {
        if(dp[n][i] < dp[n][a])
        {
            a = i;
        }
    }
    if(dp[n][a] == 1e9)
    {
        cout << -1;
        return 0;
    }
    int k = dp[n][a];
    cout << k << "\n";
    char mat[k][k];
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            mat[i][j] = '.';
        }
    }
    int i = 0;
    int sum = n;
    vector <int> vec;
    while(sum > 0)
    {
        int sum1 = p[sum][a].X;
        int a1 = p[sum][a].Y;
        vec.push_back(a);
        sum = sum1;
        a = a1;
    }
    reverse(vec.begin(), vec.end());
    for(auto a : vec)
    {
        for(int el = 0; el < a; el++)
        {
            mat[i][i + el] = 'o';
            mat[i + el][i] = 'o';
        }
        i++;
    }
    for(int i = k - 1; i >= 0; i--)
    {
        for(int j = 0; j < k; j++)
        {
            cout << mat[i][j];
        }
        cout << "\n";
    }
    return 0;
}
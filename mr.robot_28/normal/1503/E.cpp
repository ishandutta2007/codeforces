#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
const int mod = 998244353;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    if(n < m)
    {
        swap(n, m);
    }
    vector <vector <int> > choose(n + m, vector <int> (n));
    for(int i = 0; i < n + m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j == 0)
            {
                choose[i][j] = 1;
            }
            else if(i == 0)
            {
                choose[i][j] = 0;
            }
            else{
                choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % mod;
            }
        }
    }
    int ans = 0;
    for(int r = 1; r < n; r++)
    {
        int sum = 0;
        for(int c = m  - 1; c >= 1; c--)
        {
            sum = (sum + choose[n - r + m - c - 1][n - r] * choose[c + n - r - 1][n - r - 1]) % mod;
            ans = (ans + choose[r + c - 1][r] * ((choose[m - c + r - 1][r - 1] * sum) % mod)) % mod;
        }
    }
    swap(n, m);
    for(int r = 1; r < n; r++)
    {
        int sum = 0;
        for(int c = m - 1; c >= 1; c--)
        {
            ans = (ans + choose[r + c - 1][r] * ((choose[m - c + r - 1][r- 1] * sum) % mod)) % mod;
            sum = (sum + choose[n - r + m - c - 1][n - r] * choose[c + n - r - 1][n - r - 1]) % mod;
        }
    }
    cout << (ans * 2) % mod;
    return 0;
}
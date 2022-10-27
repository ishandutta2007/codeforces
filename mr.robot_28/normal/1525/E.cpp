#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int mod = 998244353;
int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b % 2 == 0)
    {
        int t = power(a, b / 2);
        return t * t % mod;
    }
    return a * power(a, b - 1) % mod;
}
signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int> > d(n, vector <int> (m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> d[i][j];
        }
    }
    int inv = (mod + 1) / 2;
    int k1 = 1;
    for(int i =1 ; i <= n; i++)
    {
        k1 = k1 * i % mod;
    }
    int sum = 0;
    for(int i = 0; i < m; i++)
    {
        vector <int> p;
        for(int j = 0; j < n; j++)
        {
            p.push_back(d[j][i] - 1);
        }
        sort(p.begin(), p.end());
        int ans = 1;
        for(int j = 0; j < n; j++)
        {
            ans = ans * (p[j] - j) % mod;
        }
        sum = (sum + k1 - ans + mod) % mod;
    }    k1 = power(k1, mod - 2);

    cout << sum * k1 % mod;
    return 0;
}
#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
//#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5;

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> vec;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '?')
        {
            vec.push_back(-1);
        }
        else
        {
            vec.push_back(s[i] - 'a');
        }
    }
    vector <vector <int> > right(k, vector <int> (n, 0));
    for(int i = 0; i < k; i++)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            if(vec[j] == i || vec[j] == -1)
            {
                if(j == n - 1)
                {
                    right[i][j] = 1;
                }
                else
                {
                    right[i][j] = right[i][j + 1] + 1;
                }
            }
   //         cout << right[i][j] << " ";
        }
     //   cout << "\n";
    }
    int l = 0, r = n + 1;
    while(r - l > 1)
    {
        int midd = (r + l) / 2;
        vector <vector <int> > mass(26);
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(right[i][j] >= midd)
                {
                    mass[i].push_back(j);
                }
            }
        }
        vector <int> dp(1 << k, 1e9);
        dp[0] = -1;
        vector <int> iter(k, 0);
        vector <vector <int> > mass1(n + 1);
        mass1[0].push_back(0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < k; j++)
            {
                while(iter[j] < sz(mass[j]) && mass[j][iter[j]] < i)
                {
                    iter[j]++;
                }
            }
            for(auto p : mass1[i])
            {
                if(dp[p] != i - 1)
                {
                    continue;
                }
                for(int j = 0; j < k; j++)
                {
                    if((1 << j) & p)
                    {
                        continue;
                    }
                    if(iter[j] < sz(mass[j]))
                    {
                        int u = mass[j][iter[j]];
                        if(dp[(1 << j) | p] > u + midd - 1)
                        {
                            dp[(1 << j) | p] = u + midd - 1;
                            mass1[u + midd].push_back((1 << j) | p);
                        }
                    }
                }
            }
        }
        if(dp[(1 << k) - 1] < n)
        {
            l = midd;
        }
        else
        {
            r = midd;
        }
    }
    cout << l;
    return 0;
}
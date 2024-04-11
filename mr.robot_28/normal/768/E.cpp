#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 4;
const double eps = 1e-7;
map <pair <int, long long>, bool> mp;
map <pair <int, long long>, int> dp;
int rec(int a, long long mask, int prev = 63)
{
    for(int i = a; i < prev; i++)
    {
        if((mask >> i) & 1LL)
        {
            mask ^= (1LL << i);
        }
    }
    if(mp[{a, mask}])
    {
        return dp[{a, mask}];
    }
    vector <bool> used(63, false);
    for(int b = 0; b < a; b++)
    {
        if(((mask >> b) & 1LL) == 0)
        {
            continue;
        }
        used[rec(a - b - 1LL, mask ^ (1 << b), a)] = 1;
    }
    int ans1 = 0;
    for(int i = 0; i < 63; i++)
    {
        if(used[i])
        {
            continue;
        }
        dp[{a, mask}] = i;
        ans1 = i;
        break;
    }
    mp[{a, mask}] = 1;
    return ans1;
}
signed main()
{
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    //cout.tie(NULL);
    int n;
    cin >> n;
    dp[{0, 0}] = 0;
    int gr[61];
    for(int i = 0; i <= 60; i++)
    {
        gr[i] = rec(i, (1LL << i) - 1);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        ans = ans ^ gr[s];
    }
    if(ans == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
using namespace __gnu_pbds;
const int mod = 998244353;
vector <int> power(int len, int val)
{
    if(val == 1)
    {
        return vector <int>(len, 1);
    }
    vector <int> ans(len);
    vector <int> solve1 = power(len, val / 2);
    for(int j = 0; j < len; j++)
    {
        for(int i = 0; i <= j; i++)
        {
            int to = solve1[j - i];
            if(i % 2 != 0)
            {
                to = (j - 1 - i >= 0 ? solve1[j - i - 1] : 0);
            }
            ans[j] = (ans[j] + solve1[i] * to) % mod;
        }
    }
    if(val % 2 == 1)
    {
        vector <int> ans1(len);
        for(int j = 0; j < len; j++)
        {
            for(int i = 0; i <= j; i++)
            {
                int add = (i != j || j % 2 == 0 ? ans[i] : 0);
                ans1[j] = (ans1[j] + add) % mod;
            }
        }
        ans = ans1;
    }
    return ans;
}
void funct1(vector <int> &dp, vector <int> &L, vector <int> &R, vector <bool> &flag, int val)
{
    vector <int> dp2(dp.size());
    for(int i = 0; i < dp.size(); i++)
    {
        for(int j = 0; j < i + (flag[i] == 1); j++)
        {
            if(L[i] <= val && R[i] >= val && L[j] <= val - 1 && val - 1 <= R[j])
            {
                dp2[i] = (dp2[i] + dp[j]) % mod;
            }
        }
    }
    dp = dp2;
}
int funct(vector <int> mass)
{
    int n1 = mass.size();
     vector <int> mass1 = mass;
     sort(mass1.begin(), mass1.end());
     vector <int> L(n1), R(n1);
     vector <bool> flag(n1, 1);
     for(int i = 0; i + 1 < mass.size(); i++)
     {
         L[i] = mass[i];
         R[i] = mass[i + 1];
         if(i != 0)
         {
            if(L[i] < R[i])
            {
                L[i]++;
            }
            else
            {
                L[i]--;
            }
         }
         if(L[i] > R[i])
         {
             swap(L[i], R[i]);
             flag[i] = 0;
         }
     }
     n1--;
     int from = mass1[0];
     int to = mass1.back();
     vector <int> dp(n1, 0);
     for(int i = 0; i < n1; i++)
     {
         if(from <= R[i] && L[i] <= from)
         {
             dp[i] = 1;
         }
     }
     int lst = from;
     for(int it = 0; it < mass1.size(); it++)
     {
         int val = mass1[it];
         if(lst < val - 2)
         {
            vector <int> active(n1);
            for(int i = 0; i <  n1; i++)
            {
                for(int j = 0; j < i + (flag[i] == 1); j++)
                {
                    if(L[i] <= val - 2 && R[i] >= val - 2 && L[j] <= val - 2 && val - 2 <= R[j])
                    {
                        active[i] = active[j] = 1;
                    }
                }
            }
            vector <int> pos(n1);
            int cnt = 0;
            for(int i = 0; i < n1; i++)
            {
                if(active[i])
                {
                    pos[i] = cnt;
                    cnt++;
                }
            }
            vector <int> dp2(n1);
            vector <int> dp1 = power(cnt, val - 2 - lst);
            for(int i = 0; i < n1; i++)
            {
                for(int j = 0; j <= i; j++)
                {
                    int add;
                    int i1 = pos[i];
                    int j1 = pos[j];
                    if(i1 % 2 == 0)
                    {
                        add = dp1[i1 - j1];
                    }
                    else if(i1 - j1 - 1 >= 0)
                    {
                        add = dp1[i1 - j1 - 1];
                    }
                    else
                    {
                        add = 0;
                    }
                    dp2[i] = (dp2[i] + dp[j] * add) % mod;
                }
            }
            dp = dp2;
            lst = val - 2;
         }
         if(lst < val - 1)
         {
             funct1(dp, L, R, flag, val - 1);
             lst = val - 1;
         }
         if(lst < val)
         {
             funct1(dp, L, R, flag, val);
             lst = val;
         }
         if(val + 1 <= to && lst < val + 1)
         {
             funct1(dp, L, R, flag, val + 1);
             lst = val + 1;
         }
     }
     int ans = 0;
     for(int i = 0; i < n1; i++)
     {
         if(L[i] <= to && to <= R[i])
         {
         ans = (ans + dp[i]) % mod;
         }
     }
     return ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector <int> a;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x != 0)
        {
            if(a.size() > 0 && a.back() * x > 0)
            {
                a[a.size() - 1] += x;
            }
            else
            {
                a.push_back(x);
            }
        }
    }
    for(int i = 1; i < a.size(); i++)
    {
        a[i] += a[i - 1];
    }
    a.insert(a.begin(), 0);
    int maxlen = 1;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = i + 1; j < a.size(); j++)
        {
            maxlen = max(maxlen, a[j] - a[i] + 1);
        }
    }
    if(maxlen == 1)
    {
        int ans = 1;
        for(int i = 0; i + 1 < a.size(); i++)
        {
            ans += abs(a[i + 1] - a[i]);
        }
        ans = ans % mod;
        cout << 1 << " " << ans;
        return 0;
    }
    n = a.size();
    int i = 0;
    int ans = 0;
    while(i < n)
    {
        int id = -1;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] - a[i] + 1 == maxlen)
            {
                id = j;
            }
        }
        if(id == -1)
        {
            i++;
            continue;
        }
        vector <int> mass;
        for(int k = i; k <= id; k++)
        {
            mass.push_back(a[k]);
        }
        ans = (ans + funct(mass)) % mod;
        i = id;
    }
    cout << maxlen << " " << ans;
    return 0;
}
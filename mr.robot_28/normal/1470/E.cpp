#include<bits/stdc++.h>
using namespace std;
const int N = 3e4;
#define ll __int128
    ll dp[N][11][11];
    ll dpsum[N][11];
        vector <pair <int, int> > vec[N][11];
    ll dppref[N][11];
        ll dp2[N][11][11];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, c, q;
        cin >> n >> c >> q;
        vector <int> p(n);
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= 10; j++)
            {
                dppref[i][j] = 0;
                dpsum[i][j] = 0;
                for(int c1 = 0; c1 <= 10; c1++)
                {
                    dp[i][j][c1] = 0;
                }
            }
        }
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= c && i + j < n; j++)
            {
                if(i + j == n - 1)
                {
                    dp[i][j][j] = 1;
                }
                else
                {
                    for(int k = 0; k + j <= c; k++)
                    {
                        dp[i][j + k][j] += dpsum[i + j + 1][k];
                    }
                }
            }
            for(int j = 0; j <= c; j++)
            {
                for(int k = 0; k <= c; k++)
                {
                    dpsum[i][j] += dp[i][j][k];
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= c; j++)
            {
                for(int k = 0; k <= c; k++)
                {
                    if(k + i >= n || p[k + i] >= p[i])
                    {
                        continue;
                    }
                    dppref[i][j] += dp[i][j][k];
                }
                if(j != 0)
                {
                    dppref[i][j] += dppref[i][j - 1];
                }
            }
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= c; j++)
            {
                if(i != 0)
                {
                    dppref[i][j] += dppref[i - 1][j];
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int k = 0; k <= c; k++)
            {
                for(int j = 0; j <= c; j++)
                {
                    dp2[i][j][k] = dp[i][j][k];
                    if(j != 0)
                    {
                        dp2[i][j][k] += dp2[i][j - 1][k];
                    }
                }
            }
        }
        ll dp1[n][11];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= c; j++)
            {
                dp1[i][j] = dp[i][j][0];
                if(j != 0){
                    dp1[i][j] += dp[i][j - 1][0];
                }
            }
        }
        ll sumall = 0;
        for(int j = 0;j <= c; j++)
        {
            sumall += dpsum[0][j];
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= c; j++)
            {
                vec[i][j].clear();
                if(j != 0)
                {
                    vec[i][j] = vec[i][j - 1];
                }
                if(j + i < n)
                {
                vec[i][j].push_back({p[i + j], j});
                sort(vec[i][j].begin(), vec[i][j].end());
                }
            }
        }
        while(q--)
        {
            long long cnt;
            int ind;
            cin >> ind >> cnt;
            ind--;
            int ans = -1;
            if(sumall >= cnt)
            {
                int st = 0;
                int call = 0;
                int ost = c;
                while(st != n)
                {
                    if(st != 5)
                    {
               //         cout << st << " " << ost << " " << cnt << "\n";
                    }
                    int l = st - 1, r = n - 1;
                    while(r - l > 1)
                    {
                        int midd = (r + l) / 2;
                        ll t1 = dppref[midd][ost];
                        if(st != 0)
                        {
                            t1 -= dppref[st - 1][ost];
                        }
                        ll t2 = t1 + dp1[midd][ost];
                        if(st != 5)
                        {
                      //  cout << st << " " << midd << " " << t1 << " " << dp1[midd][ost] << "\n";
                        }
                        if(t1 < cnt && t2 >= cnt)
                        {
                            l = midd;
                        }
                        else
                        {
                            r = midd;
                        }
                    }

                    if(l != st - 1)
                    {
                        ll t1 = dppref[l][ost];
                        if(st != 0)
                        {
                            t1 -= dppref[st - 1][ost];
                        }
                        cnt -= t1;
                    }
                    if(ind >= st && ind < l + 1)
                    {
                        ans = p[ind];
                    }
                   // cout << st << " " << vec[st][1].size() << "\n";
                    st = l + 1;
                    for(int i = 0; i < vec[st][ost].size(); i++)
                    {
                        int it = vec[st][ost][i].second;
                        ll val = dp2[st][ost][it];
                        if(val >= cnt)
                        {
                            if(ind >= st && ind <= st + it)
                            {
                                ans = p[st + it - (ind - st)];
                            }
                            ost -= it;
                            st += it + 1;
                            break;
                        }
                        else
                        {
                            cnt -= val;
                        }
                    }
                    call++;
             //       assert(call <= 20);
                    //cout << "\n";
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
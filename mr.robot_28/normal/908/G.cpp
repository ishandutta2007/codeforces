#include<bits/stdc++.h>

using namespace std;
#define int long long
int powers[701];
const int mod = 1e9 + 7;
int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b % 2 == 0)
    {
        int t= power(a, b / 2);
        return 1LL * t * t % mod;
    }
    return 1LL * a * power(a, b - 1) % mod;
}
int stupid_sol(int x)
{
    int ans = 0;
    while(x)
    {
        int x1 = x;
        vector <int> mass;
        while(x1 > 0)
        {
            mass.push_back(x1 % 10);
            x1 /= 10;
        }
        sort(mass.begin(), mass.end());
        reverse(mass.begin(), mass.end());
        for(int i = 0;i < mass.size(); i++)
        {
            ans += powers[i] * mass[i] % mod;
            if(ans >= mod)
            {
                ans -= mod;
            }
        }
        x--;
    }
    return ans;
}
signed main(){
//	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
//	cout.tie(NULL);
    string s;
    cin >> s;
    powers[0] = 1;
    for(int i = 1; i <= 700; i++)
    {
        powers[i] = powers[i - 1] * 10 % mod;
    }
    int ans = 0;
    int dp1[701][701][2], dp2[701][701][2];
    for(int a = 1; a <= 9; a++)
    {
        for(int cnt1 = 0; cnt1 < 701; cnt1++)
        {
            for(int cnt2 = 0; cnt2 < 701; cnt2++)
            {
                for(int fl = 0; fl < 2; fl++)
                {
                    dp1[cnt1][cnt2][fl] = dp2[cnt1][cnt2][fl] = 0;
                }
            }
        }
        dp2[0][0][0] = 1;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j <= i; j++)
            {
                for(int fl = 0; fl < 2; fl++)
                {
                    int maxt = 9;
                    if(fl == 0)
                    {
                        maxt = s[i] - '0';
                    }
                    for(int c1 = 0; c1 <= maxt; c1++)
                    {
                        int j1 = j + (c1 >= a);
                        int fl1 = fl;
                        if(c1 < maxt)
                        {
                            fl1 = 1;
                        }
                        if(c1 == a)
                        {
                            dp1[i + 1][j1][fl1] += (dp1[i][j][fl] + a * powers[j] % mod * dp2[i][j][fl] % mod) % mod;
                            while(dp1[i + 1][j1][fl1] >= mod)
                            {
                                dp1[i + 1][j1][fl1] -= mod;
                            }
                        }
                        if(c1 < a)
                        {
                            dp1[i + 1][j1][fl1] += dp1[i][j][fl];
                            while(dp1[i + 1][j1][fl1] >= mod)
                            {
                                dp1[i + 1][j1][fl1] -= mod;
                            }
                        }
                        if(c1 > a)
                        {
                            dp1[i + 1][j1][fl1] += dp1[i][j][fl] * 10 % mod;
                            while(dp1[i + 1][j1][fl] >= mod)
                            {
                                dp1[i + 1][j1][fl] -= mod;
                            }
                        }
                        dp2[i + 1][j1][fl1] += dp2[i][j][fl];
                        while(dp2[i + 1][j1][fl1] >= mod)
                        {
                            dp2[i + 1][j1][fl1] -= mod;
                        }
                    }
                }
            }
        }
        for(int j = 0; j <= s.size(); j++)
        {
            for(int t =0 ; t < 2; t++)
            {
            ans += dp1[s.size()][j][t];
            while(ans >= mod)
            {
                ans -= mod;
            }
            }
        }
    }
    cout << ans;
	return 0;
}
#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
#define int long long

std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;

signed main()
{
   // ifstream cin("rt.txt.txt");
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector <string> s(n);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int ans = 0;
    vector <int> res(m);
    for(int iter = 0; iter < 50; iter++)
    {
        int idx = rnd() % n;
        vector <int> bits;
        for(int j = 0; j < m; j++)
        {
            if(s[idx][j] == '1')
            {
                bits.push_back(j);
            }
        }
        int m1 = sz(bits);
        vector <int> cnt(1 << m1);
        for(int i = 0; i < n; i++)
        {
            int mask = 0;
            for(int j= 0; j < sz(bits); j++)
            {
                if(s[i][bits[j]] == '1')
                {
                    mask |= (1 << j);
                }
            }
            ++cnt[mask];
        }
        for(int j = 0; j < m1; j++)
        {
            for(int msk = 0; msk < (1 << m1); msk++)
            {
                if((msk & (1 << j)) == 0)
                {
                    cnt[msk] += cnt[msk | (1 << j)];
                }
            }
        }
        for(int msk = 0; msk < (1 << m1); msk++)
        {
            if(cnt[msk] >= (n + 1) / 2)
            {
                int c = 0;
                for(int j = 0; j < m1; j++)
                {
                    if((1 << j) & msk)
                    {
                        c++;
                    }
                }
                if(c > ans)
                {
                    ans = c;
                    for(int j = 0; j < m; j++)
                    {
                        res[j] = 0;
                    }
                    for(int j = 0; j < m1; j++)
                    {
                        if((1 << j) & msk)
                        {
                            res[bits[j]] = 1;
                        }
                    }
                }
            }
        }
    }
    for(int j = 0; j < m; j++)
    {
        cout << res[j];
    }
    return 0;
}
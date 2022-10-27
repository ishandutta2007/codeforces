#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
//#define int long long
using namespace std;
const int mod = 998244353;
const int N = 2e6;
vector <int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
vector <int> dy = {-1, 0, 1, 1, -1, 0, 1, -1};
signed main()
{
  ios_base::sync_with_stdio(0);
 cin.tie(0);
  cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int h, w;
        cin >> h >> w;
        vector <pair <int, int> > vec;
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if((i == 0 || i == h - 1) && (j <= 1 || j >= w - 2))
                {
                    vec.push_back({i, j});
                }
                else if((j == 0 || j == w - 1) && (i <= 1 || i >= h - 1))
                {
                    vec.push_back({i, j});
                }
            }
        }
        vector <vector<char> > opt(h, vector <char> (w, '0'));
        int ans = 0;
        int m = sz(vec);
        for(int mask = 0; mask < (1 << m); mask++)
        {
            int s = 0;
            map <pair <int, int>, int> mp;
            for(int i = 0; i < sz(vec); i++)
            {
                if((1 << i) & mask)
                {
                    s++;
                    mp[vec[i]] = 1;
                }
            }
            for(int i = 0; i < sz(vec); i++)
            {
                if((1 << i) & mask)
                {
                    for(int j = 0; j < 8; j++)
                    {
                        pair <int, int> p = {vec[i].X + dx[j], vec[i].Y + dy[j]};
                        if(mp[p])
                        {
                            s = 1e9;
                        }
                    }
                }
            }
            if(s == 1e9)
            {
                continue;
            }
            for(int j = 2; j + 2 < w; j++)
            {
                if(!mp[{0, j - 1}] && !mp[{0, j + 1}])
                {
                    mp[{0, j}] = 1;
                    s++;
                }
                if(!mp[{h - 1, j - 1}] && !mp[{h - 1, j + 1}])
                {
                    mp[{h - 1, j}] = 1;
                    s++;
                }
            }
            for(int i = 2; i + 2 < h; i++)
            {
                if(!mp[{i - 1, 0}] && !mp[{i + 1, 0}])
                {
                    s++;
                    mp[{i, 0}] = 1;
                }
                if(!mp[{i - 1, w - 1}] && !mp[{i + 1, w - 1}])
                {
                    mp[{i, w - 1}] = 1;
                    s++;
                }
            }
            if(s > ans)
            {
                ans = s;
                for(int i = 0; i < h; i++)
                {
                    if(mp[{i, 0}])
                    {
                        opt[i][0] = '1';
                    }
                    else
                    {
                        opt[i][0] = '0';
                    }
                    if(mp[{i, w - 1}])
                    {
                        opt[i][w - 1] = '1';
                    }
                    else
                    {
                        opt[i][w - 1] = '0'; 
                    }
                }
                for(int i = 0; i < w; i++)
                {
                    if(mp[{0, i}])
                    {
                        opt[0][i] = '1';
                    }
                    else
                    {
                        opt[0][i] = '0';
                    }
                    if(mp[{h - 1, i}])
                    {
                        opt[h - 1][i] = '1';
                    }
                    else
                    {
                        opt[h - 1][i] = '0';
                    }
                }
            }
        }
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                cout << opt[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int maxn =2e5 + 100;

signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        int m, k;
        cin >> m >> k;
        vector <pair <int, int> > a(k);
        for(int i = 0; i < k; i++)
        {
            cin >> a[i].X;
            a[i].Y = i + 1;
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        int mx = a[0].X;
        for(int n = 1; n <= m; n++)
        {
            if(mx > n * ((n + 1) / 2))
            {
                continue;
            }
            if(m > n * n - (n / 2) * (n / 2))
            {
                continue;
            }
            int ans[n][n];
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    ans[i][j] = 0;
                }
            }
            vector <pair <int, int> > x, y, z;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if((i + j) % 2 == 1)
                    {
                        if(i % 2 == 0)
                        {
                            x.push_back({i, j});
                        }
                        else
                        {
                            y.push_back({i, j});
                        }
                    }
                    else if(i % 2 == 0)
                    {
                        z.push_back({i, j});
                    }
                }
            }
            for(int i = 0; i < k; i++)
            {
                vector <pair <int, int> > &cur = (sz(x) > 0 ? x : y);
                while(a[i].X && sz(cur))
                {
                    ans[cur.back().X][cur.back().Y] = a[i].Y;
                    a[i].X--;
                    cur.pop_back();
                }
                while(a[i].X--)
                {
                    ans[z.back().X][z.back().Y] = a[i].Y;
                    z.pop_back();
                }
            }
            cout << n << "\n";
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << "\n";
            }
            break;
        }
    }
    return 0;
}
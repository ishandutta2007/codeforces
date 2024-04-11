#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int N = 2e6 + 1;
int query(int a, int b, int c)
{
    cout << "? " << a << " " << b << " " << c << endl;
    int x;
    cin >> x;
    return x;
}

signed main()
{
   // ifstream cin("rt.txt.txt");
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> ans(n + 1);
        int a = -1, b, c;
        for(int x = 1; x <= 13; x++)
        {
            for(int y = x + 1; y <= 13; y++)
            {
                for(int z = y + 1; z <= 13; z++)
                {
                    if(query(x, y, z) <= (n - 4) / 6)
                    {
                        a = x;
                        b = y;
                        c = z;
                        break;
                    }
                }
                if(a != -1)
                {
                    break;
                }
            }
            if(a != -1)
            {
                break;
            }
        }
        map <int, vector <int> > mp;
        for(int x = 1; x <= n; x++)
        {
            if(x != a && x != b)
            {
                mp[query(a, b, x)].push_back(x);
            }
        }
        int hv;
        int largest = 0;
        for(auto it : mp)
        {
            hv = it.X;
            largest = it.Y[0];
        }
        if(sz(mp[hv - 1]) >= 2)
        {
            if(query(mp[hv][0], mp[hv - 1][0], a) > query(mp[hv][0], mp[hv -1][1], a))
            {
                swap(mp[hv - 1][0], mp[hv - 1][1]);
            }
        }
        int h1 = mp[hv][0], h2 = mp[hv - 1][0];
        ans[h1] = 1;
        ans[h2] = 2;
        for(int i = 1; i <= n; i++)
        {
            if(i != h1 && i != h2)
            {
                ans[i] = query(h1, h2, i) + 2;
            }
        }
        if(ans[1] > ans[2])
        {
            for(int i = 1; i <= n; i++)
            {
                ans[i] = n - ans[i] + 1;
            }
        }
        cout << "! ";
        for(int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        int k;
        cin >> k;
    }
    return 0;
}
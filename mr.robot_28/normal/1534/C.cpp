#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 100;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>> n;
        vector <vector <int> > a(2, vector <int> (n));
        bool fl = 1;
        vector <int> nxt(n);
        for(int i = 0;i < 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 0; i< n; i++)
        {
            if(a[0][i] == a[1][i])
            {
                fl = 0;
            }
            nxt[a[0][i] - 1] = (a[1][i] - 1);
        }
        if(!fl)
        {
            cout << 0<< "\n";
            continue;
        }
        int ans = 1;
        vector <bool> used(n);
        for(int i = 0; i < n; i++)
        {
            if(!used[i])
            {
                ans = ans * 2 % mod;
                int v = i;
                while(!used[v])
                {
                    used[v] = 1;
                    v = nxt[v];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
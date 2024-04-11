#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)a.size()
#define X first
#define Y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, u, v;
        cin >> n >> u >> v;
        vector <int> a(n);
        bool fl = 1;
        bool fl1 = 1;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(i != 0 && a[i] != a[i - 1])
            {
                fl = 0;
            }
            if(i != 0 && abs(a[i] - a[i - 1]) > 1)
            {
                fl1 = 0;
            }
        }
        if(fl)
        {
            cout << v + min(u, v) << "\n";
        }
        else if(!fl1)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << min(u, v) << "\n";
        }
    }
    return 0;
}
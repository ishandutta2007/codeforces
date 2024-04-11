#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
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
        int u, v;
        cin >> u >> v;
        if(u > v)
        {
            cout << "NO\n";
            continue;
        }
        int t1 = __builtin_popcount(u);
        int t2 = __builtin_popcount(v);
       // cout << t1 << " " << t2 << "\n";
        if(t1 < t2)
        {
            cout << "NO\n";
            continue;
        }
        int f = 0;
        bool flag = 1;
        int c1 = 0, c2 = 0;
        while((1 << f) <= v)
        {
            c1 += ((u & (1 << f)) >> f);
            c2 += ((v & (1 << f)) >> f);
            f++;
      //      cout << c1 << " " << c2 << "\n";
            if(c1 < c2)
            {
                flag = 0;
            }
        }
        if(!flag)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}
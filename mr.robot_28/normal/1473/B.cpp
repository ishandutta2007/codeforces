#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();
        string s1 = s, t1 = t;
        int k = n * m / __gcd(n, m);
        while(s.size() < k)
        {
            s += s1;
        }
        while(t.size() < k)
        {
            t += t1;
        }
        bool fl = 1;
        for(int i = 0; i < k; i++)
        {
            if(s[i] != t[i])
            {
                fl = 0;
            }
        }
        if(fl)
        {
            cout << s << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}
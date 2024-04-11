#include<bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    map <pair <int, int>, int> colors;
    set <pair <int, int> > s1, s2;
    while(m--)
    {
        char t;
        cin >> t;
        if(t == '+')
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if(colors.count({v, u}))
            {
                if(colors[{v, u}] == c)
                {
                    s1.insert({min(u, v), max(u, v)});
                }
                else
                {
                    s2.insert({min(u, v), max(u, v)});
                }
            }
            colors[{u, v}] = c;
        }
        else if(t == '-')
        {
            int u, v;
            cin >> u >> v;
            s1.erase({min(u, v), max(u, v)});
            s2.erase({min(u, v), max(u, v)});
            colors.erase({u, v});
        }
        else
        {
            int k;
            cin >> k;
            bool fl = s1.size() > 0;
            if(k & 1)
            {
                fl = fl | s2.size() > 0;
            }
            if(fl)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N = 1e5+5;
const long long inf = 2e18;

vector<int> g[N];
int n;

signed main()
{
    cin >> n;
    if (n == 2)
    {
        cout << "Yes\n1\n1 2";
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int pos = 0;
    for (int i = 1; i <= n; i++)
        if (g[i].size() > 2)
            if (pos == 0)
                pos = i;
            else
            {
                cout << "No";
                return 0;
            }
    if (pos == 0)
    {
        cout << "Yes\n1\n";
        for (int i = 1; i <= n; i++)
            if (g[i].size() == 1)
                cout << i << ' ';
        return 0;
    }
    int kol = 0;
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1)
            kol++;
    cout << "Yes" << endl;
    cout << kol << endl;

    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1)
            cout << i << ' ' << pos << endl;
    return 0;
}
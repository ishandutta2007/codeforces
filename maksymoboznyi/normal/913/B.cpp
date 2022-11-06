#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e6+6;
const ll inf = 2e18;

vector<int> g[N];
ll n, kol[N], k[N];

signed main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        g[x].pb(i);
    }
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 0)
            kol[i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < int(g[i].size()); j++)
            k[i] += kol[g[i][j]];
    for (int i = 1; i <= n; i++)
        if (kol[i] == 0 && k[i] < 3)
        {
            cout << "No";
            return 0;
        }
    cout << "Yes";
    return 0;
}
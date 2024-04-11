#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w[100010], deg[100010] = {0};

        ll r = 0;
        vector<int> c;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> w[i];
            r += w[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            deg[x]++;
            deg[y]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] >= 2)
            {
                deg[i]--;
                while (deg[i]--)
                    c.emplace_back(w[i]);
            }
        }
        sort(c.begin(), c.end());
        for (int i = 1; i <= n - 1; i++)
        {
            cout << r << " \n"[i == n - 1];
            if (!c.empty())
            {
                r += c.back();
                c.pop_back();
            }
        }
    }
}
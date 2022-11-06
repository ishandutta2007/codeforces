#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, a[N], h;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> p;
    for (int i = 1; i <= n; i++) {
        int x = 0;
        vector<int> pp;
        for (; x < p.size() && p[x] <= a[i]; x++)
            pp.pb(p[x]);
        pp.pb(a[i]);
        for (; x < p.size(); x++)
            pp.pb(p[x]);
        p = pp;
        long long h1 = 0;
        for (int i = p.size() - 1; i >= 0; i -= 2)
            h1 += p[i];
        if (h1 > h)
        {
            cout << i - 1;
            return 0;
        }
    }
    cout << n;
    return 0;
}
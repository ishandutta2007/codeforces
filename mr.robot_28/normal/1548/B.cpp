#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 2e5;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if(n == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        vector <int> d(n - 1);
        for(int i = 0; i < n - 1; i++)
        {
            d[i] = abs(a[i] - a[i + 1]);
        }
        int ans = 1;
        vector <pair <int, int> > mass;
        for(int i = 0; i < n - 1; i++)
        {
            mass.push_back({d[i], i});
            vector <pair <int, int> > mass1;
            for(int j = 0; j < sz(mass); j++)
            {
                int g1 = __gcd(mass[j].X, d[i]);
                if(g1 == 1)
                {
                    continue;
                }
                if(sz(mass1) == 0 || mass1.back().X != g1)
                {
                    mass1.push_back({g1, mass[j].Y});
                }
            }
            swap(mass, mass1);
            if(sz(mass) != 0)
            {
                 ans = max(ans, i - mass[0].Y + 2);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long

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
        cin >> n;
        vector <int> d(n);
        for(int i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        sort(d.begin(), d.end());
        ll s = d[n - 1];
        for(int i = 0; i < n - 1; i++)
        {
            s -= 1LL * (d[i + 1] - d[i]) * (i + 1) * (n - i - 1);
        }
        cout << s<< "\n";
    }
    return 0;
}
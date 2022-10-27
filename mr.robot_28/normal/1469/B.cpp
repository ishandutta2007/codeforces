#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> r(n);
        int sum1 = 0, sum2 = 0, ans1 = 0, ans2 = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> r[i];
            sum1 += r[i];
            ans1 = max(ans1, sum1);
        }
        int m;
        cin >> m;
        vector <int> b(m);
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
            sum2 += b[i];
            ans2 = max(ans2, sum2);
        }
        cout << ans1 + ans2 << "\n";
    }
    return 0;
}
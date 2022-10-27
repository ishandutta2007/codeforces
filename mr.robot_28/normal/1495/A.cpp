#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
#define ld long double

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
        vector <int> x1, x2;
        for(int i = 0; i < n * 2; i++)
        {
            int a, b;
            cin >> a >>b;
            if(a == 0)
            {
                x2.push_back(abs(b));
            }
            else
            {
                x1.push_back(abs(a));
            }
        }
        sort(x1.begin(), x1.end());
        sort(x2.begin(), x2.end());
        ld ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += sqrt(x1[i] * x1[i] + x2[i] * x2[i]);
        }
        cout << fixed << setprecision(10) << ans << "\n";
    }
    return 0;
}
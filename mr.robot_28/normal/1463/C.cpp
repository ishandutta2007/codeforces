#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;

signed main()
{
 //   ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> x(n), t(n);
        for(int i = 0; i < n; i++)
        {
            cin >> t[i] >> x[i];
        }
        int x1 = 0;
        int go_to = 0;
        int t0 = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int u = min(t[i] - t0, abs(go_to - x1));
         //   cout << "A " << u << " ";
            if(go_to > x1)
            {
                x1 += u;
            }
            else
            {
                x1 -= u;
            }
            int fl = 0;
            if(i == n - 1)
            {
                if(x1 == go_to)
                {
                    fl = 1;
                }
                else if(min(x1, go_to) <= x[i] && max(x1, go_to) >= x[i])
                {
                    fl = 1;
                }
            }
            else
            {
                if(x1 == go_to)
                {
                    if(abs(x[i] - x1) <= t[i + 1] - t[i])
                    {
                        fl = 1;
                    }
                    go_to = x[i];
                }
                else{
                    int t1 = min(abs(go_to - x1), t[i + 1] - t[i]);
                    if(go_to < x1)
                    {
                        t1 *=  -1;
                    }
                    if(max(t1 + x1, x1) >= x[i] && min(t1 + x1, x1) <= x[i])
                    {
                        fl = 1;
                    }
                }
            }
            ans += fl;
            t0 = t[i];
         //   cout << fl << " ";
        }
        cout << ans << "\n";
    }
    return 0;
}
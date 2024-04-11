
#include <bits/stdc++.h>
using namespace std;
//#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector <int> c(n);
        for(int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        int ans = 1e9;
        for(int a = 1; a <= 100; a++)
        {
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(c[i] != a)
                {
                    cnt++;
                    i = i + k - 1;
                }
            }
            ans = min(ans, cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}
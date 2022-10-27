#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int pred = -1e9;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if(pred < a)
            {
                ans++;
                pred = a;
            }
            else if(pred == a)
            {
                pred = a + 1;
                ans++;
            }
            else
            {
                pred = a + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
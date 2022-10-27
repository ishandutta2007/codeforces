#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector <int> x(n);
        for(int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        sort(x.begin(), x.end());
        int w = 0;
        for(int i = 0; i < n - 1; i++)
        {
            w = __gcd(w, x[i + 1] - x[i]);
        }
        if(abs(k - x[0]) % w == 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
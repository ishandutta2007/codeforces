
#include <bits/stdc++.h>
using namespace std;
//#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if(n >= 3)
    {
    for(int i = 0; i < n - 2; i++)
    {
        int b = a[i + 1] ^ a[i + 2];
        if(b < a[i])
        {
            cout << 1;
            return 0;
        }
    }
    }
    int ans = 1e9;
    for(int i = 0; i < n; i++)
    {
        int xor1 = 0;
        for(int j = i; j >= 0; j--)
        {
            xor1 = xor1 ^ a[j];
            int xor2 = 0;
            for(int k = i + 1; k < n; k++)
            {
                xor2 = xor2 ^ a[k];
                if(xor1 > xor2)
                {
                    ans = min(ans, i - j + k - i - 1);
                }
            }
        }
    }
    if(ans == 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
    return 0;
}
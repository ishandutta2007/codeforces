#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 2e5 + 5;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int ans;
        string s;
        cin >> s;
        ans = s.size();
        int k0 = 0, k1 = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '0')
                k0++;
            else
                k1++;
        ans = min(k1, k0);
        ///000111
        int x1 = 0, x0 = k0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                x1++;
            else
                x0--;
            ans = min(ans, x0 + x1);
        }
        ///1111000
        x0 = 0, x1 = k1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                x1--;
            else
                x0++;
            ans = min(ans, x0 + x1);
        }
        cout << ans << "\n";
    }
    return 0;
}
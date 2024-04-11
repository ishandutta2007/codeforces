#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(q) (q).begin(), (q).end()
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
        string s;
        cin >> s;
        int lst[4];
        lst[1] = lst[2] = lst[3] = -1;
        int ans = 1e9;
        for (int i = 0; i < s.size(); i++) {
            lst[s[i] - '0'] = i;
            int l = min(lst[1], min(lst[2], lst[3]));
            if (l != -1)
                ans = min(ans, i - l + 1);
        }
        if (ans == 1e9)
            cout << "0\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 1e5 + 5;

int n, k, z, a[N];

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
        for (int i = 0; i < 10; i++)
            a[i] = 0;
        int mx = 0;
        for (int i = 0; i < s.size(); i++)
            a[s[i] - '0']++, mx = max(mx, a[s[i] - '0']);
        int ans = s.size() - mx;
        for (int x = 0; x < 10; x++)
            for (int y = 0; y < 10; y++) {
                int cur = 0, pos = 0;
                while (cur < s.size()) {
                    if (pos % 2 == 0) {
                        while (cur < s.size() && s[cur] - '0' != x)
                            cur++;
                        if (cur == s.size())
                            break;
                    } else {
                        while (cur < s.size() && s[cur] -'0' != y)
                            cur++;
                        if (cur == s.size())
                            break;
                    }
                    pos++;
                    cur++;
                }
                if (pos % 2 == 1)
                    pos--;
                ans = min(ans, (int)s.size() - pos);
            }
        cout << ans << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N = 3e5 + 5;
const long long M = 1e9 + 7;
const long long inf = 1e18;

int bal[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t > 0) {
        t--;
        string s;
        int n, x;
        cin >> n >> x;
        cin >> s;
        s = '1' + s;
        for (int i = 1; i <= n; i++)
            if (s[i] == '0')
                bal[i] = bal[i - 1] + 1;
            else
                bal[i] = bal[i - 1] - 1;
        if (bal[n] == 0) {
            bool was = 0;
            for (int i = 0; i <= n; i++)
                if (bal[i] == x)
                    was = 1;
            if (was)
                cout << "-1\n";
            else
                cout << "0\n";
        }
        if (bal[n] > 0) {
            int ans = 0;
            for (int i = 1; i <= n; i++)
                if (bal[i] <= x && (x - bal[i]) % bal[n] == 0)
                    ans++;
            if (x == 0)
                ans++;
            cout << ans << "\n";
        }
        if (bal[n] < 0) {
            int ans = 0;
            for (int i = 1; i <= n; i++)
                if (bal[i] >= x && (bal[i] - x) % bal[n] == 0)
                    ans++;
            if (x == 0)
                ans++;
            cout << ans << "\n";
        }
        //cout << s << ' ' << t <<  endl;
    }
    return 0;
}
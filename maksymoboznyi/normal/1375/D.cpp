#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 3e5 + 5;

int n, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> ans;
        int state = 0;
        while (1) {
            bool is = 1;
            for (int i = 1; i < n; i++)
                if (a[i] > a[i + 1])
                    is = 0;
            if (is)
                break;
            int mx;
            vector<int> b;
            for (int i = 1; i <= n; i++)
                b.pb(a[i]);
            sort(b.begin(), b.end());
            mx = b[n - 1] + 1;
            if (b[0] != 0)
                mx = 0;
            else
                for (int i = 1; i < b.size(); i++)
                    if (b[i] - b[i - 1] > 1) {
                        mx = b[i - 1] + 1;
                        break;
                    }
            if (mx != n)
                a[mx + 1] = mx, ans.pb(mx + 1);
            else {
                for (int i = 1; i <= n; i++)
                    if (a[i] != i - 1) {
                        a[i] = mx;
                        ans.pb(i);
                        break;
                    }
            }
            /*cout << mx << endl;
            for (int i = 1; i <= n; i++)
                cout << a[i] <<  ' ';\
            cout << endl;*/
        }
        /*for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << "\n";
*/
        if (ans.size() > 2 * n)
            while (1)
            n = n;
        cout << ans.size() << "\n";
        for (auto p: ans)
            cout << p << ' ';
        cout << "\n";
    }
    return 0;
}
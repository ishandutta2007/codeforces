#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 3e5 + 5;

int n, a[N], b[N];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        vector<int> c0, c1;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++) {
            cin >> a[i];
            if (a[i] % 2)
                c1.pb(i);
            else
                c0.pb(i);
        }
        if (c0.size() % 2) {
            c0.pop_back();
            c1.pop_back();
        } else {
            if (c0.size() > 0)
                c0.pop_back(), c0.pop_back();
            else
                c1.pop_back(), c1.pop_back();
        }
        int x = c1.size();
        while (c1.size() > 0)
            cout << c1[c1.size() - 2] << ' ' << c1[c1.size() - 1] << "\n", c1.pop_back(), c1.pop_back();

        while (c0.size() > 0)
            cout << c0[c0.size() - 2] << ' ' << c0[c0.size() - 1] << "\n", c0.pop_back(), c0.pop_back();
    }
    return 0;
}
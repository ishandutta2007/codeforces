#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 3e5 + 5;

int n, a[N], b[N], m, pref[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t) {
        t--;
        cin >> n;
        m = 0;
        vector<int> b;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i > 1 && a[i] != -1 && a[i - 1] != -1)
                m = max(m, abs(a[i] - a[i - 1]));
            if (i > 1 && a[i - 1] == -1 && a[i] != -1)
                b.pb(a[i]);
            if (i > 1 && a[i - 1] != -1 && a[i] == -1 && (b.size() == 0 || b.back() != a[i - 1]))
                b.pb(a[i - 1]);
        }
        if (b.size() == 0) {
            cout << "0 0\n";
            continue;
        }
        sort(b.begin(), b.end());
        if (b.back() == b[0]) {
            cout << m << ' ' << b[0] << "\n";
            continue;
        }
        int del = (b.back() - b[0] - 1) / 2 + 1;
        cout << max(m, del) << ' ' << b[0] + del << "\n";
    }

    return 0;
}
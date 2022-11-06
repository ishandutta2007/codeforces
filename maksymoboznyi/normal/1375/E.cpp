#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 1e3 + 3;

int n, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] = a[i] * 10000 + i;
    vector<pi> ans1;
    for (int i = n; i > 1; i--) {
        vector<pi> inv;
        for (int j = 1; j < i; j++)
            if (a[j] > a[i])
                inv.pb({a[j], j});
        sort(all(inv));
        for (auto p: inv)
            ans1.pb({p.second, i});
    }
    vector<pi> ans2;
    for (auto p: ans1)
        if (a[p.first] / 10000 != a[p.second] / 10000)
            ans2.pb({min(p.first, p.second), max(p.first, p.second)});
    cout << ans2.size() << "\n";
    for (auto p: ans2)
        cout << p.first << ' ' << p.second << "\n";
    return 0;
}
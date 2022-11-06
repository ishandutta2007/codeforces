#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define pi pair<int, int>
using namespace std;

const int N = 2e5 + 5;

int n, a[N], k, ans = 1e18, l[N], r[N], lkol[N], rkol[N];

signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    vector<pi> p;
    p.pb({a[1], 1});
    for (int i = 2; i <= n; i++)
        if (a[i] == a[i - 1])
            p.back().second++;
        else
            p.pb({a[i], 1});
    int sum = 0, kol = 0;
    for (int i = 0; i < p.size(); i++) {
        l[i] = kol * (p[i].first - 1) - sum;
        lkol[i] = kol;
        kol += p[i].second;
        sum += p[i].first * p[i].second;
    }
    sum = 0, kol = 0;
    for (int i = p.size() - 1; i >= 0; i--) {
        r[i] = sum - kol * (p[i].first + 1);
        rkol[i] = kol;
        kol += p[i].second;
        sum += p[i].first * p[i].second;
    }
    for (int i = 0; i < p.size(); i++) {
        if (p[i].second >= k) {
            cout << 0;
            return 0;
        }
        if (p[i].second + lkol[i] >= k)
            ans = min(ans, l[i] + k - p[i].second);
        if (p[i].second + rkol[i] >= k)
            ans = min(ans, r[i] + k - p[i].second);
        ans = min(ans, l[i] + r[i] + k - p[i].second);
    }
    cout << ans;
    return 0;
}
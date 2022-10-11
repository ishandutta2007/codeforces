#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()

ll get(int L, int R) {
    if (L > R)
        return 0;
    ll len = R - L + 1;
    return (len + 1) * len / 2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;
    vector<ll> pref(n + 1);
    pref[0] = 0;
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    map<ll, int> mapa;
    vector<pair<int, int>> bads;
    for (int i = 0; i <= n; i++)
        mapa[pref[i]] = -1;
    mapa[pref[0]] = 0;
    for (int i = 0; i < n; i++) {
        int cur = mapa[pref[i + 1]];
        if (cur != -1)
            bads.emplace_back(cur, i);
        mapa[pref[i + 1]] = i + 1;
    }
    if (bads.size() == 0)
        return cout << get(0, n - 1), 0;
    ll ans = 0;
    ll left = bads[0].first + 1;
    for (int i = 0; i < bads.size(); i++) {
        ll right;
        if (i == bads.size() - 1)
            right = n - bads[i].second;
        else
            right = bads[i + 1].second - bads[i].second;
        left = max(left, bads[i].first + 1);
        ans += right * left;
    }
    cout << get(0, n - 1) - ans << '\n';
}
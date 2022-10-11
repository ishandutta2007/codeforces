#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define len(a) int(a.size())
#define all(a) (a).begin(), (a).end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    k++;
    vector<int> c(n);
    for (auto &x : c) {
        cin >> x;
    }

    sort(all(c));
    priority_queue<ll> pq;
    for (int i = 0; i < k; i++) {
        pq.push(0);
    }

    ll ans = 0;
    reverse(all(c));
    for (auto x : c) {
        ll mx = pq.top();
        pq.pop();
        ans += mx;
        mx += x;
        pq.push(mx);
    }
    cout << ans << '\n';
}
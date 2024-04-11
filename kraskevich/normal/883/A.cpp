#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

ll n, m, a, d;
vector<ll> t;
ll ptr_a;
ll ptr_e;
ll ans;
ll block;

void make_next_move() {
    if (ptr_e == m) {
       ans += (n - ptr_a + block - 1) / block;
       ptr_a = n;
       return;
    }
    if (ptr_a == n) {
        ans++;
        int r = ptr_e;
        while (r < m && t[r] - t[ptr_e] <= d)
            r++;
        ptr_e = r;
        return;
    }

    if ((ptr_a + 1) * a + d < t[ptr_e]) {
        ll l = 0;
        ll r = (n - ptr_a + block - 1) / block;
        assert(r > 0);
        while (r - l > 1) {
            int mid = (l + r) / 2;
            ll start_a = mid * block * a + (ptr_a + 1) * a;
            if (start_a + d < t[ptr_e])
                l = mid;
            else
                r = mid;
        }
        ans += r;
        ptr_a += block * r;
        ptr_a = min(ptr_a, n);
        return;
    }

    ll start = min((ptr_a + 1) * a, t[ptr_e]);
    ll end = start + d;
    while (ptr_e < m && t[ptr_e] <= end)
        ptr_e++;
    ans++;
    ptr_a = max(ptr_a, min(n, end / a));
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m >> a >> d;
    t.resize(m);
    for (auto& x : t)
        cin >> x;
    block = d / a + 1;
    while (ptr_a < n || ptr_e < m)
        make_next_move();
    cout << ans << "\n";
}
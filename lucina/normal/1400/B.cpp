#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
using ll = int64_t;

void solve() {
    int x, y;
    cin >> x >> y;
    int n, m;
    cin >> n >> m;
    int s, w;
    cin >> s >> w;

    int ans = 0;

    for (int i = 0 ; i <= n ; ++ i) {
        ll sum = s * i;
        if (sum > x) break;
        int has_res = x - sum;
        int cur = i;
        int can = min(m, has_res / w);
        cur += can;
        int has_w = m - can;
        int has_s = n - i;
        auto p = make_pair(w, has_w);
        auto q = make_pair(s, has_s);
        if (p > q) swap(p, q);
        int cur_y = y;
        can = min(p.second, cur_y / p.first);
        cur_y -= can * p.first;
        cur += can;
        can = min(q.second, cur_y / q.first);
        cur += can;
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}
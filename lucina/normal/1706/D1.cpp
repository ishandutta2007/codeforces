#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
int a[nax];

void solve() {
    cin >> n >> k;

    int mx_v = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        mx_v = max(mx_v, a[i]);
    }
    int ans = 1e9;

    for (int mx = 0 ; mx <= mx_v ; ++ mx) {
        vector <int> g;
        for (int i = 1 ; i <= n ; ++ i) {
            if (a[i] > mx) {
                int r = (mx == 0) ? k : a[i] / mx;
                r = max(1, r - 1);
                r = min(r, k);
                int v = a[i];
                while (v / r > mx && r < k) {
                    r += 1;
                }
                if (v / r <= mx) g.push_back(v / r);
            } else g.push_back(a[i]);
        }
        if (g.size() != n) continue;
        sort(g.begin(), g.end());


        if (g.back() == mx) {
            ans = min(ans, g.back() - g[0]);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    rated div.2, quite a while though
*/
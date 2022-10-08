
#pragma GCC optimize("Ofast") // why not

#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// only consider adjacent differences
// process adjacent differences in decreasing order
// how many intervals contain the given adjacent difference (and not larger adjacent differences)?
// . . . . . [ ] . .

const int N = 1e5 + 5;
int n, q, l, r, le[N], ri[N];
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];
    vector<pair<ll, int>> ve;
    rep(i, 1, n) {
        ve.emplace_back(abs(a[i] - a[i - 1]), i);
    }
    sort(ve.rbegin(), ve.rend());
    set<int> s;
    for(auto &p : ve) {
        int i = p.se;
        auto it = s.lower_bound(i);
        ri[i] = (it == s.end() ? 1e9 : *it);
        le[i] = (it == s.begin() ? -1e9 : *(--it));
        s.insert(i);
    }
    while(q--) {
        cin >> l >> r;
        r--;
        ll ans = 0;
        for(auto &p : ve) {
            auto [dif, i] = p;
            if(l <= i && i <= r) {
                ans += dif * (min(r + 1, ri[i]) - i) * (i - max(l - 1, le[i]));
            }
        }
        cout << ans << '\n';
    }
}
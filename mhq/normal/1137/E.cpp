#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m;
vector < pair < ll, ll > > lines;
const ld eps = 1e-9;
void add(ll x, ll y) {
    while (lines.size() >= 2) {
        ld t1 = (lines[lines.size() - 2].second - lines.back().second) / (1.0 * ((lines.back().first - lines[lines.size() - 2].first)));
        ld t2 = (lines.back().second - y) / (1.0 * x - lines.back().first);
        if (t2 <= t1 + eps) break;
        lines.pop_back();
    }
    lines.emplace_back(x, y);
}
ll get(pair < ll, ll >& x, ll t) {
    return x.first * t + x.second;
}
pair < ll, ll > getMin(ll v) {
    int l = 0;
    int r = lines.size() - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (get(lines[m], v) > get(lines[m + 1], v)) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return make_pair(get(lines[l], v), lines[l].first);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  //  freopen("input.txt", "r", stdin);
    cin >> n >> m;
    ll cur_len = n;
    ll cur_val = 0;
    ll shift = 0;
    ll cur_s = 0;
    lines.emplace_back(0, 0);
    for (int i = 1; i <= m; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int k;
            cin >> k;
            cur_len += k;
            cur_val = 0;
            cur_s = 0;
            shift = 0;
            lines.clear();
            lines.emplace_back(0, 0);
            cout << 1 << " " << 0 << '\n';
        }
        else if (tp == 2) {
            int k;
            cin >> k;
            add(cur_len, lines.back().second + cur_s * (lines.back().first - cur_len) - cur_val);
            cur_val = 0;
            cur_len += k;
            auto it = getMin(cur_s);
            shift = get(lines.back(), cur_s);
            cout << it.second + 1 << " " << it.first - shift << '\n';
        }
        else {
            ll b, s;
            cin >> b >> s;
            cur_val += lines.back().first * s + b;
            cur_s += s;
            auto it = getMin(cur_s);
            cout << it.second + 1 << " " << it.first + (cur_val - get(lines.back(), cur_s)) << '\n';
        }
    }

}
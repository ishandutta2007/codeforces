#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

struct bit {
    vector<ll> f;

    bit(int n): f(n) {}

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            res += f[i];
        return res;
    }

    void upd(int i, ll d) {
        for (; i < (int)f.size(); i = (i | (i + 1)))
            f[i] += d;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> suf_max(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    suf_max[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf_max[i] = max(a[i], suf_max[i + 1]);

    vector<int> bs(m);
    vector<int> ps(m);
    for (int& x : bs)
        cin >> x;
    for (int& x : ps)
        cin >> x;

    vector<pii> events;
    for (int i = 0; i < m; i++) {
        int b = bs[i];
        int p = ps[i];
        if (suf_max[0] < b)
            continue;
        int l = 0;
        int r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (suf_max[mid] >= b)
                l = mid;
            else
                r = mid;
        }
        events.emplace_back(p, l);
    }
    sort(events.begin(), events.end());
    bit t(n);
    set<int> alive;
    for (int i = 0; i < n; i++) {
        t.upd(i, a[i]);
        alive.insert(i);
    }
    int ans = 0;
    for (auto e : events) {
        if (t.get(e.second) < e.first)
            continue;
        ans++;
        auto it = alive.upper_bound(e.second);
        --it;
        int pos = *it;
        int rem = e.first;
        while (rem > 0) {
            int delta = min(rem, a[pos]);
            a[pos] -= delta;
            t.upd(pos, -delta);
            rem -= delta;
            if (a[pos] == 0) {
                alive.erase(pos);
                if (rem != 0) {
                    --pos;
                    it = alive.upper_bound(pos);
                    --it;
                    pos = *it;
                }
            }
        }
    }
    cout << ans << "\n";
}
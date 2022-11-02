#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct MaxDelta {
    multiset<ll> q;
    ll sum = 0;
    int k;

    MaxDelta(int k_): k(k_) {}

    void add(ll num, bool check) {
        if (num <= 0)
            return;
        q.insert(num);
        sum += num;
        if (q.size() > k && check) {
            sum -= *q.begin();
            q.erase(q.begin());
        }
    }

    void del(ll num) {
        auto it = q.find(num);
        if (it == q.end())
            return;
        sum -= *it;
        q.erase(it);
    }

    ll get() {
        if (q.size() <= k)
            return sum;
        ll ans = sum;
        auto it = q.begin();
        for (int i = 0; i < int(q.size()) - k; i++) {
            ans -= *it;
            ++it;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(20);

    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> h(n);
    vector<ll> d(n);
    ll tot = 0;
    MaxDelta delta(b);
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> d[i];
        tot += d[i];
        delta.add(h[i] - d[i], true);
    }
    ll ans = tot + delta.get();
    for (int i = 0; i < n; i++) {
        delta.del(h[i] - d[i]);
        delta.add((h[i] << a) - d[i], false);
        ans = max(ans, tot + delta.get());
        delta.del((h[i] << a) - d[i]);
        delta.add(h[i] - d[i], true);
    }
    cout << ans << "\n";
}
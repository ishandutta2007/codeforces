#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int n;
vector<ll> v;
int k;

bool can(ll max_diff) {
    vector<ll> s(n + 1);
    s[0] = 1;
    int l = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1];
        while (v[l] < v[i - 1] - max_diff)
            l++;
        assert(l <= i - 1);
        int R = i - k;
        int L = l;
        if (L > R)
            continue;
        int cur = s[R];
        if (L)
            cur -= s[L - 1];
        s[i] += cur > 0;
    }
    return s[n] - s[n - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> k;
    v.resize(n);
    for (auto& x : v)
        cin >> x;
    sort(v.begin(), v.end());

    ll l = -1;
    ll r = v.back() - v[0];
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (can(m))
            r = m;
        else
            l = m;
    }
    cout << r << "\n";
}
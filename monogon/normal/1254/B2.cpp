
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e6 + 5;
int n;
ll a[N];
ll b[N];

ll getcost(const vector<pair<int, ll>> &v, int k) {
    ll cost = 0;
    for(auto p : v) {
        cost += abs(p.first - k) * p.second;
    }
    return cost;
}

ll ternary(const vector<pair<int, ll>> &v) {
    int l = v[0].first, r = v.back().first;
    while(r - l >= 3) {
        int m1 = l + (r - l) / 3;
        int m2 = l + 2 * (r - l) / 3;
        ll c1 = getcost(v, m1);
        ll c2 = getcost(v, m2);
        if(c1 < c2) {
            r = m2 - 1;
        }else if(c1 > c2) {
            l = m1 + 1;
        }else {
            l = m1;
            r = m2;
        }
    }
    ll c = getcost(v, l);
    for(int i = l + 1; i <= r; i++) {
        c = min(c, getcost(v, i));
    }
    return c;
}

ll getcost(ll k) {
    vector<pair<int, ll>> v;
    ll cost = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++) b[i] = a[i];
    for(int i = 0; i < n; i++) {
        if(b[i] >= k - cnt) {
            v.emplace_back(i, k - cnt);
            cost += ternary(v);
            b[i] = (b[i] - (k - cnt)) % k;
            i--;
            cnt = 0;
            v.clear();
        }else {
            v.emplace_back(i, b[i]);
            cnt += b[i];
            b[i] = 0;
        }
    }
    return cost;
}

ll solve(ll K) {
    ll mincost = LLONG_MAX;
    for(ll k = 2; k * k <= K; k++) {
        if(K % k == 0) {
            mincost = min(mincost, getcost(k));
            while(K % k == 0) K /= k;
        }
    }
    if(K > 1) mincost = min(mincost, getcost(K));
    return mincost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll k = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k += a[i];
    }
    if(k <= 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << solve(k) << endl;
}
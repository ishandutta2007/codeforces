#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, k, m;
const int maxN = (int)1e5 + 10;
int a[maxN];
int w[maxN];
int tp[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector < pair < int, int > > all;
    for (int i = 1; i <= n; i++) {
        if (all.empty()) {
            all.push_back(make_pair(a[i], 1));
        }
        else {
            auto t = all.back();
            if (t.first != a[i]) {
                all.push_back(make_pair(a[i], 1));
            }
            else {
                t.second++;
                t.second %= k;
                if (t.second == 0) all.pop_back();
                else {
                    all.pop_back();
                    all.push_back(t);
                }
            }
        }
    }
    int sz = all.size();
    for (int i = 1; i <= sz; i++) {
        tp[i] = all[i - 1].first;
        w[i] = all[i - 1].second;
    }
    if (sz == 0) {
        cout << 0;
        return 0;
    }
    if (sz == 1) {
        cout << (1LL * m * w[1]) % k;
        return 0;
    }
    ll sum = 0;
    for (int i = 1; i <= sz; i++) {
        sum += w[i];
    }
    if (m == 1) {
        cout << sum;
        return 0;
    }
    int l = 1;
    int r = sz;
    while (true) {
        if (l == r) {
            ll num = 1LL * w[l] * m;
            if (num % k == 0) {
                cout << 0;
            }
            else {
                cout << num % k + (sum - w[l]);
            }
            return 0;
            // if num == 0, all destroyed
        }
        if (tp[l] != tp[r]) {
            ll sum_without = 0;
            ll sum_in = 0;
            for (int i = 1; i <= sz; i++) {
                if (i < l || i > r) sum_without += w[i];
                else sum_in += w[i];
            }
            cout << m * sum_in + sum_without;
            return 0;
        }
        else if (l + 1 == r) {
            ll num = m * (w[l] + w[r]);
            if (num % k != 0) {
                cout << (sum - w[l] - w[r]) + num % k;
            }
            else {
                cout << 0;
            }
            return 0;
        }
        else {
            ll num = w[l] + w[r];
            if (num % k != 0) {
                ll sum_without = 0;
                ll sum_in = 0;
                for (int i = 1; i <= sz; i++) {
                    if (i < l || i > r) sum_without += w[i];
                    else if (i > l && i < r) sum_in += w[i];
                }
                cout << sum_without + m * sum_in + (m - 1) * (num % k) + (w[l] + w[r]);
                return 0;
            }
            else {
                l++;
                r--;
            }
        }
    }
    return 0;
}
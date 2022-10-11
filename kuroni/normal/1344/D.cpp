#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N], b[N];
long long ans = 0, k;
priority_queue<pair<long long, int>> pq;

pair<int, int> find_ans(int a, long long lim) {
    int l = 0, r = a - 1;
    bool eq = false;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a - 1 - 3LL * m * (m + 1) == lim) {
            eq = true;
        } 
        if (a - 1 - 3LL * m * (m + 1) >= lim) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return {l - eq, l};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long le = LLONG_MIN, ri = LLONG_MAX;
    while (le <= ri) {
        long long mi = (le + ri) / 2;
        long long lv = 0, rv = 0;
        for (int i = 1; i <= n; i++) {
            auto [l, r] = find_ans(a[i], mi);
            lv += l;
            rv += r;
        }
        if (lv > k) {
            le = mi + 1;
        } else if (rv < k) {
            ri = mi - 1;
        } else {
            int ov = k - lv;
            for (int i = 1; i <= n; i++) {
                auto [l, r] = find_ans(a[i], mi);
                if (l < r && ov > 0) {
                    cout << r << " ";
                    ov--;
                } else {
                    cout << l << " ";
                }
            }
            return 0;
        }
    }
}
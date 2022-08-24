#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 10;
const int INF = (int)1e9;
int n;
vector < pair < int, int > > by_x, by_y;
int x[maxN];
int y[maxN];
int copX[maxN], copY[maxN];
int max_left[maxN], max_right[maxN];
int suf_max[maxN], suf_min[maxN], pref_min[maxN], pref_max[maxN];
bool check(ll val) {
    if ((1LL * pref_max[n - 1] - pref_min[n - 1]) * (1LL * pref_max[n - 1] - pref_min[n - 1]) <= val) return true;
    int l = 0;
    for (int i = 0; i < n; i++) {
        while (l + 1 < n && (1LL * x[l + 1] - x[i]) * (x[l + 1] - x[i]) <= val) l++;
        max_right[i] = l;
    }
    int r = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (r - 1 >= 0 && (1LL * x[i] - x[r - 1]) * (x[i] - x[r - 1]) <= val) r--;
        max_left[i] = r;
    }
    for (int i = 0; i < n; i++) {
    }
    for (int i = 0; i < n; i++) {
        int lim = abs(x[i]);
        int l = -1;
        int r = -1;
        if (x[i] < 0) {
            int upper = n - 1;
            if (x[n - 1] > lim) {
                upper = upper_bound(x, x + n, lim) - x;
                upper--;
            }
            upper = min(upper, max_right[i]);
            l = i;
            r = upper;
        }
        else {
            int down = 0;
            if (x[0] < -lim) {
                down = lower_bound(x, x + n, -lim) - x;
            }
            down = max(down, max_left[i]);
            l = down;
            r = i;
        }
        if (r - l + 1 == n) return true;
        int mx = -INF;
        int mn = INF;
        if (l > 0) {
            mx = max(mx, pref_max[l - 1]);
            mn = min(mn, pref_min[l - 1]);
        }
        if (r < (n - 1)) {
            mx = max(mx, suf_max[r + 1]);
            mn = min(mn, suf_min[r + 1]);
        }
        if ((1LL * mx - mn) * (1LL * mx - mn) > val) continue;
        int mx_d = max(abs(mx), abs(mn));
        if (1LL * mx_d * mx_d + 1LL * lim * lim > val) continue;
        return true;
    }
    return false;
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        copX[i] = x[i];
        copY[i] = y[i];
        by_x.push_back(make_pair(x[i], i));
    }
    sort(by_x.begin(), by_x.end());
    for (int i = 0; i < n; i++) {
        x[i] = copX[by_x[i].second];
        y[i] = copY[by_x[i].second];
        by_y.push_back(make_pair(y[i], i));
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            pref_max[i] = y[i];
            pref_min[i] = y[i];
        }
        else {
            pref_max[i] = max(pref_max[i - 1], y[i]);
            pref_min[i] = min(pref_min[i - 1], y[i]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            suf_max[i] = y[i];
            suf_min[i] = y[i];
        }
        else {
            suf_max[i] = max(suf_max[i + 1], y[i]);
            suf_min[i] = min(suf_min[i + 1], y[i]);
        }
    }
    ll l = 0;
    ll r = 2 * (ll)1e18;
    if (check(l)) {
        cout << 0;
        return 0;
    }
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
    return 0;
}
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e6 + 100;
int n, x;
int a[maxN];
bool is_sorted(int l, int r) {
    int lst = 0;
    for (int i = 1; i <= n; i++) {
        if (l <= a[i] && a[i] <= r) {
            if (lst > a[i]) return false;
            lst = a[i];
        }
    }
    return true;
}
vector < int > byVal[maxN];
int max_pos[maxN];
int min_pos[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        byVal[a[i]].push_back(i);
    }
    int mx_l = x + 1;
    int mn_l = 1;
    if (is_sorted(1, mx_l - 1)) {
        cout << (1LL * x * (x + 1)) / 2;
        return 0;
    }
    while (mx_l - mn_l > 1) {
        int mid = (mx_l + mn_l) / 2;
        if (is_sorted(1, mid - 1)) mn_l = mid;
        else mx_l = mid;
    }
    mx_l = mn_l;
    // mx_l - ok
    int mn_r = 0;
    int mx_r = x;
    while (mx_r - mn_r > 1) {
        int mid = (mx_r + mn_r) / 2;
        if (is_sorted(mid + 1, x)) mx_r = mid;
        else mn_r = mid;
    }
    mn_r = mx_r;
    // mn_r - ok
    //  cout << mx_l << " " << mn_r << endl;
  //  assert(mx_l <= mn_r);
    max_pos[0] = 0;
    for (int i = 1; i <= mx_l - 1; i++) {
        max_pos[i] = max_pos[i - 1];
        for (int v : byVal[i]) {
            max_pos[i] = max(max_pos[i], v);
        }
    }
    min_pos[x + 1] = n + 100;
    for (int i = x; i >= mn_r + 1; i--) {
        min_pos[i] = min_pos[i + 1];
        for (int v : byVal[i]) {
            min_pos[i] = min(min_pos[i], v);
        }
    }
    ll ans = 0;
    int ri = mx_r;
    for (int le = 1; le <= mn_l; le++) {
        while (le > ri) ri++;
        while (max_pos[le - 1] >= min_pos[ri + 1]) ri++;
        ans += (x - ri + 1);
    }
    cout << ans;
    return 0;
}
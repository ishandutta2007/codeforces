#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 4 * (int)1e5 + 10;
int a[maxN];
int n;
int cur_val[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector < int > f;
    for (int i = 1; i <= n; i++) f.push_back(i);
    int xr = 0;
    for (int bit = 0; ; bit++) {
        if ((1 << bit) >= 2e7) break;
        vector<int> nf;
        for (int v : f) {
            if (!(a[v] & (1 << (bit)))) nf.push_back(v);
        }
        for (int v : f) {
            if (a[v] & (1 << (bit))) nf.push_back(v);
        }
        f = nf;
        vector < int > all_vals;
        for (int v : f) {
            cur_val[v] = a[v] & ((1 << (bit + 1)) - 1);
            all_vals.emplace_back(cur_val[v]);
        }
        all_vals.emplace_back(1e9);
        int l = (1 << bit);
        int r = (1 << (bit + 1)) - 1;
        ll cnt = 0;
        for (int i = 1; i + 1 < all_vals.size(); i++) {
            int at_least = lower_bound(all_vals.begin(), all_vals.end(), l - all_vals[i]) - all_vals.begin();
            int at_most = lower_bound(all_vals.begin(), all_vals.end(), r + 1 - all_vals[i]) - all_vals.begin();

            at_most = min(at_most - 1, i - 1);
            cnt += max(0, at_most - at_least + 1);
        }
        l = (3 << bit);
        r = (4 << bit) - 1;
        for (int i = 1; i + 1 < all_vals.size(); i++) {
            int at_least = lower_bound(all_vals.begin(), all_vals.end(), l - all_vals[i]) - all_vals.begin();
            int at_most = lower_bound(all_vals.begin(), all_vals.end(), r + 1 - all_vals[i]) - all_vals.begin();
            at_most = min(at_most, i - 1);
            cnt += max(0, at_most - at_least + 1);
        }
        if (cnt & 1) {
            xr ^= (1 << bit);
        }
    }
    cout << xr;
    return 0;
}
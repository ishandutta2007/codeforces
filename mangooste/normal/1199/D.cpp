#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a)
        cin >> el;
    int q;
    cin >> q;
    vector<pii> last(n, mp(-1, -1));
    vector<pii> evs;
    for (int tt = 0; tt < q; tt++) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, val;
            cin >> i >> val, i--;
            last[i] = mp(tt, val);
            continue;
        }
        int x;
        cin >> x;
        evs.eb(tt, x);
    }
    int m = evs.size();
    vector<int> suf_max(m + 1, 0);  
    for (int i = m - 1; i >= 0; i--)
        suf_max[i] = max(suf_max[i + 1], evs[i].second);
    int mx = suf_max[0];
    for (int i = 0; i < n; i++) {
        if (last[i].first == -1) {
            cout << max(a[i], mx) << ' ';
            continue;
        }
        int val = last[i].second;
        int pos = lower_bound(all(evs), last[i]) - evs.begin();
        if (pos == evs.size() || suf_max[pos] < val)
            cout << val << ' ';
        else
            cout << suf_max[pos] << ' ';
    }
    cout << '\n';
}
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
    ll I;
    cin >> n >> I;
    I *= 8;
    vector<int> a(n);
    for (auto &el : a)
        cin >> el;
    sort(all(a));
    vector<pii> b;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        b.eb(a[i], j - i);
        i = j;
    }
    int m = b.size();
    vector<int> suf(m + 1);
    suf[m] = 0;
    for (int i = m - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + b[i].second;

    auto get_log = [](int val) {
        int cnt = 0;
        while ((1 << cnt) < val)
            cnt++;
        return cnt;
    };

    int k = 0;
    for (int i = 1; i <= n; i++)
        if (1ll * n * get_log(i) <= I)
            k = i;
    // cerr << "k = " << k << endl;
    // cerr << "b = ";
    // for (auto el : b)
    //     cerr << '(' << el.first << ' ' << el.second << ") ";
    // cerr << endl;
    const int INF = 1e6;
    int ans = INF;
    int pref = 0;
    for (int i = 0; i < m; i++) {
        int cur_ans = pref;
        int j = i + k;
        if (j <= m)
            cur_ans += suf[j];
        ans = min(ans, cur_ans);
        // cerr << "i = " << i << " cur_ans = " << cur_ans << endl;
        pref += b[i].second;
    }
    cout << ans << '\n';
}
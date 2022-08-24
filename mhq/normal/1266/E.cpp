#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
set < pair < pair < int, int >, int > > ss;
int cnt[maxN];
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    ll cur = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int s, t, u;
        cin >> s >> t >> u;
        auto it = ss.lower_bound({make_pair(s, t), -1});
        if (it != ss.end() && ((it -> first) == make_pair(s, t))) {
            cur -= min(a[it -> second], cnt[it -> second]);
            cnt[it -> second]--;
            cur += min(a[it -> second], cnt[it -> second]);
            ss.erase(it);
        }
        if (u != 0) {
            ss.insert({make_pair(s, t), u});
            cur -= min(a[u], cnt[u]);
            cnt[u]++;
            cur += min(a[u], cnt[u]);
        }
        cout << sum - cur << '\n';
    }
    return 0;
}
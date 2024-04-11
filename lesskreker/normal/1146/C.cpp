#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size()); };
mt19937 rng((size_t) make_shared<char>().get());

int ask(const vector<int>& a, const vector<int>& b) {
    if (!isz(a) || !isz(b)) {
        return 0;
    }
    cout << isz(a) << " " << isz(b);
    for (int i : a) {
        cout << " " << i + 1;
    }
    for (int i : b) {
        cout << " " << i + 1;
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int main(int argc, char** argv) {
#ifdef VSE
    // if (argc > 1) assert(freopen(argv[1], "r", stdin));
    rng.seed(0);
#endif
#ifndef cin
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif

    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < 8; i++) {
            vector<int> a[2];
            for (int j = 0; j < n; j++) {
                a[(j >> i) & 1].push_back(j);
            }
            ans = max(ans, ask(a[0], a[1]));
        }
        cout << "-1 " << ans << endl;
    }

    return 0;
}
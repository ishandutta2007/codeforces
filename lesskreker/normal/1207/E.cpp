#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size()); };
mt19937 rng((size_t) make_shared<char>().get());

int main(int argc, char** argv) {
#ifdef VSE
    // if (argc > 1) assert(freopen(argv[1], "r", stdin));
    rng.seed(0);
#endif
#ifndef cin
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif

    auto ask = [](const vector<int>& a) {
        cout << "?";
        for (int i : a) {
            cout << " " << i;
        }
        cout << endl;
        int r;
        cin >> r;
        return r;
    };

    vector<int> a;
    for (int i = 1; i <= 100; i++) {
        a.push_back(i);
    }
    int a1 = ask(a);

    for (int i = 0; i < 100; i++) {
        a[i] <<= 7;
    }

    int a2 = ask(a);

    int ans = (a1 >> 7 << 7) | (a2 & ((1 << 7) - 1));
    cout << "! " << ans << endl;

    return 0;
}
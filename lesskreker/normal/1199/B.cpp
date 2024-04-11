#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size()); };
mt19937 rng((size_t) make_shared<char>().get());

// #include "lib/fastio.h"

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) assert(freopen(argv[1], "r", stdin));
    rng.seed(0);
#endif
#ifndef cin
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif

    long double h, l;
    cin >> h >> l;
    long double ang = atan2l(l, h);
    long double c2 = h * h + l * l;

    long double ans = c2 / (2 * (1 - cosl(acosl(-1) - 2 * ang)));

    cout << setprecision(11) << fixed;

    cout << sqrtl(ans) - h << "\n";

    return 0;
}
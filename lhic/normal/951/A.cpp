#ifndef BZ
#pragma GCC optimize -O3
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif

    string s;
    cin >> s;
    int n = s.length();
    s = s + s;
    int cur = 0;
    int ans = 0;
    char p = '#';
    for (char c: s) {
        if (c == p)
            cur = 0;

        ++cur;
        ans = max(ans, cur);
        p = c;
    }

    cout << min(ans, n) << "\n";
    return 0;
}
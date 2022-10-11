#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;
    if (s != string(s.rbegin(), s.rend())) {
        cout << len(s) << '\n';
    } else if (*min_element(all(s)) == *max_element(all(s))) {
        cout << "0\n";
    } else {
        cout << len(s) - 1 << '\n';
    }
}
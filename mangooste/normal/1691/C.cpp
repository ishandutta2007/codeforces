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

void solve(int test_num) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    if (count(all(s), '0') == n) {
        cout << "0\n";
        return;
    }

    int first = 0;
    while (s[first] == '0') first++;
    int last = n - 1;
    while (s[last] == '0') last--;

    if (first == last) {
        if (n - 1 - last <= k) {
            cout << "1\n";
        } else if (first <= k) {
            cout << "10\n";
        } else {
            cout << "11\n";
        }
        return;
    }

    int tot = 0;
    for (int i = 0; i + 1 < n; i++) {
        tot += s[i + 1] - '0';
        tot += 10 * (s[i] - '0');
    }
    
    if (last != n - 1 && n - 1 - last <= k) {
        k -= n - 1 - last;
        tot -= 10;
    }
    if (first != 0 && first <= k) {
        tot--;
    }
    cout << tot << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
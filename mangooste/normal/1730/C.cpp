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
    #define dprint(...)
#endif // LOCAL

void solve(int test_num) {
    string s;
    cin >> s;

    constexpr int A = 10;
    array<int, A> sum{};
    for (int d = 0, ptr = 0; d < A; d++) {
        cout << string(sum[d] + count(ptr + all(s), '0' + d), '0' + d);
        int pos = len(s) - 1;
        while (pos >= ptr && s[pos] - '0' != d) pos--;
        for (; ptr != pos + 1; ptr++) {
            if (s[ptr] != '0' + d) sum[min(s[ptr] - '0' + 1, 9)]++;
        }
        if (d == A - 1) assert(ptr == len(s));
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
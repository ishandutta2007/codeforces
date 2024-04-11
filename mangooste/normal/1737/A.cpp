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
    int n, k;
    string s;
    cin >> n >> k >> s;
    constexpr int A = 26;
    vector<int> cnt(A);
    for (auto c : s) cnt[c - 'a']++;
    
    vector<int> take(k);
    for (int i = 0, pos = k; i < A && take[0] < n / k; i++) {
        pos = min(pos, cnt[i]);
        for (int j = 0; j < pos; j++) {
            take[j]++;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << char('a' + take[i]);
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
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
    int n;
    string s;
    cin >> n >> s;

    constexpr int A = 26;
    vector<int> nxt(A, -1);
    vector<bool> is_start(A, true);

    for (auto c : s) {
        if (nxt[c - 'a'] != -1) {
            cout << char('a' + nxt[c - 'a']);
            continue;
        }

        for (int start = 0; start < A; start++) {
            if (!is_start[start]) continue;
            if (start == c - 'a') continue;
            int pos = start;
            while (nxt[pos] != -1) pos = nxt[pos];
            if (pos != c - 'a') {
                nxt[c - 'a'] = start;
                is_start[start] = false;
                break;
            }
        }

        if (nxt[c - 'a'] == -1) {
            assert(count(all(nxt), -1) == 1);
            assert(count(all(is_start), true) == 1);
            int pos = find(all(is_start), true) - is_start.begin();
            nxt[c - 'a'] = pos;
            is_start[pos] = false;
        }
        cout << char('a' + nxt[c - 'a']);
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
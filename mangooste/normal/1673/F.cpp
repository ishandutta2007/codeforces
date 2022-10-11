#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << (1 << (__builtin_ctz(j + 1) * 2)) << " \n"[j == n - 2];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            cout << (2 << (__builtin_ctz(i + 1) * 2)) << " \n"[j == n - 1];
        }
    }
    map<int, pair<int, int>> where;
    for (int i = 0, cur = 0; i < n; i++, cur ^= 2 << (__builtin_ctz(i) * 2)) {
        for (int j = 0, cur2 = cur; j < n; j++, cur2 ^= 1 << (__builtin_ctz(j) * 2)) {
            assert(!where.count(cur2));
            where[cur2] = {i, j};
        }
    }

    cout << flush;
    int pref_xor = 0;
    while (k--) {
        int value;
        cin >> value;
        pref_xor ^= value;
        assert(where.count(pref_xor));
        cout << where[pref_xor].first + 1 << ' ' << where[pref_xor].second + 1 << endl;
    }
}
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
    cin >> n >> k;

    auto query = [&](const vector<int> &first, const vector<int> &second) {
        cout << "? " << len(first) << ' ' << len(second) << '\n';
        for (int i = 0; i < len(first); i++) {
            cout << first[i] + 1 << "  \n"[i == len(first) - 1];
        }
        for (int i = 0; i < len(second); i++) {
            cout << second[i] + 1 << " \n"[i == len(second) - 1];
        }
        cout << flush;

        string res;
        cin >> res;
        if (res == "FIRST") {
            return 0;
        } else if (res == "SECOND") {
            return 1;
        } else if (res == "EQUAL") {
            return 2;
        } else {
            assert(false);
        }
    };

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    bool is_stone = true;
    for (int it = 0; it < 20; it++) {
        int pos = rng() % (n - 1) + 1;
        is_stone &= query({0}, {pos}) != 1;
    }
    if (!is_stone) {
        cout << "! 1" << endl;
        return;
    }

    auto get_range = [&](int from, int to) {
        vector<int> res(to - from);
        iota(all(res), from);
        return res;
    };

    int cnt_stones = 1, extra;
    while (true) {
        if (n - cnt_stones <= cnt_stones) {
            extra = n - cnt_stones;
            break;
        }
        if (query(get_range(0, cnt_stones), get_range(cnt_stones, 2 * cnt_stones)) == 0) {
            extra = cnt_stones;
            break;
        }
        cnt_stones <<= 1;
    }

    int l = 0, r = extra;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        (query(get_range(0, mid), get_range(cnt_stones, cnt_stones + mid)) == 0 ? r : l) = mid;
    }
    cout << "! " << cnt_stones + r << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
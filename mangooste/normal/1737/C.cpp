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
    cin >> n;
    vector<int> x(3), y(3);
    for (int i : {0, 1, 2}) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    int pos_x, pos_y;
    cin >> pos_x >> pos_y;
    pos_x--, pos_y--;

    cout << ([&]() -> bool {
        for (int i : {0, 1, 2}) {
            if (x[i] == pos_x && y[i] == pos_y) return true;
        }

        for (int rot = 0; rot < 2; rot++, swap(pos_x, pos_y), swap(x, y)) {
            int my_y = -1;
            for (int i : {0, 1, 2}) {
                if (count(all(y), y[i]) == 2) {
                    my_y = y[i];
                    break;
                }
            }
            if (my_y == pos_y) return true;
        }

        for (int val1 : {0, n - 1}) {
            for (int val2 : {0, n - 1}) {
                if (count(all(x), val1) == 2 && count(all(y), val2) == 2) {
                    return false;
                }
            }
        }

        dbg("here");
        for (int i : {0, 1, 2}) {
            for (int j : {0, 1, 2}) {
                if (!(x[i] != x[j] && y[i] != y[j])) continue;
                int k = 1 ^ 2 ^ i ^ j;
                int xx = x[k] + 1, yy = y[k];
                dbg(xx, yy);
                if ((pos_x + pos_y) % 2 == (xx + yy) % 2) return true;
                if (abs(pos_x - pos_y) % 2 == abs(xx - yy) % 2) return true;
            }
        }

        for (int rot = 0; rot < 2; rot++, swap(pos_x, pos_y), swap(x, y)) {
            int my_y = -1;
            for (int i : {0, 1, 2}) {
                if (count(all(y), y[i]) == 2) {
                    my_y = y[i];
                    break;
                }
            }
            if (my_y == pos_y) return true;
            assert(my_y != -1);
            if (pos_y % 2 == my_y % 2) return true;
        }

        return false;
    }() ? "YES" : "NO") << '\n';

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
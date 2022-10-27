#include<bits/stdc++.h>
using namespace std;
const int nax = 150;
int k;
int64_t a[nax];
int64_t f[nax];

/**
    it's almost unique, but 8 and 3 are troublesome cases,
    Instead, greedy from f[L] ..., f[0] and brute force with all number
    So, we do not have to care about 8 and 3
*/

bool solve() {
    cin >> k;
    int64_t s = 0;
    for (int i = 1 ; i <= k ; ++ i) {
        cin >> a[i];
        s += a[i];
    }
    int l = -1;

    while (s > 0) {
        s -= f[++ l];
    }
    if (s != 0) return false;

    int lst = -1;

    for (int i = l ; i >= 0 ; -- i) {
        int mx = *max_element(a + 1, a + 1 + k);
        if (mx < f[i]) return false;
        bool ok = false;
        for (int j = 1 ; j <= k ; ++ j) {
            if (a[j] == mx && lst != j) {
                a[j] -= f[i];
                lst = j;
                ok = true;
                break;
            }
        }
        if (!ok) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    /**
        3 can be either 3 or | 2 | | 1 |
        by this greedy we will choose 3 before 2, 1


        1 1 2 3
    */

    int T;

    f[0] = f[1] = 1;
    for (int i = 2 ; i <= 50 ; ++ i) {
        f[i] = f[i - 1] + f[i - 2];
    }

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
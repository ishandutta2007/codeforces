#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
bool used[1005];
void brute() {
    for (int i = 1; i <= 40; i++) {
        int a = -1;
        int b = -1;
        int c = -1;
        for (int j = 1; j <= 1000; j++) {
            if (!used[j]) {
                a = j;
                used[j] = true;
                for (int k = 1; k <= 1000; k++) {
                    if (!used[k] && !used[k ^ j]) {
                        b = k;
                        c = k ^ j;
                        used[k] = true;
                        used[k ^ j] = true;
                        break;
                    }
                }
                assert(b != -1);
                assert(c != -1);
                break;
            }
        }
        cout << a << " " << b << " " << c << '\n';
    }
}
ll n;
ll solve1(int bit, ll pos, int tp) {
    // take from 0 .. 2^(bit) - 1 each
    assert(bit % 2 == 0);
    if (bit == 0) {
        return 0;
    }
    if (tp == 0) {
        return pos;
    }
    int bt_small = bit - 2;
    if (pos < (1LL << bt_small)) return solve1(bt_small, pos, tp);
    ll f = 1LL << bt_small;
    if (pos >= f && pos < 2 * f) {
        ll T = solve1(bt_small, pos - f, tp);
        if (tp == 1) {
            return T + 2 * f;
        }
        else {
            return T + 3 * f;
        }
    }
    if (pos >= 2 * f && pos < 3 * f) {
        ll T = solve1(bt_small, pos - 2 * f, tp);
        if (tp == 1) {
            return T + 3 * f;
        }
        if (tp == 2) {
            return T + f;
        }
    }
    if (pos >= 3 * f && pos < 4 * f) {
        ll T = solve1(bt_small, pos - 3 * f, tp);
        if (tp == 1) {
            return T + f;
        }
        if (tp == 2) {
            return T + 2 * f;
        }
    }
    assert(false);
    return -228;


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n;
        n--;
        int tp = n % 3;
        ll pos = n / 3;
        for (int bt = 0; ; bt += 2) {
            ll p = (1LL << (bt + 1)) - (1LL << (bt));
            if (pos < p) {
                ll f = solve1(bt, pos, tp);
                if (tp == 0) {
                    f += (1LL << bt);
                }
                else if (tp == 1) {
                    f += (1LL << (bt + 1));
                }
                else {
                    f += (1LL << (bt + 1)) + (1LL << bt);
                }
                cout << f << '\n';
                break;
            }
            else {
                pos -= p;
            }
        }
    }
    return 0;
}
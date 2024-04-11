#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll s, x;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> s >> x;
    if (x > s || (x % 2 != s % 2)) {
        cout << 0;
        return 0;
    }
    ll an = (s - x) / 2;
    ll coef = 1;
    for (int i = 0; i < 50; i++) {
        int bit1 = (an >> i) % 2;
        int bit2 = (x >> i) % 2;
        if (bit1 == 1) {
            if (bit2 != 0) {
                cout << 0;
                return 0;
            }
        }
        else {
            if (bit2 == 1) {
                coef *= 2;
            }
        }
    }
    if (an == 0) {
        if (x == 0) {
            cout << 0;
            return 0;
        }
        else {
            coef -= 2;
        }
    }
    cout << coef << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int q;
ll shift[65];
ll sz[65];
void _shift(int i, ll x) {
    shift[i] += x;
    shift[i] %= sz[i];
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    sz[0] = 1;
    for (int i = 1; i <= 62; i++) sz[i] = 2 * sz[i - 1];
    //cout << sz[62] << endl;
    cin >> q;
    for (int iter = 1; iter <= q; iter++) {
        int type;
        cin >> type;
        if (type == 1) {
            ll x, k;
            cin >> x >> k;
            for (int i = 62; i >= 0; i--) {
                if (x >= sz[i]) {
                    k %= sz[i];
                    if (k < 0) k += sz[i];
                    _shift(i, k);
                    break;
                }
            }
        }
        else if (type == 2) {
            ll x, k;
            cin >> x >> k;
            for (int i = 62; i >= 0; i--) {
                if (x >= sz[i]) {
                    k %= sz[i];
                    if (k < 0) k += sz[i];
                    for (int j = i; j <= 62; j++) {
                        _shift(j, k);
                        k *= 2;
                    }
                    break;
                }
            }
        }
        else {
            ll x;
            cin >> x;
            int ind = -1;
            for (int i = 62; i >= 0; i--) {
                if (x >= sz[i]) {
                    ind = i;
                    break;
                }
            }
            ll pos = (x + shift[ind]) % sz[ind];
            for (int i = ind; i >= 0; i--) {
                cout << (((pos - shift[i] + sz[i]) % sz[i]) + sz[i]) << " ";
                pos /= 2;
            }
            cout << '\n';
        }
    }
    return 0;
}
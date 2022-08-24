#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) {
        int ang;
        cin >> ang;
        for (int i = 1; i <= 360; i++) {
            // 180 * x / i = ang
            if ((ang * i) % 180 == 0) {
                int x = (ang * i) / 180;
                if (x <= i - 2) {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
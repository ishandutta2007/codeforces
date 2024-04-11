#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define right ololojfs
const int maxN = (int)1e6 + 100;
int shiftO, shiftE;
int n, q;
int pos[maxN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            shiftO += x;
            shiftO %= n;
            shiftO += n;
            shiftO %= n;
            shiftE += x;
            shiftE %= n;
            shiftE += n;
            shiftE %= n;
        }
        else {
            if (shiftO % 2 == 1) {
                shiftO--;
                shiftE++;
            }
            else {
                shiftO++;
                shiftE--;
            }
            shiftO %= n;
            shiftO += n;
            shiftO %= n;
            shiftE %= n;
            shiftE += n;
            shiftE %= n;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            pos[(i + shiftO - 1) % n + 1] = i;
        }
        else {
            pos[(i + shiftE - 1) % n + 1] = i;
        }
    }
    for (int i = 1; i <= n; i++) cout << pos[i] << " ";
}
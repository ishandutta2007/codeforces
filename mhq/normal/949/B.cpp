#include <bits/stdc++.h>
using namespace std;
long long n;
int q;
const int maxN = 2 * (int)1e5 + 10;
long long ans[maxN];
long long upd[maxN];
long long x[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        cin >> x[i];
    }
    while (n != 0) {
        //if (n == 2) for (int i = 1; i <= q; i++) cout << x[i] << " ";
        //cout << endl;
        if (n % 2 == 0) {
            long long k = n / 2;
            for (int i = 1; i <= q; i++) {
                if (ans[i] != 0) continue;
                if (x[i] & 1) {
                    ans[i] = (x[i] + 1) / 2 + upd[i];
                }
                else {
                    upd[i] += k;
                    x[i] = x[i] / 2;
                }
            }
            n = k;
        }
        else {
            for (int i = 1; i <= q; i++) {
                if (ans[i] != 0) continue;
                if (x[i] == 1) {
                    ans[i] = 1 + upd[i];
                }
                else if (x[i] == 2) {
                    x[i] = n - 1;
                    upd[i] += 1;
                }
                else {
                    //if (n == 3) cout << i << endl;
                    x[i] = x[i] - 2;
                    upd[i] += 1;
                }
            }
            n = n - 1;
        }
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << " ";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 100000 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<LL> c(n);

        for (int i = 0; i < n; i += 1) {
            int x;
            cin >> x;
            //if (i % 2 == 1) x = -x;
            c[i] = x;
        }
        LL ans = 0;
        for (int l = 0; l < n; l += 2) {
            // i + 1 to j - 1
            LL sum = 0, sum_min = 0;
            for (int r = l + 1; r < n; r += 1) {
                if (r & 1) {
                    LL le = -sum_min;
                    if (le < 1) le = 1;
                    LL ri = min(c[l], c[r] - sum);
                    if (ri >= le) ans += (ri - le + 1);
                }
                if (r & 1) sum -= c[r];
                else
                    sum += c[r];
                sum_min = min(sum_min, sum);
            }
        }
        cout << ans << '\n';
    }
}
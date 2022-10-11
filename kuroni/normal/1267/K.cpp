#include <bits/stdc++.h>
using namespace std;

const int MX = 21;
 
int t, m, cnt[MX];
long long n, fct[MX];
vector<int> ve;

long long C(int n, int k) {
    if (n < k || n < 0 || k < 0) {
        return 0;
    } else {
        return fct[n] / fct[k] / fct[n - k];
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fct[0] = 1;
    for (int i = 1; i < MX; i++) {
        fct[i] = fct[i - 1] * i;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        fill(cnt, cnt + MX, 0);
        for (int i = 2; n > 0; i++) {
            cnt[n % i]++;
            n /= i;
        }
        m = accumulate(cnt, cnt + MX, 0);
        long long ans = 0;
        for (int i = m; i > 0; i--) {
            if (cnt[i] > 0) {
                cnt[i]--;
                int val = 0;
                unsigned long long cur = (cnt[m] == 0);
                for (int j = m - 1; j >= 1; j--) {
                    val++;
                    cur *= C(val, cnt[j]);
                    val -= cnt[j];
                }
                ans += cur;
                cnt[i]++;
            }
        }
        cout << ans - 1 << '\n';
    }
}
#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];
int64_t sum[nax];

int64_t get_sum(int l, int r) {
    return sum[r] - sum[l - 1];
}

int main() {

    cin >> n;

    for (int i = 1 ; i <= n; ++ i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    /**
        problem reduces
        to 2 * (a[l] | a[r]) = (a[l] + ... + a[r])
        a[l] or a[r] should have MSB.
        If none of them doesn't have MSB, the condition won't be satisfy;

        The number of subarray in each MSB should be O(n)
        so brute force
    */

    int64_t ans = 0, ans2 = 0;

    for (int b = 29 ; b >= 0 ; -- b) {
        for (int i = 1 ; i <= n ; ++ i) {
            if (a[i] >> b & 1) {
                int64_t s = 0;
                int ct_msb = 0;
                for (int j = i ; j >= 1 ; -- j) {
                    if (a[j] >= (1LL << (b + 1)) || s+a[j]>=(1ll<<(b+2))) break;
                    s += a[j];
                    if (i - j >= 2 && 2LL * (a[i] | a[j]) == s) {
                        int bar = 1 + (a[j] >> b & 1);
                        if (bar == 2) ++ ans;
                        else ++ ans2;
                    }
                }
                s = 0;
                ct_msb = 0;
                for (int j = i ; j <= n ; ++ j) {

                    if (a[j] >= (1LL << (b + 1)) || s+a[j]>=(1ll<<(b+2))) break;
                    s += a[j];
                    if (j - i >= 2 && 2LL * (a[i] | a[j]) == s) {
                        int bar = 1 + (a[j] >> b & 1);
                        if (bar == 2) ++ ans;
                        else ++ ans2;

                    }
                }
            }
        }
    }

    cout << ans / 2 + ans2 << '\n';

}
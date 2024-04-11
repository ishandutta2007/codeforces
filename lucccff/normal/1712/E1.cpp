#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, l, r;
int pre[N];

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(pre, 0, sizeof(pre));
        cin >> l >> r;
        for(int i = l; i <= r; i++) {
            for(int j = i * 2; j <= r; j += i) {
                pre[j]++;
            }
        }
        __int128 ans = 0;
        for(int i = l + 2; i <= r; i++) {
            ans += 1ll * (i - l) * (i - l - 1) / 2;
            ans -= 1ll * pre[i] * (pre[i] - 1) / 2;
        }
        for(int i = l + 2; i <= r; i++) {
            if (2 * i % 3 == 0 && 2 * i % 5 == 0 && 2 * i / 5 >= l) {
                ans--;
            }
            if (2 * i % 3 == 0 && i % 2 == 0 && i / 2 >= l) {
                ans--;
            }
        }
        int a[100], k = 0;
        memset(a, 0, sizeof(a));
        while(ans) {
            a[k++] = ans % 10;
            ans /= 10;
        }
        for(int i = k - 1; i >= 0; i--) {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}
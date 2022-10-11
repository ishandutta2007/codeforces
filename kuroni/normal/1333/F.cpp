#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, cur, ans[N];
bool chk[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        chk[i] = true;
    }
    for (int i = n, pt = n, cur = n; i >= 2; i--) {
        while (cur >= i) {
            for (int j = 2 * pt; j <= n; j += pt) {
                if (chk[j]) {
                    chk[j] = false;
                    cur--;
                }
            }
            pt--;
        }
        ans[i] = pt + 1;
    }
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}
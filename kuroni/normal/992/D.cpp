#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5;
const long long MX = 1E18;

int n, k, a[N], nxt[N];
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    nxt[n + 1] = n + 1;
    for (int i = n; i >= 1; i--) {
        nxt[i] = (a[i + 1] > 1 ? i + 1 : nxt[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        long long cur = 1, sum = 0;
        for (int j = i; j <= n; j = nxt[j]) {
            cur *= a[j]; sum += a[j];
            if (cur % k == 0) {
                long long tmp = cur / k;
                if (tmp >= sum && tmp < sum + nxt[j] - j) {
                    ans++;
                }
            }
            if (nxt[j] == n + 1 || MX / a[nxt[j]] < cur) {
                break;
            }
            sum += nxt[j] - j - 1;
        }
    }
    cout << ans;
}
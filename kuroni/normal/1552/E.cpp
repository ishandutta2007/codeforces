#include <bits/stdc++.h>
using namespace std;

const int N = 105, K = 105;

int n, k, cnt = 0, a[N * K], l[N], r[N];
int prv[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n * k; i++) {
        cin >> a[i];
    }
    while (cnt < n) {
        for (int j = 1; j <= n; j++) {
            if (prv[j] != -1) {
                prv[j] = 0;
            }
        }
        for (int i = 1; i <= n * k; i++) {
            if (prv[a[i]] == 0) {
                prv[a[i]] = i;
            } else if (prv[a[i]] > 0) {
                l[a[i]] = prv[a[i]];
                r[a[i]] = i;
                prv[a[i]] = -1;
                for (int j = 1; j <= n; j++) {
                    if (prv[j] != -1) {
                        prv[j] = 0;
                    }
                }
                cnt++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << l[i] << " " << r[i] << '\n';
    }
}
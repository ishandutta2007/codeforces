#include <bits/stdc++.h>

using namespace std;

int n;
int pr[1000006];
int f[1000006];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 2; i * i <= n; ++i) if (!pr[i]) for (int j = i * i; j <= n; j += i) pr[j] = 1;
    for (int i = 1; i <= n; ++i) f[i] = 1e9;
    for (int i = 2; i <= n; ++i) if (!pr[i]) for (int j = i + i; j <= n; j += i) f[j] = j - i + 1;
    int ans = 1e9;
    for (int i = n; i >= 2; --i) if (!pr[i] && n % i == 0) {
        for (int j = n; j >= n - i + 1; --j) ans = min(ans, f[j]);
        return cout << ans << endl, 0;
    }
}
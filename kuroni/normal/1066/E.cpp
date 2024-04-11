#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5, MOD = 998244353;

int n, m, pw[N], sum[N];
string a, b;
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (a.size() < b.size()) {
        a += '0';
    }
    while (b.size() < a.size()) {
        b += '0';
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    n = a.size();
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + b[i - 1] - '0';
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 2 % MOD;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] == '1') {
            (ans += 1LL * pw[n - i] * sum[i]) %= MOD;
        }
    }
    cout << ans;
}
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1000100;
const int mod = 1e9 + 7;

int n, k, n2;
ll l, ln;

int a[maxn], a2[maxn];
int dp[maxn];
int ans;

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> l >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    n2 = l % n;
    for (int i = 0; i < n2; ++i) a2[i] = a[i];
    sort(a, a+n);
    sort(a2, a2+n2);

    ln = l / n;

    dp[0] = 1;
    for (int i = 1; i <= k; ++i) {
        int sum = 0;
        
        for (int j = 0, j2, p = 0; j < n2; j = j2) {
            while (p < n && a[p] <= a2[j]) sum = (sum + dp[p]) % mod, ++p;
            for (j2 = j; j2 < n2 && a2[j2] == a2[j]; ++j2);
            int num = ll(j2 - j) * sum % mod;

            if (i <= ln + 1) {
                ans = (ans + num % mod) % mod;
            }
        }

        sum = 0;

        for (int j = 0, j2; j < n; j = j2) {
            sum = (sum + dp[j]) % mod;
            for (j2 = j; j2 < n && a[j2] == a[j]; ++j2);
            int num = ll(j2 - j) * sum % mod;
            
            if (i <= ln + 1) {
                ans = (ans + ll(ln + 1 - i) % mod * num % mod) % mod;
            }

            dp[j] = num;
        }
    }

    cout << ans << '\n';
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000005;
const int mod = 1e9 + 7;

int pw2[maxn], dp[maxn];
int num[maxn];
int add[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    pw2[0] = 1;
    for (int i = 1; i < maxn; i++)
        pw2[i] = (pw2[i - 1] << 1) % mod;
    dp[0] = 0;
    for (int i = 1; i < maxn; i++)
        dp[i] = (2LL * dp[i - 1] + pw2[i - 1]) % mod;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        num[a]++;
    }

    for (int i = 2; i < maxn; i++) {
        add[i] = (i + mod - add[i]) % mod;
        for (int j = i + i; j < maxn; j += i)
            add[j] = (add[i] + add[j]) % mod;
    }

    int ans = 0;
    for (int i = 2; i < maxn; i++) {
        int cnt = 0;
        for (int j = i; j < maxn; j += i) cnt += num[j];
        ans = (ans + ll(add[i]) * dp[cnt] % mod) % mod;
    }
    cout << ans << '\n';
}
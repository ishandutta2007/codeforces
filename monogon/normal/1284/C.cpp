
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 250'000 + 5;
ll n, m, fact[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (i * fact[i - 1]) % m;
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        ans += (((fact[i] * fact[n - i]) % m) * (((n - i + 1) * (n - i + 1)) % m)) % m;
        ans %= m;
    }
    cout << ans << endl;
}
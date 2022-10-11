#include <bits/stdc++.h>
using namespace std;

const int MX = 2E5 + 5, MOD = 1E9 + 7;

int n, a;
long long ans = 1, inv[MX], fct[MX], ifc[MX];
map<int, int> ma;

long long C(int n, int k) {
    return fct[n] * ifc[k] % MOD * ifc[n - k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inv[1] = 1;
    for (int i = 2; i < MX; i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }
    fct[0] = ifc[0] = 1;
    for (int i = 1; i < MX; i++) {
        fct[i] = fct[i - 1] * i % MOD;
        ifc[i] = ifc[i - 1] * inv[i] % MOD;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        for (int i = 2; i * i <= a; i++) {
            while (a % i == 0) {
                ma[i]++;
                a /= i;
            }
        }
        if (a > 1) {
            ma[a]++;
        }
    }
    for (pair<int, int> u : ma) {
        (ans *= C(u.second + n - 1, n - 1)) %= MOD;
    }
    cout << ans;
}
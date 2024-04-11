#include <bits/stdc++.h>
using namespace std;

const int MOD = 1E9 + 7;

int chk[10], n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                chk[i + j + k]++;
            }
        }
    }
    long long ans = 1, rem = 1;
    for (int i = 1; i <= 3 * n; i++) {
        (ans *= 3) %= MOD;
    }
    for (int i = 1; i <= n; i++) {
        (rem *= chk[3]) %= MOD;
    }
    cout << (ans - rem + MOD) % MOD;
}
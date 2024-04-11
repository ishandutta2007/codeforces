#include <bits/stdc++.h>
using namespace std;

const int LG = 30, MOD = 1E9 + 7;

int n, cur;
long long ans = 1, pw[LG], inv[LG], f[LG + 1][LG + 1];

long long solve(int msk, int res) {
    for (int i = 0; i <= LG; i++) {
        for (int j = 0; j <= LG; j++) {
            f[i][j] = 0;
        }
    }
    long long ret = pw[res];
    int top = 31 - __builtin_clz(msk);
    for (int i = top; i >= 0; i--) {
        f[1][i] = pw[res];
    }
    for (int st = 2; st <= top + 1; st++) {
        for (int i = top + 1 - st; i >= 0; i--) {
            if ((msk >> i & 1) || (i < res)) {
                f[st][i] = f[st - 1][i + 1] * pw[i] % MOD;
                (f[st][i] *= inv[st - 2]) %= MOD;
                if (i < res) {
                    (f[st][i] *= inv[1]) %= MOD;
                }
            }
            (f[st][i] += f[st][i + 1]) %= MOD;
        }
        (ret += f[st][0]) %= MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);   
    cin.tie(nullptr);
    cin >> n; ++n;
    pw[0] = inv[0] = 1;
    for (int i = 1; i < LG; i++) {
        pw[i] = pw[i - 1] * 2 % MOD;
        inv[i] = inv[i - 1] * (MOD + 1) / 2 % MOD;
    }
    for (int i = LG - 1; i >= 0; i--) {
        if (n >> i & 1) {
            if (cur == 0) {
                for (int j = 0; j < i; j++) {
                    (ans += solve(1 << j, j)) %= MOD;
                }
            } else {
                (ans += solve(cur, i)) %= MOD;
            }
            cur ^= (1 << i);
        }
    }
    cout << ans;
}
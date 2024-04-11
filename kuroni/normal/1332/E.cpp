#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int m, n, l, r;

struct matrix {
    long long f[2][2];

    matrix operator*(const matrix &oth) const {
        matrix ans;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ans.f[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    (ans.f[i][j] += f[i][k] * oth.f[k][j]) %= MOD;
                }
            }
        }
        return ans;
    }

    matrix operator^(const long long &p) const {
        matrix ans = *this;
        for (int i = __lg(p) - 1; i >= 0; i--) {
            ans = ans * ans;
            if (p >> i & 1) {
                ans = ans * (*this);
            }
        }
        return ans;
    }
} bas;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n >> l >> r;
    bas.f[0][1] = bas.f[1][0] = (r - l + 1) / 2;
    bas.f[0][0] = bas.f[1][1] = (r - l + 1) / 2;
    if (l % 2 == 1 && r % 2 == 1) {
        bas.f[0][1]++;
        bas.f[1][0]++;
    } else if (l % 2 == 0 && r % 2 == 0) {
        bas.f[0][0]++;
        bas.f[1][1]++;
    }
    bas = bas ^ (1LL * m * n);
    if (1LL * m * n % 2 == 0) {
        cout << bas.f[0][0];
    } else {
        cout << (bas.f[0][0] + bas.f[0][1]) % MOD;
    }
}
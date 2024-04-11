#include <bits/stdc++.h>
using namespace std;

const int N = 100, D = 31, MOD = 1E9 + 7;

int d, cur, a[N];
long long n;

struct matrix {
    long long f[D][D];

    matrix() {
        for (int i = 0; i <= d; i++) {
            for (int j = 0; j <= d; j++) {
                f[i][j] = 0;
            }
        }
    }

    matrix operator*(const matrix& oth) const {
        matrix ans;
        for (int i = 0; i <= d; i++) {
            for (int j = 0; j <= d; j++) {
                for (int k = 0; k <= d; k++) {
                    (ans.f[i][j] += f[i][k] * oth.f[k][j]) %= MOD;
                }
            }
        }
        return ans;
    }
} bas[N];

matrix rotate(int u) {
    (u += d) %= d;
    matrix ans;
    for (int i = 0; i < d; i++) {
        ans.f[i][(i + u) % d] = 1;
    }
    ans.f[d][d] = 1;
    return ans;
}

void init() {
    for (int i = 1; i < d; i++) {
        bas[0].f[i][i] = 1;
    }
    bas[0].f[d][0] = 1;
    bas[0].f[d][d] = 2; bas[0].f[0][d] = -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d;
    for (cur = 0; n > 0; cur++, n /= d) {
        a[cur] = n % d;
    }
    init();
    for (int i = 1; i < cur; i++) {
        bas[i] = rotate(0);
        for (int j = 0; j < d; j++) {
            bas[i] = bas[i] * bas[i - 1] * rotate(1);
        }
    }
    matrix ans = rotate(0);
    for (int i = cur - 1; i >= 0; i--) {
        for (int j = 0; j < a[i]; j++) {
            ans = ans * bas[i] * rotate(1);
        }
    }
    cout << (ans.f[d][d] + MOD) % MOD;
}
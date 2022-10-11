#include <bits/stdc++.h>
using namespace std;

const int N = 5005, BS = 13, MOD = 1E9 + 7;

int n;
long long pw[N], h[N], f[N][N];
char s[N];

long long get_hash(int l, int r) {
    return ((h[r] - h[l - 1] * pw[r - l + 1]) % MOD + MOD) % MOD;
}

bool check(int l, int r, int sz) {
    int le = 0, ri = sz;
    while (le <= ri) {
        int mi = (le + ri) / 2;
        if (get_hash(l, l + mi - 1) == get_hash(r, r + mi - 1)) {
            le = mi + 1;
        } else {
            ri = mi - 1;
        }
    }
    if (le > sz) {
        return false;
    } else {
        return s[l + le - 1] < s[r + le - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> (s + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * BS % MOD;
        h[i] = (h[i - 1] * BS + s[i] - '0' + 1) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < i) {
                if (s[i - j + 1] > '0') {
                    int pr = i - j;
                    (f[i][j] += f[pr][j - 1]) %= MOD;
                    if (pr - j + 1 >= 1 && check(pr - j + 1, pr + 1, j)) {
                        (f[i][j] += f[pr][j] - f[pr][j - 1]) %= MOD;
                    }
                }
                (f[i][j] += f[i][j - 1]) %= MOD;
            } else {
                f[i][j] = (f[i][i - 1] + 1) % MOD;
            }
        }
    }
    cout << f[n][n] << '\n';
}
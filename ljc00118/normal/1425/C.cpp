#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

const int N = 105;

int nn, mm, f[N][N];

__int128_t solve1(__int128_t n, __int128_t m) {
    if (n % 2 == 0) {
        __int128_t res = solve1(n - 1, m);
        m = std::min(n / 2, m);
        __int128_t x = n / 2 % 2 ? n / 2 : n / 2 + 1;
        __int128_t y = n / 2 % 2 ? n / 2 + 1 : n / 2;
        res += x * ((m + 1) / 2) + y * (m / 2);
        return res;
    }
    n /= 2;
    __int128_t res = 0;
    if (n <= m) {
        res += n * (n + 1) * (n * 4 + 5) / 6;
    } else {
        res += m * (m + 1) * (m * 4 + 5) / 6;
        res -= m * (m + 1) * (m + 1);
        res += m * (n + 1) * (n + 1);
    }
    return res;
}

__int128_t solve2(__int128_t n, __int128_t m) {
    __int128_t res = std::min((n - 1) / 2, m - 1);
    res = res * (res + 1) / 2;
    return res;
}
__int128_t solve3(__int128_t n, __int128_t m) {
    __int128_t res;
    n = std::min(n, m) - 1;
    res = (4 + n * n * 3 + n * 9 + (n % 3 - (n - 1) % 3) * 2) / 18;
    return res * 2;
}
__int128_t check(__int128_t n, __int128_t m) {
    __int128_t res = 0;
    for (__int128_t l = 1, r = 1e9, mid; l <= r; ) {
        mid = (l + r) / 2;
        if (std::min(mid, m - mid - mid) > std::max((__int128_t) 0, mid * 4 - n)) {
            l = mid + 1; res = mid;
        } else {
            r = mid - 1;
        }
    }
    return res;
}
__int128_t solve4(__int128_t n, __int128_t m) {
    __int128_t res = 0, p = check(n, m);
    if (p == 0) { return 0; }
    __int128_t pn = n / 4, pm = m / 3;
    pn = std::min(pn, p); pm = std::min(pm, p);
    if (pn > pm) {
        res += pm * (pm + 1) * (pm * 4 + 5) / 6;
        res -= m * (pm + 1) * (pm + 1) - (pm * (pm + 1) * (pm * 4 + 5) / 6 * 2);
        res += m * (pn + 1) * (pn + 1) - (pn * (pn + 1) * (pn * 4 + 5) / 6 * 2);
        res -= (m + n) * (pn + 1) * (pn + 1) - (pn * (pn + 1) * (pn * 4 + 5) / 6 * 6);
        res += (m + n) * (p + 1) * (p + 1) - (p * (p + 1) * (p * 4 + 5) / 6 * 6);
    } else {
        res += pn * (pn + 1) * (pn * 4 + 5) / 6;
        res -= n * (pn + 1) * (pn + 1) - (pn * (pn + 1) * (pn * 4 + 5) / 6 * 3);
        res += n * (pm + 1) * (pm + 1) - (pm * (pm + 1) * (pm * 4 + 5) / 6 * 3);
        res -= (m + n) * (pm + 1) * (pm + 1) - (pm * (pm + 1) * (pm * 4 + 5) / 6 * 6);
        res += (m + n) * (p + 1) * (p + 1) - (p * (p + 1) * (p * 4 + 5) / 6 * 6);
    }
    return res;
}
__int128_t solve5(__int128_t n, __int128_t m) {
    n -= 2; m -= 1;
    if (n < 1 || m < 1) { return 0; }
    __int128_t res = 0, p = check(n, m);
    if (p == 0) { return 0; }
    __int128_t pn = n / 4, pm = m / 3;
    pn = std::min(pn, p); pm = std::min(pm, p);
    if (pn > pm) {
        res += pm * (pm + 1) * (pm * 4 + 5) / 6;
        res += pm * (pm + 1) / 2;
        res -= m * (pm + 1) * (pm + 1) - (pm * (pm + 1) * (pm * 4 + 5) / 6 * 2);
        res -= pm * m - pm * (pm + 1) / 2 * 2;
        res += m * (pn + 1) * (pn + 1) - (pn * (pn + 1) * (pn * 4 + 5) / 6 * 2);
        res += pn * m - pn * (pn + 1) / 2 * 2;
        res -= (m + n) * (pn + 1) * (pn + 1) - (pn * (pn + 1) * (pn * 4 + 5) / 6 * 6);
        res -= pn * (n + m) - pn * (pn + 1) / 2 * 6;
        res += (m + n) * (p + 1) * (p + 1) - (p * (p + 1) * (p * 4 + 5) / 6 * 6);
        res += p * (n + m) - p * (p + 1) / 2 * 6;
    } else {
        res += pn * (pn + 1) * (pn * 4 + 5) / 6;
        res += pn * (pn + 1) / 2;
        res -= n * (pn + 1) * (pn + 1) - (pn * (pn + 1) * (pn * 4 + 5) / 6 * 3);
        res -= pn * n - pn * (pn + 1) / 2 * 3;
        res += n * (pm + 1) * (pm + 1) - (pm * (pm + 1) * (pm * 4 + 5) / 6 * 3);
        res += pm * n - pm * (pm + 1) / 2 * 3;
        res -= (m + n) * (pm + 1) * (pm + 1) - (pm * (pm + 1) * (pm * 4 + 5) / 6 * 6);
        res -= pm * (n + m) - pm * (pm + 1) / 2 * 6;
        res += (m + n) * (p + 1) * (p + 1) - (p * (p + 1) * (p * 4 + 5) / 6 * 6);
        res += p * (n + m) - p * (p + 1) / 2 * 6;
    }
    return res;
}

__int128_t solve(__int128_t n, __int128_t m) {
    if (n == 0 || m == 0) { return 0; }
    __int128_t res = 0;
    res += solve1(n, m) + solve1(m, n);
    res += solve2(n, m) + solve2(m, n);
    res += solve3(n, m);
    res += solve4(n, m) + solve4(m, n);
    res += solve4(n - 1, m - 1) + solve4(m - 1, n - 1);
    res += solve4(n - 2, m - 2) + solve4(m - 2, n - 2);
    res += solve5(n, m) + solve5(m, n);
    res += solve5(n - 1, m - 1) + solve5(m - 1, n - 1);
    res += solve5(n - 2, m - 2) + solve5(m - 2, n - 2);
    if (1 <= n && 2 <= m) { res += 2; }
    if (2 <= n && 1 <= m) { res += 2; }
    if (2 <= n && 2 <= m) { res += 2; }
    if (3 <= n && 3 <= m) { res += 2; }
    if (nn == 4 && n == 4) { res += 2; }
    if (mm == 4 && m == 4) { res += 2; }
    return res;
}

int main() {
    for (int T = read(); T; T--) {
        int r = read(), c = read(), n = read(), m = read();
        nn = n; mm = m;
        if (n <= 50 && m <= 50) {
            memset(f, 60, sizeof(f));
            f[1][1] = 0;
            for (int d = 0; d < 100; d++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        for (int k = 0; k < 8; k++) {
                            int x = i + dx[k], y = j + dy[k];
                            if (1 <= x && 1 <= y && x <= n && y <= m) {
                                f[i][j] = std::min(f[i][j], f[x][y] + 1);
                            }
                        }
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (f[i][j] > 1e9) { f[i][j] = 0; }
                    f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
                }
            }
            printf("%d\n", f[n][m] + f[r - 1][c - 1] - f[n][c - 1] - f[r - 1][m]);
        } else {
            printf("%d\n", (int) ((solve(n, m) + solve(r - 1, c - 1) - solve(n, c - 1) - solve(r - 1, m)) % mod));
        }        
    }
    return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <ios>

using namespace std;

typedef long long ll;

const int maxn = 2005;
const int mod = 1e9 + 7;

int n, m;
char M[2][maxn], S[maxn];
int ans;

int Z[2][maxn], R[2][maxn]; //Z - forward, R - reverse
char s[2 * maxn]; //temp string
int z[2 * maxn]; //temp z algorithm
int numr[2][maxn][maxn], dp[2][maxn][maxn];

void calcz(int k = 0) {
    int N = n + m + 1;
    int l = k, r = k;
    for (int i = k + 1; i < N; i++) {
        if (i >= r) {
            l = r = i;
            while (r < N && s[r] == s[r - l + k]) r++;
            z[i] = r - i;
        } else {
            if (i + z[i - l + k] >= r) {
                l = i;
                while (r < N && s[r] == s[r - l + k]) r++;
                z[i] = r - i;
            } else z[i] = z[i - l + k];
        }
    }
}

void add(int& a, int b) { a = (a + b) % mod; }

void go() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++)
            s[m + 1 + j] = M[i][n - 1 - j];
        calcz();
        for (int j = 0; j < n; j++)
            R[i][n - 1 - j] = z[m + 1 + j];

        for (int j = 0; j < n; j++)
            s[m + 1 + j] = M[i][j];
        reverse(s, s + m);
        calcz();
        for (int j = 0; j < n; j++)
            Z[i][j] = z[m + 1 + j];
        reverse(s, s + m);
    }

    memset(dp, 0, sizeof(dp));
    for (int l = 2; l <= min(n, m - 1); l++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) s[m + 1 + j] = M[!i][j];
            calcz(l);

            for (int j = l - 1; j < n; j++)
                if (R[i][j] >= l) {
                    int k = j - l + 1;
                    if (z[k + m + 1] >= l) add(dp[!i][j + 1][2 * l], 1);
                }
        }
    }

    memset(numr, 0, sizeof(numr));
    for (int l = 2; l <= min(n, m - 1); l++) {
        if (2 * l >= m) continue;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) s[m + 1 + j] = M[i][j];
            calcz(m - 2 * l);

            for (int j = 0; j <= n - l; j++)
                if (z[j + m + 1] >= l && Z[!i][j] >= l)
                    add(numr[i][j][m - 2 * l], 1);
        }
    }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j <= n; j++)
            add(numr[i][j][m], 1);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            add(dp[i][j][0], 1);

    for (int j = 0; j <= n; j++)
        for (int i = 0; i < 2; i++)
            for (int k = 0; k <= m; k++) {
                add(ans, ll(dp[i][j][k]) * numr[i][j][k] % mod);
                if (S[k] == M[i][j]) {
                    add(dp[i][j + 1][k + 1], dp[i][j][k]);
                    if (k + 1 < m && S[k + 1] == M[!i][j])
                        add(dp[!i][j + 1][k + 2], dp[i][j][k]);
                }
            }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> M[0] >> M[1] >> S;
    n = strlen(M[0]);
    assert(strlen(M[1]) == n);
    m = strlen(S);
    for (int i = 0; i < m; i++) s[i] = S[i];
    s[m] = 0;

    if (m == 1) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                if (M[i][j] == S[0])
                    ans++;
        cout << ans << '\n';
        return 0;
    } else if (m == 2) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                if (M[i][j] == S[0])
                    for (int di = -1; di <= 1; di++)
                        for (int dj = -1; dj <= 1; dj++)
                            if ((di == 0) != (dj == 0)) {
                                int ni = i + di, nj = j + dj;
                                if (ni >= 0 && ni < 2 && nj >= 0 && nj < n && M[ni][nj] == S[1])
                                    ans++;
                            }
        cout << ans << '\n';
        return 0;
    }

    go();
    reverse(M[0], M[0] + n);
    reverse(M[1], M[1] + n);
    go();

    cout << ans << '\n';
}
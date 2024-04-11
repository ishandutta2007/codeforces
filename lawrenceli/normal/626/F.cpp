#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

typedef long long ll;

const int maxn = 205;
const int maxk = 1005;
const int mod = 1e9 + 7;

int N, K, a[maxn], dp[maxn][maxn][maxk];

void add(int& x, int y) { x = (x + y) % mod; }
int mult(int& x, int y) { return ll(x) * y % mod; }

int main() {
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N);
    a[N] = a[N - 1];

    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        int x = a[i + 1] - a[i];
        for (int j = 0; j < N; j++)
            for (int k = 0; k <= K; k++) {
                if (k + j * x <= K)
                    add(dp[i + 1][j][k + j * x], mult(dp[i][j][k], j + 1));

                if (j && k + (j - 1) * x <= K)
                    add(dp[i + 1][j - 1][k + (j - 1) * x], mult(dp[i][j][k], j));

                if (k + (j + 1) * x <= K)
                    add(dp[i + 1][j + 1][k + (j + 1) * x], dp[i][j][k]);
            }
    }

    int ans = 0;
    for (int i = 0; i <= K; i++)
        add(ans, dp[N][0][i]);

    cout << ans << '\n';
}
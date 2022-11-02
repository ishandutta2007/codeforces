#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 105;
const int mod = 1e6 + 3;

struct mat {
    int a[maxn][maxn];
    int w;
};

int n, W, H;

mat merge(mat m1, mat m2) {
    mat m = mat();
    m.w = m1.w + m2.w;
    for (int i = 0; i <= W; i++)
        for (int j = 0; j <= W; j++)
            if (m1.a[i][j])
                for (int k = 0; k <= W - j; k++)
                    for (int l = 0; l <= W; l++)
                        if (m2.a[k][l]) {
                            int x = (i == m1.w ? i + k : i);
                            int y = (l == m2.w ? l + j : l);
                            m.a[x][y] = (m.a[x][y] + ll(m1.a[i][j]) * m2.a[k][l]) % mod;
                        }
    return m;
}

int main() {
    cin >> n >> W >> H;
    mat m = mat();
    m.a[0][0] = 1, m.a[1][1] = H, m.w = 1;
    mat c = mat();
    c.a[0][0] = 1;
    for (int i = 30; i >= 0; i--) {
        c = merge(c, c);
        if (n & (1<<i)) c = merge(c, m);
    }

    int ans = 0;
    for (int i = 0; i <= W; i++)
        for (int j = 0; j <= W; j++)
            ans = (ans + c.a[i][j]) % mod;
    cout << ans << '\n';
}
#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int a[N][N];

int R[N * 2], *r = R + N;
int C[N * 2], *c = C + N;


void work() {
    int n, m;
    cin >> n >> m;
    memset(R, 0, sizeof R);
    memset(C, 0, sizeof C);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            r[i + j] += a[i][j];
            c[i - j] += a[i][j];
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, r[i + j] + c[i - j] - a[i][j]);
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) work();
}
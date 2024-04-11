#include <bits/stdc++.h>
#define i64 long long
using namespace std;

const int N = 1e3 + 10;
int m, k;
int x[N][N];
i64 s[N], s2[N];

int main() {
    cin >> m >> k;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> x[i][j];
            s[i] += x[i][j];
            s2[i] += 1ll * x[i][j] * x[i][j];
        }
    }
    int v = (s[k] - s[1]) / (k - 1);
    int y = 2;
    for(; s[y] - s[y - 1] != v || s[y + 1] - s[y] != v; y++);
    i64 A = s2[y] - s2[y - 1], B = s2[y + 1] - s2[y];
    i64 v2 = (B - A) / 2;
    y = 2;
    for(; s[y] - s[y - 1] == v; y++);
    int d = (s[y - 1] + v) - s[y];
    i64 rs2 = (s2[y - 1] + s2[y + 1]) / 2 - v2;
    i64 rs = rs2 - s2[y];
    rs -= 1ll * d * d;
    rs /= d * 2;
    cout << y - 1 <<" " << rs + d << endl;
    return 0;
}
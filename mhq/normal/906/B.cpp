#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n >> m;
    int a[n * m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int num = (i - 1) * m + j;
            a[num] = num;
        }
    }
    if (n >= 8 && m >= 8) {
        int p = 0;
        int q = 0;
        for (int t = 2; t <= n * m; t++) {
            if (gcd(t, n) == 1 && gcd(t, m) == 1) {
                if (q == 0) q = t;
                else {
                    p = t;
                    break;
                }
            }
        }
        cout << "YES" << '\n';
        int z1 = rand() % (n * m);
        int z2 = rand() % (n * m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << ((1LL * p * (i - 1) + z1) % n) * m + (1LL * q * j + z2) % m + 1 << " ";
            }
            cout << '\n';
        }
    }
    else {
        int op = 0;
        while (op < 7 * (int)1e7 ) {
            random_shuffle(a + 1, a + n * m + 1);
            bool ok = false;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (ok) break;
                    int num = a[(i - 1) * m + j];
                    for (int k = 0; k < 4; k++) {
                        op++;
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx > n || nx < 1 || ny < 1 || ny > m) continue;
                        int rnum = a[(nx - 1) * m + ny];
                        if (abs(rnum - num) == m || abs(rnum - num) == 1) ok = true;
                    }
                }
            }
            if (!ok) {
                cout << "YES" << '\n';
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        cout << a[(i - 1) * m + j] << " ";
                    }
                    cout << '\n';
                }
                return 0;
            }
        }
        cout << "NO";
    }
    return 0;
}
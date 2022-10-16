#include <bits/stdc++.h>

using namespace std;

int n;
int p[505];
int a[505][505];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) a[i][i] = p[i], --p[i];
    for (int i = 1; i < n; ++i) {
        int x = i + 1, y = 1;
        for (int j = 1; j <= n; ++j) if (p[j]) {
            a[x][y] = p[j] + i;
            ++x;
            ++y;
            --p[j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
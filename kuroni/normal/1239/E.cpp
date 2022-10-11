#include <bits/stdc++.h>
using namespace std;

const int N = 25, MX = 50000;

int n, a[2 * N];
bool chk[2 * N];
bitset<N * MX> bi[2 * N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    sort(a, a + 2 * n);
    chk[0] = true;
    int su = accumulate(a + 2, a + 2 * n, 0);
    pair<int, int> ans = {su, 0};
    bi[1][0].set(0);
    for (int i = 2; i < 2 * n; i++) {
        for (int j = n - 1; j >= 1; j--) {
            bi[i][j] = bi[i - 1][j] | (bi[i - 1][j - 1] << a[i]);
        }
    }
    for (int i = bi[2 * n - 1][n - 1]._Find_first(); i < N * MX; i = bi[2 * n - 1][n - 1]._Find_next(i)) {
        ans = min(ans, {max(i, su - i), i});
    }
    for (int cur = ans.second, i = 2 * n - 1, j = n - 1; i >= 2; i--) {
        if (!bi[i - 1][j].test(cur)) {
            chk[i] = true;
            cur -= a[i];
            j--;
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        if (chk[i]) {
            cout << a[i] << " ";
        }
    }
    cout << '\n';
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (!chk[i]) {
            cout << a[i] << " ";
        }
    }
}
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int a[305][305];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        if (k % n == 0) cout << 0 << '\n';
        else cout << 2 << '\n';
        memset(a, 0, sizeof a);
        for (int sum = 0; sum <= n; sum++) {
            for (int row = 1; row <= n; row++) {
                if (k == 0) break;
                int col = (sum + n - row) % n;
                if (col == 0) col = n;
                a[row][col] = 1;
                k--;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
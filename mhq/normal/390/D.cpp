#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int ans[150];

void print(int x, int y) {
    for (int i = 1; i <= x; i++) {
        cout << "(" << i << ",1)" << " ";
    }
    for (int i = 2; i <= y; i++) {
        cout << "(" << x << "," << i << ")" << " ";
    }
    cout << '\n';
}
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans[i + j]++;
        }
    }
    int t = 0;
    int ind = -1;
    int ost = -1;
    int ne = 0;
    for (int i = 2; i <= n + m; i++) {
        if (t + ans[i] >= k) {
            ost = k - t;
            ind = i;
            break;
        }
        t += ans[i];
        ne += ans[i] * (i - 1);
    }
    ne += ost * (ind - 1);
    cout << ne << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + j == ind && ost > 0) {
                print(i, j);
                ost--;
            }
        }
    }
    for (int i = ind - 1; i >= 2; i--) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (j + k == i) {
                    print(j, k);
                }
            }
        }
    }
    return 0;
}
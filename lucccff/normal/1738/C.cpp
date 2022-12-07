#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int P = 998244353;

int a[110][110][2][2], n, b[110];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    a[0][0][0][0] = a[0][0][0][1] = 1;
    a[0][0][1][0] = a[0][0][1][1] = 0;
    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 100; j++) {
            if (i == 0 && j == 0) continue;
            for(int k = 0; k < 2; k++) {
                a[i][j][k][0] = 1;
                a[i][j][k][1] = 0;
                if (i > 0) {
                    a[i][j][k][0] &= a[i - 1][j][k][1];
                    a[i][j][k][1] |= a[i - 1][j][k][0];
                }
                if (j > 0) {
                    a[i][j][k][0] &= a[i][j - 1][k][1];
                    a[i][j][k][1] |= a[i][j - 1][k ^ 1][0];
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt1 = 0, cnt0 = 0, k;
        for(int i = 0; i < n; i++) {
            cin >> k;
            if (k & 1) cnt1++;
            else cnt0++;
        }
        if (a[cnt0][cnt1][0][1]) {
            cout << "Alice";
        }
        else {
            cout << "Bob";
        }
        cout << endl;
    }
    return 0;
}
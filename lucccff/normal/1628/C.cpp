#include <bits/stdc++.h>
using namespace std;

const int mx = 1073741823;

int a[1010][1010],b[1010][1010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t;
    cin >> t;
    while(t--) {
        cin >> n;
        int x = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
            b[i][0] = 0;
        }
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < n; i++) {
                b[i][j] = a[i][j - 1];
                if (j - 1 > 0) {
                    b[i][j] ^= b[i][j - 2];
                }
                if (i > 0) {
                    b[i][j] ^= b[i - 1][j - 1];
                }
                if (i < n - 1) {
                    b[i][j] ^= b[i + 1][j - 1];
                }
                x ^= b[i][j];
            }
        }
        cout << x << endl;
    }
}
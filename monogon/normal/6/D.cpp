
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 15, H = 20;
int n, a, b;
int h[N];
int dp[N][H][H];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
        h[i]++;
    }
    int t1 = (h[0] + b - 1) / b;
    h[1] = max(0, h[1] - t1 * a);
    h[2] = max(0, h[2] - t1 * b);
    int t2 = max((h[n - 1] + b - 1) / b, 0);
    h[n - 2] = max(0, h[n - 2] - t2 * a);
    h[n - 3] = max(0, h[n - 3] - t2 * b);

    n -= 2;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= h[i]; j++) {
            for(int k = 0; k < H; k++) {
                if(i == 1) {
                    dp[i][j][k] = max(k, (j + a - 1) / a);
                    continue;
                }
                dp[i][j][k] = 1e9;
                for(int l = k; l < H; l++) {
                    dp[i][j][k] = min(dp[i][j][k], l + dp[i - 1][max(0, h[i - 1] - l * b)][max(0, (j - l * a + b - 1) / b)]);
                }
            }
        }
    }
    cout << dp[n][h[n]][0] + t1 + t2 << endl;
    while(t1--) {
        cout << "2 ";
    }
    while(t2--) {
        cout << (n + 1) << " ";
    }
    int i = n, j = h[n], k = 0;
    while(i > 0) {
        int t = max(k, (j + a - 1) / a);
        if(i == 1) {
            while(t--) {
                cout << "2 ";
            }
            i--;
        }else for(int l = k; l < H; l++) {
            if(dp[i][j][k] == l + dp[i - 1][max(0, h[i - 1] - l * b)][max(0, (j - l * a + b - 1) / b)]) {
                k = max(0, (j - l * a + b - 1) / b);
                j = max(0, h[i - 1] - l * b);
                while(l--) {
                    cout << (i + 1) << " ";
                }
                i--;
                break;
            }
        }
    }
    cout << endl;
}

#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 55;

int n;
string str;
bool arr[MAX_N][MAX_N];

// the number of black cells with both indices strictler lower
int prefix[MAX_N][MAX_N];

// dp[x][y][w][h] is the solution for the rectangle 
// starting at (x, y) with width w and height h.
int dp[MAX_N][MAX_N][MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < n; j++) {
            arr[i][j] = (str[j] == '#');
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                prefix[i][j] = 0;
            }else {
                prefix[i][j] = (arr[i - 1][j - 1] ? 1 : 0) +
                    prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }
    for(int w = 0; w <= n; w++) {
        for(int h = 0; h <= n; h++) {
            for(int x = 0; x + w <= n; x++) {
                for(int y = 0; y + h <= n; y++) {
                    if(w == 0 || h == 0) {
                        dp[x][y][w][h] = 0;
                    }else if(w >= h) {
                        dp[x][y][w][h] = w;
                        for(int i = 0; i < w; i++) {
                            if(prefix[x + i + 1][y + h] - prefix[x + i][y + h] - prefix[x + i + 1][y] + prefix[x + i][y] == 0) {
                                dp[x][y][w][h] = min(dp[x][y][w][h], dp[x][y][i][h] + dp[x + i + 1][y][w - i - 1][h]);
                            }
                        }
                    }else {
                        dp[x][y][w][h] = h;
                        for(int j = 0; j < h; j++) {
                            if(prefix[x + w][y + j + 1] - prefix[x + w][y + j] - prefix[x][y + j + 1] + prefix[x][y + j] == 0) {
                                dp[x][y][w][h] = min(dp[x][y][w][h], dp[x][y][w][j] + dp[x][y + j + 1][w][h - j - 1]);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << dp[0][0][n][n] << endl;
}
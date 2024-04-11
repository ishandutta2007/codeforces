#include <bits/stdc++.h>
using namespace std;
int n, m;
int x, y, z;
int ans[2 * 1005];
int r[1005][1005];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {
            char a, b;
            cin >> a >> b;
            if (a == '0' && b == '0') z++;
            else if (a == '1' && b == '1') x++;
            else y++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= m; j++) {
                if (x > 0) {
                    //cout << "11" << " ";
                    r[i][j] = 1;
                    ans[2 * j]++;
                    ans[2 * j + 1]++;
                    x--;
                }
                else if (y > 0) {
                    if (ans[2 * j] > ans[2 * j + 1]) {
                        //cout << "01" << " ";
                        r[i][j] = 2;
                        ans[2 * j + 1]++;
                    }
                    else {
                        //cout << "10" << " ";
                        r[i][j] = 3;
                        ans[2 * j]++;
                    }
                    y--;
                }
                else {
                    //cout << "00" << " ";
                    r[i][j] = 4;
                }
            }
        }
        else {
            for (int j = m; j >= 1; j--) {
                if (x > 0) {
                    //cout << "11" << " ";
                    r[i][j] = 1;
                    ans[2 * j]++;
                    ans[2 * j + 1]++;
                    x--;
                }
                else if (y > 0) {
                    if (ans[2 * j] > ans[2 * j + 1]) {
                        //cout << "01" << " ";
                        r[i][j] = 2;
                        ans[2 * j + 1]++;
                    }
                    else {
                        //cout << "10" << " ";
                        r[i][j] = 3;
                        ans[2 * j]++;
                    }
                    y--;
                }
                else {
                    //cout << "00" << " ";
                    r[i][j] = 4;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (r[i][j] == 1) cout << "11 ";
            if (r[i][j] == 2) cout << "01 ";
            if (r[i][j] == 3) cout << "10 ";
            if (r[i][j] == 4) cout << "00 ";
        }
        cout << '\n';
    }
    return 0;
}
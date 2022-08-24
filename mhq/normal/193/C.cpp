#include <bits/stdc++.h>
using namespace std;
int h[10][10];
pair < int, int > sm[10];
int ind[10];
string s[10];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    for (int i = 1; i <= 4; i++) {
        for (int j = i + 1; j <= 4; j++) {
            cin >> h[i][j];
            h[j][i] = h[i][j];
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                if ((h[i][j] + h[j][k] + h[i][k]) % 2 != 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    for (int i = 1; i <= 4; i++) {
        int sum = 0;
        for (int j = 1; j <= 4; j++) {
            if (j == i) continue;
            sum += h[i][j];
        }
        sm[i] = make_pair(sum, i);
    }
    sort(sm + 1, sm + 4 + 1);
    int mi = sm[1].second;
    for (int i = 1; i <= 4; i++) ind[i] = i;
    ind[4] = mi;
    ind[mi] = 4;
    for (int i = 1; i <= 4; i++) {
        if (i == 4 || i == mi) continue;
        swap(h[mi][i], h[4][i]);
        swap(h[i][4], h[i][mi]);
    }
    int x, y, z, x1, y1, z1, x2, y2, z2;
    x = (h[2][3] + h[1][3] - h[1][2]) / 2;
    y = (h[2][3] + h[1][2] - h[1][3]) / 2;
    z = (h[1][2] + h[1][3] - h[2][3]) / 2;
    x2 = (h[2][4] + h[1][4] - h[1][2]) / 2;
    y2 = (h[3][4] + h[1][4] - h[1][3]) / 2;
    z2 = (h[3][4] + h[2][4] - h[2][3]) / 2;
    x1 = (h[2][3] + h[1][3] - h[2][4] - h[1][4]) / 2;
    y1 = (h[2][3] + h[1][2] - h[3][4] - h[1][4]) / 2;
    z1 = (h[1][2] + h[1][3] - h[3][4] - h[2][4]) / 2;
    if (x < 0 || y < 0 || z < 0 || x2 < 0 || y2 < 0 || z2 < 0 || x1 < 0 || y1 < 0 || z1 < 0) {
        cout << -1;
        return 0;
    }
    cout << x + y + z << '\n';
    for (int i = 0; i < x; i++) {
        s[1] += 'a';
        s[2] += 'a';
        s[3] += 'b';
    }
    for (int i = 0; i < y; i++) {
        s[1] += 'a';
        s[2] += 'b';
        s[3] += 'a';
    }
    for (int i = 0; i < z; i++) {
        s[1] += 'b';
        s[2] += 'a';
        s[3] += 'a';
    }
    for (int i = 0; i < x1; i++) {
        s[4] += 'a';
    }
    for (int i = 0; i < x2; i++) {
        s[4] += 'b';
    }
    for (int i = 0; i < y1; i++) {
        s[4] += 'a';
    }
    for (int i = 0; i < y2; i++) {
        s[4] += 'b';
    }
    for (int i = 0; i < z1; i++) {
        s[4] += 'a';
    }
    for (int i = 0; i < z2; i++) {
        s[4] += 'b';
    }
    for (int i = 1; i <= 4; i++) {
        cout << s[ind[i]] << '\n';
    }
    return 0;
}
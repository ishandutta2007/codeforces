#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;

int N;
int mat[maxn][maxn];

int rx = -1, lx = maxn, ry = -1, ly = maxn;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            mat[i][j] = c - '0';
            if (mat[i][j] == 4) {
                rx = max(rx, i);
                lx = min(lx, i);
                ry = max(ry, j);
                ly = min(ly, j);
            }
        }

    if (rx == -1) {
        cout << "No\n";
        return 0;
    }

    //cout << lx << ' ' << rx << ' ' << ly << ' ' << ry << endl;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int a = (lx <= i && i <= rx + 1) + int(lx <= i + 1 && i <= rx);
            int b = (ly <= j && j <= ry + 1) + int(ly <= j + 1 && j <= ry);
            int num = a * b;
            //cout << i << ' ' << j << ' ' << a << ' ' << b << ' ' << mat[i][j] << endl;
            if (num != mat[i][j]) {
                cout << "No\n";
                return 0;
            }
        }

    cout << "Yes\n";
}
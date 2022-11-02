#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 75;
const int NUMIT = 10000;

int n, t;
int mat[2*MAXN][2*MAXN][2];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    cin >> n >> t;
    mat[MAXN][MAXN][0] = n;
    for (int i=0; i<NUMIT; i++) {
        for (int j=1; j<2*MAXN-1; j++)
            for (int k=1; k<2*MAXN-1; k++) {
                int v = mat[j][k][0]/4;
                mat[j+1][k][1] += v;
                mat[j-1][k][1] += v;
                mat[j][k+1][1] += v;
                mat[j][k-1][1] += v;
            }
        for (int j=0; j<2*MAXN; j++)
            for (int k=0; k<2*MAXN; k++)
                mat[j][k][0] = mat[j][k][1] + mat[j][k][0]%4, mat[j][k][1] = 0;
    }
    for (int i=0; i<t; i++) {
        int x, y;
        cin >> x >> y;
        x += MAXN, y += MAXN;
        if (x < 0 || x >= 2*MAXN || y < 0 || y >= 2*MAXN) cout << "0\n";
        else cout << mat[x][y][0] << '\n';
    }
    return 0;
}
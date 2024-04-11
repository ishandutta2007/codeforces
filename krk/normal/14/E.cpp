#include <iostream>
using namespace std;

typedef long long ll;

const int Maxn = 22;
const int Maxt = 12;
const int Maxy = 4;

int n, t;
ll ways[Maxn][Maxt][Maxt][Maxy][2];

int main()
{
    cin >> n >> t;
    for (int i = 0; i < Maxy; i++) {
        for (int j = i + 1; j < Maxy; j++) ways[2][0][0][j][1]++;
        for (int j = i - 1; j >= 0; j--) ways[2][0][0][j][0]++;
    }
    for (int i = 2; i < n; i++)
        for (int j = t; j >= 0; j--)
            for (int l = t - 1; l >= 0; l--)
                for (int k = Maxy - 1; k >= 0; k--) {
                    for (int z = k + 1; z < Maxy; z++) {
                        ways[i + 1][j][l + 1][z][1] += ways[i][j][l][k][0];
                        ways[i + 1][j][l][z][1] += ways[i][j][l][k][1];
                    }
                    for (int z = k - 1; z >= 0; z--) {
                        ways[i + 1][j + 1][l][z][0] += ways[i][j][l][k][1];
                        ways[i + 1][j][l][z][0] += ways[i][j][l][k][0];
                    }
                }
    ll res = 0;
    for (int i = 0; i < Maxy; i++)
        for (int j = 0; j < 2; j++) res += ways[n][t][t - 1][i][j];
    cout << res << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 30005;
const int Maxh = 31;

string s;
int n, h;
ld P[Maxh];
ld prob[Maxn][Maxh][3], ex[Maxn][Maxh][3];

int main()
{
    cin >> s;
    cin >> n >> h;
    for (int i = 0; i < h; i++)
        P[i] = 1.0l / ld(1 << i + 1);
    P[h] = 1.0l / ld(1 << h);
    if (s == "Alice") {
        for (int i = 0; i <= h; i++) {
            prob[1][i][0] = P[i];
            ex[1][i][0] = P[i];
            prob[1][i][1] = P[i];
            ex[1][i][1] = P[i];
        }
        for (int i = 1; i < n; i++)
            for (int j = 0; j <= h; j++)
                for (int f = 0; f < 3; f++) if (prob[i][j][f] || ex[i][j][f])
                    for (int z = 0; z <= h; z++)
                        if (f == 0)
                            if (z < j) {
                                prob[i + 1][j][f] += prob[i][j][f] * P[z];
                                ex[i + 1][j][f] += ex[i][j][f] * P[z];
                            } else {
                                prob[i + 1][z][f] += prob[i][j][f] * P[z];
                                ex[i + 1][z][f] += (ex[i][j][f] + prob[i][j][f] * (1 << j)) * P[z];
                                if (z > j) {
                                    prob[i + 1][z][1] += prob[i][j][f] * P[z];
                                    ex[i + 1][z][1] += (ex[i][j][f] + prob[i][j][f] * (1 << j)) * P[z];
                                }
                            }
                        else if (f == 1)
                            if (z > j) continue;
                            else {
                                prob[i + 1][z][2] += prob[i][j][f] * P[z];
                                ex[i + 1][z][2] += (ex[i][j][f] + prob[i][j][f] * (1 << z)) * P[z];
                            }
                        else if (f == 2)
                            if (z > j) continue;
                            else {
                                prob[i + 1][z][f] += prob[i][j][f] * P[z];
                                ex[i + 1][z][f] += (ex[i][j][f] + prob[i][j][f] * (1 << z)) * P[z];
                                if (z < j) {
                                    prob[i + 1][j][f] += prob[i][j][f] * P[z];
                                    ex[i + 1][j][f] += ex[i][j][f] * P[z];
                                }
                            }
        ld res = 0;
        for (int j = 0; j <= h; j++)
            res += ex[n][j][1] + ex[n][j][2];
        cout << fixed << setprecision(15) << res << endl;
    } else {
        for (int i = 0; i <= h; i++) {
            prob[1][i][0] = P[i];
            ex[1][i][0] = P[i];
            prob[1][i][1] = P[i];
            ex[1][i][1] = P[i];
        }
        for (int i = 1; i < n; i++)
            for (int j = 0; j <= h; j++)
                for (int f = 0; f < 2; f++) if (prob[i][j][f] || ex[i][j][f])
                    if (f == 0)
                        for (int z = j; z <= h; z++) {
                            if (i + (1 << j) <= n) {
                                prob[i + (1 << j)][z][0] += prob[i][j][f] * P[z];
                                ex[i + (1 << j)][z][0] += (ex[i][j][f] + prob[i][j][f] * (1 << j)) * P[z];
                                if (z > j) {
                                    prob[i + (1 << j)][z][1] += prob[i][j][f] * P[z];
                                    ex[i + (1 << j)][z][1] += (ex[i][j][f] + prob[i][j][f] * (1 << j)) * P[z];
                                }
                            }
                        }
                    else for (int z = 0; z <= j; z++) {
                        if (i + (1 << z) <= n) {
                            prob[i + (1 << z)][z][1] += prob[i][j][f] * P[z];
                            ex[i + (1 << z)][z][1] += (ex[i][j][f] + prob[i][j][f] * (1 << z)) * P[z];
                        }
                    }
        ld res = 0;
        ld sump = 0;
        for (int j = 0; j <= h; j++) {
            res += ex[n][j][1];
            sump += prob[n][j][1];
        }
        res /= sump;
        cout << fixed << setprecision(15) << res << endl;
    }
    return 0;
}
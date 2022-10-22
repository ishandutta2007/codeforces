#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;
const int Maxk = 15;

int n, m, k;
char B[Maxn][Maxn];
int best[Maxn][Maxn][Maxk];
char p[Maxn][Maxn][Maxk];

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> B[i][j];
    fill((int*)best, (int*)best + Maxn * Maxn * Maxk, -1);
    for (int j = 0; j < m; j++) best[0][j][(B[0][j] - '0') % (k + 1)] = B[0][j] - '0';
    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j < m; j++)
            for (int l = 0; l <= k; l++) 
                if (best[i][j][l] != -1) {
                                  if (j) {
                                         int val = best[i][j][l] + B[i + 1][j - 1] - '0';
                                         if (val > best[i + 1][j - 1][val % (k + 1)]) {
                                                 best[i + 1][j - 1][val % (k + 1)] = val;
                                                 p[i + 1][j - 1][val % (k + 1)] = 'R';
                                         }
                                  }
                                  if (j + 1 < m) {
                                        int val = best[i][j][l] + B[i + 1][j + 1] - '0';
                                        if (val > best[i + 1][j + 1][val % (k + 1)]) {
                                                best[i + 1][j + 1][val % (k + 1)] = val;
                                                p[i + 1][j + 1][val % (k + 1)] = 'L';
                                        }
                                  }
                }
    int b = 0;
    for (int i = 0; i < m; i++)
        if (best[n - 1][i][0] > best[n - 1][b][0]) b = i;
    cout << best[n - 1][b][0] << endl;
    if (best[n - 1][b][0] != -1) {
               cout << b + 1 << endl;
               int mod = 0;
               for (int i = n - 1; i > 0; i--) {
                   cout << p[i][b][mod];
                   int nmod = (mod - (B[i][b] - '0') % (k + 1) + k + 1) % (k + 1);
                   if (p[i][b][mod] == 'L') b--;
                   else b++;
                   mod = nmod;
               }
               cout << endl;
    }
    return 0;
}
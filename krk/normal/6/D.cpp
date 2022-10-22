#include <cstdio>
#include <algorithm>
#define mp make_pair
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 11;
const int Maxm = 17;
const int Inf = 1000000000;

int n, a, b;
int h[Maxn];
int best[Maxn][Maxm][Maxm], wth[Maxn][Maxm][Maxm];
ii p[Maxn][Maxm][Maxm];
bool printed;

void Print(int n, const ii &v)
{
     if (n != 2) Print(n - 1, p[n][v.first][v.second]);
     int cnt = wth[n][v.first][v.second];
     while (cnt--) {
           if (printed) printf(" ");
           printed = true;
           printf("%d", n - 1);
     }
}

int main()
{
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++) { scanf("%d", &h[i]); h[i]++; }
    fill((int*)best, (int*)best + Maxn * Maxm * Maxm, Inf);
    best[2][h[1]][h[2]] = 0;
    for (int i = 2; i < n; i++)
        for (int j = 0; j < Maxm; j++)
            for (int l = 0; l < Maxm; l++) if (best[i][j][l] != Inf) {
                int from = j / b + (j % b > 0);
                for (int k = from; k < Maxm; k++) {
                    int nj = max(0, l - a * k), nl = max(0, h[i + 1] - b * k);
                    if (best[i][j][l] + k < best[i + 1][nj][nl]) {
                                      best[i + 1][nj][nl] = best[i][j][l] + k;
                                      p[i + 1][nj][nl] = mp(j, l);
                                      wth[i + 1][nj][nl] = k;
                    }
                }
            }
    printf("%d\n", best[n][0][0]);
    Print(n, mp(0, 0)); printf("\n");
    return 0;
}
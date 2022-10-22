#include <iostream>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 6;
const int Maxm = 42;

int n, m;
int best[Maxm][1 << Maxn][1 << Maxn];

int main()
{
    fill((int*)best, (int*)best + Maxm * (1 << Maxn) * (1 << Maxn), Inf);
    cin >> n >> m;
    if (n > m) swap(n, m);
    best[0][0][0] = 0;
    for (int i = 0; i <= m; i++)
        for (int m1 = 0; m1 < 1 << n; m1++)
            for (int m2 = 0; m2 < 1 << n; m2++)
                for (int m3 = 0; m3 < 1 << n; m3++)
                    if (best[i][m1][m2] != Inf) {
                                        if (i >= 1) {
                                              int j;
                                              for (j = 0; j < n; j++)
                                                  if ((m2 & 1 << j) == 0 && 
                                                      !(j > 0 && m2 & 1 << j - 1 ||
                                                        j + 1 < n && m2 & 1 << j + 1 ||
                                                        m1 & 1 << j || m3 & 1 << j)) break;
                                              if (j < n) continue;
                                        }
                                        int cnt = 0;
                                        for (int j = 0; j < n; j++)
                                            cnt += bool(m3 & 1 << j);
                                        best[i + 1][m2][m3] = min(best[i + 1][m2][m3], 
                                                                  best[i][m1][m2] + cnt);
                    }
    int b = Inf;
    for (int m1 = 0; m1 < 1 << n; m1++)
        b = min(b, best[m + 1][m1][0]);
    cout << n * m - b << endl;
    return 0;
}
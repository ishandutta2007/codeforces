#include <iostream>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 105;
const int Maxm = 721;

int n;
int A[Maxn];
int best[Maxn][Maxm];

int Pen(int x)
{
    if (x <= 360) return 0;
    return x - 360;
}

int main()
{
    fill((int*)best, (int*)best + Maxn * Maxm, Inf);
    best[0][10] = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A, A + n);
    for (int i = 0; i < n; i++) {
          int a = A[i];
          for (int j = i; j >= 0; j--)
              for (int l = 10; l + a < Maxm; l++) {
                  int cand = best[j][l] + Pen(l + a);
                  if (cand < best[j + 1][l + a]) {
                           best[j + 1][l + a] = cand;
                  }
              }
    }
    int i, j;
    for (i = n; i >= 0; i--) {
        j = 10;
        for (int l = 10; l < Maxm; l++)
            if (best[i][l] < best[i][j]) j = l;
        if (best[i][j] < Inf) break;
    }
    cout << i << " " << best[i][j] << endl;
    return 0;
}
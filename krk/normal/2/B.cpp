#include <iostream>
#include <cstdio>
#include <algorithm>
#define x first
#define y second
#define mp make_pair
using namespace std;

const int Inf = 1000000000;
const int Maxn = 1005;

int n;
int B[Maxn][Maxn];
int t[Maxn][Maxn], f[Maxn][Maxn];
pair <int, int> bestt[Maxn][Maxn], bestf[Maxn][Maxn];
char pt[Maxn][Maxn], pf[Maxn][Maxn];

bool findNull(int &r)
{
     for (int i = 1; i <= n; i++)
         for (int j = 1; j <= n; j++)
             if (!B[i][j]) {
                           r = i;
                           return true;
             }
     return false;
}

void Print(char p[][Maxn], int i, int j)
{
     if (i > 1 || j > 1) {
           if (p[i][j] == 'D') Print(p, i - 1, j);
           else Print(p, i, j - 1);
           cout << p[i][j];
     }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> B[i][j];
            int tmp = B[i][j];
            while (tmp && tmp % 2 == 0) {
                  tmp /= 2;
                  t[i][j]++;
            }
            while (tmp && tmp % 5 == 0) {
                  tmp /= 5;
                  f[i][j]++;
            }
            bestt[i][j] = bestf[i][j] = mp(Inf, Inf);
        }
    bestt[1][1] = mp(t[1][1], f[1][1]);
    bestf[1][1] = mp(f[1][1], t[1][1]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i < n && B[i + 1][j]) {
                  pair <int, int> cand = mp(bestt[i][j].x + t[i + 1][j], bestt[i][j].y + f[i + 1][j]);
                  if (cand < bestt[i + 1][j]) {
                           bestt[i + 1][j] = cand;
                           pt[i + 1][j] = 'D';
                  }
                  cand = mp(bestf[i][j].x + f[i + 1][j], bestf[i][j].y + t[i + 1][j]);
                  if (cand < bestf[i + 1][j]) {
                           bestf[i + 1][j] = cand;
                           pf[i + 1][j] = 'D';
                  }
            }
            if (j < n && B[i][j + 1]) {
                  pair <int, int> cand = mp(bestt[i][j].x + t[i][j + 1], bestt[i][j].y + f[i][j + 1]);
                  if (cand < bestt[i][j + 1]) {
                           bestt[i][j + 1] = cand;
                           pt[i][j + 1] = 'R';
                  }
                  cand = mp(bestf[i][j].x + f[i][j + 1], bestf[i][j].y + t[i][j + 1]);
                  if (cand < bestf[i][j + 1]) {
                           bestf[i][j + 1] = cand;
                           pf[i][j + 1] = 'R';
                  }
            }
        }
    int r;
    int res = min(bestt[n][n].x, bestf[n][n].x);
    if (res >= 2 && findNull(r)) {
            cout << "1\n";
            for (int i = 1; i < r; i++)
               cout << 'D';
            for (int j = 1; j < n; j++)
               cout << 'R';
            for (int i = r; i < n; i++)
               cout << 'D';
            cout << endl;
    } else {
           cout << res << endl;
           if (res == bestt[n][n].x) Print(pt, n, n);
           else Print(pf, n, n);
           cout << endl;
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1000;

int n, m;
char B[Maxn][Maxn];

bool takeHor(int r, int c1, int c2)
{
     if (c2 >= m) return false;
     if (B[r][c1] != 'W' || B[r][c1+1] != 'B' || B[r][c2] != 'W') return false;
     bool ctake[4]; fill(ctake, ctake + 4, true);
     if (r - 1 >= 0)
        for (int j = c1; j <= c2; j++) 
           if ('a' <= B[r-1][j] && B[r-1][j] <= 'd') ctake[B[r-1][j]-'a'] = false;
     if (r + 1 < n)
        for (int j = c1; j <= c2; j++)
           if ('a' <= B[r+1][j] && B[r+1][j] <= 'd') ctake[B[r+1][j]-'a'] = false;
     if (c1 - 1 >= 0 && 'a' <= B[r][c1-1] && B[r][c1-1] <= 'd') ctake[B[r][c1-1]-'a'] = false;
     if (c2 + 1 < m && 'a' <= B[r][c2+1] && B[r][c2+1] <= 'd') ctake[B[r][c2+1]-'a'] = false;
     for (int i = 0; i < 4; i++)
        if (ctake[i]) {
                      for (int j = c1; j <= c2; j++) B[r][j] = 'a' + i;
                      break;
        }
     return true;
}

bool takeVer(int c, int r1, int r2)
{
     if (r2 >= n) return false;
     if (B[r1][c] != 'W' || B[r1+1][c] != 'B' || B[r2][c] != 'W') return false;
     bool ctake[4]; fill(ctake, ctake + 4, true);
     if (c - 1 >= 0)
        for (int i = r1; i <= r2; i++)
           if ('a' <= B[i][c-1] && B[i][c-1] <= 'd') ctake[B[i][c-1]-'a'] = false;
     if (c + 1 < m)
        for (int i = r1; i <= r2; i++)
           if ('a' <= B[i][c+1] && B[i][c+1] <= 'd') ctake[B[i][c+1]-'a'] = false;
     if (r1 - 1 >= 0 && 'a' <= B[r1-1][c] && B[r1-1][c] <= 'd') ctake[B[r1-1][c]-'a'] = false;
     if (r2 + 1 < m && 'a' <= B[r2+1][c] && B[r2+1][c] <= 'd') ctake[B[r2+1][c]-'a'] = false;
     for (int i = 0; i < 4; i++)
        if (ctake[i]) {
                      for (int j = r1; j <= r2; j++) B[j][c] = 'a' + i;
                      break;
        }
     return true;
}

bool canFill(int r, int c)
{
     if (r >= n) return true;
     if (c >= m) return canFill(r + 1, 0);
     if (B[r][c] != 'W' && B[r][c] != 'B') return canFill(r, c + 1);
     if (B[r][c] == 'B') return false;
     if (takeHor(r, c, c + 2)) return canFill(r, c + 3);
     if (takeVer(c, r, r + 2)) return canFill(r, c + 1);
     return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++) {
           cin >> B[i][j];
           B[i][j] = toupper(B[i][j]);
       }
    if (canFill(0, 0)) {
                   cout << "YES\n";
                   for (int i = 0; i < n; i++) {
                       for (int j = 0; j < m; j++)
                          cout << B[i][j];
                       cout << endl;
                   }
    } else cout << "NO\n";
    return 0;
}
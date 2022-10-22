#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 9;
const int Maxm = 4;
const int Maxd = 3;
const int Maxk = 5;
const int pr[Maxm][Maxk] = {{0, 0, 0, 1, 2}, {0, 1, 1, 1, 2}, 
                            {0, 1, 2, 2, 2}, {0, 1, 1, 1, 2}};
const int pc[Maxm][Maxk] = {{0, 1, 2, 1, 1}, {2, 0, 1, 2, 2},
                            {1, 1, 0, 1, 2}, {0, 0, 1, 2, 0}};

int n, m;
int lft;
int cand;
char B[Maxn][Maxn];
int best = -1;
char R[Maxn][Maxn];

bool Check(int x, int r, int c)
{
     if (r < 0 || c < 0 || r + 2 >= n || c + 2 >= m) return false;
     for (int i = 0; i < Maxk; i++)
         if (B[r + pr[x][i]][c + pc[x][i]] != '.') return false;
     for (int i = 0; i < Maxk; i++) B[r + pr[x][i]][c + pc[x][i]] = 'A' + cand;
     cand++; lft -= 5;
     return true;
}

void Undo(int x, int r, int c)
{
     for (int i = 0; i < Maxk; i++) B[r + pr[x][i]][c + pc[x][i]] = '.';
     cand--; lft += 5;
}

void Search(int r, int c)
{
     if (cand + lft / 5 <= best) return;
     if (r >= n) {
           if (cand > best) {
                    best = cand;
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < m; j++) R[i][j] = B[i][j];
           }
     } else {
            int nxtr = r + (c + 1) / m, nxtc = (c + 1) % m;
            if (B[r][c] == '.') lft--; 
            Search(nxtr, nxtc);
            if (B[r][c] == '.') lft++; 
            for (int i = 0; i < Maxm; i++)
                if (Check(i, r, c)) {
                             if ((i == 1 || i == 2) && B[r][c] == '.') lft--;
                             Search(nxtr, nxtc);
                             if ((i == 1 || i == 2) && B[r][c] == '.') lft++;
                             Undo(i, r, c);
                }
     }
}

int main()
{
    fill((char*)B, (char*)B + Maxn * Maxn, '.');
    scanf("%d %d", &n, &m);
    lft = n * m;
    Search(0, 0);
    printf("%d\n", best);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%c", R[i][j]);
        printf("\n");
    }
    return 0;
}
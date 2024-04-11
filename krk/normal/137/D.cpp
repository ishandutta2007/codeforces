#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 505;
const int Inf = 1000000000;

string s;
int k;
int f[Maxn][Maxn];
int best[Maxn][Maxn], p[Maxn][Maxn];

void printString(int i, int j)
{
     if (i >= j) return;
     if (i + 1 == j) { printf("%c", s[i]); return; }
     printf("%c", s[i]); printString(i + 1, j - 1); printf("%c", s[i]);
}

void Print(int n, int k)
{
     if (n == 0) return;
     Print(p[n][k], k - 1);
     if (p[n][k]) printf("+");
     printString(p[n][k], n);
}

int main()
{
    getline(cin, s); 
    cin >> k;
    for (int len = 2; len <= s.length(); len++)
        for (int i = 0; i + len <= s.length(); i++) {
            f[i][i + len] = f[i + 1][i + len - 1] + (s[i] != s[i + len - 1]);
        }
    fill((int*)best, (int*)best + Maxn * Maxn, Inf); best[0][0] = 0;
    for (int i = 0; i < s.length(); i++)
        for (int j = 0; j < k; j++)
            for (int l = i + 1; l <= s.length(); l++) {
                int cand = best[i][j] + f[i][l];
                if (cand < best[l][j + 1]) {
                         best[l][j + 1] = cand;
                         p[l][j + 1] = i;
                }
            }
    int j = 0;
    for (int l = 0; l <= k; l++) if (best[s.length()][l] < best[s.length()][j]) j = l;
    printf("%d\n", best[s.length()][j]);
    Print(s.length(), j); printf("\n");
    return 0;
}
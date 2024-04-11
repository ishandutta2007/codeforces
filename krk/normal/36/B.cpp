#include <cstdio>
#include <iostream>
using namespace std;

const int MaxN = 243;
const int Maxn = 3;

int n, k, nk;
char model[Maxn][Maxn];
bool black[MaxN][MaxN];

void colBlack(int y, int x, int len)
{
     for (int i = y; i < y + len; i++)
        for (int j = x; j < x + len; j++)
           black[i][j] = true;
}

void colWhite(int y, int x, int len)
{
     if (!len) return;
     int nlen = len / n;
     for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
           if (model[i][j] == '*') colBlack(y + i * nlen, x + j * nlen, nlen);
           else colWhite(y + i * nlen, x + j * nlen, nlen);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < n; j++) 
          cin >> model[i][j];
    nk = 1;
    for (int i = 0; i < k; i++) nk *= n;
    colWhite(0, 0, nk);
    for (int i = 0; i < nk; i++) {
        for (int j = 0; j < nk; j++)
           if (black[i][j]) cout << "*";
           else cout << ".";
        cout << endl;
    }
    return 0;
}
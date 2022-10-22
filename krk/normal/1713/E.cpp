#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n;
int B[Maxn][Maxn];
int par[Maxn], siz[Maxn];
int col[Maxn];

int getPar(int x) { return par[x] == x? x: getPar(par[x]); }

int getColour(int x) { return par[x] == x? col[x]: (col[x] ^ getColour(par[x])); }

void unionSet(int a, int b, int c)
{
    int para = getPar(a), parb = getPar(b);
    if (para == parb) return;
    int cola = getColour(a), colb = getColour(b);
    if (siz[para] < siz[parb]) {
        swap(a, b);
        swap(para, parb);
        swap(cola, colb);
    }
    siz[para] += siz[parb]; par[parb] = para;
    col[parb] = (cola ^ colb ^ c);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &B[i][j]);
        for (int i = 0; i < n; i++) {
            par[i] = i; siz[i] = 1;
            col[i] = 0;
        }
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (B[i][j] < B[j][i]) unionSet(i, j, 0);
                else if (B[i][j] > B[j][i]) unionSet(i, j, 1);
        for (int d = 0; d < n; d++) if (getColour(d))
            for (int i = 0; i < n; i++)
                swap(B[i][d], B[d][i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                printf("%d%c", B[i][j], j + 1 < n? ' ': '\n');
    }
    return 0;
}
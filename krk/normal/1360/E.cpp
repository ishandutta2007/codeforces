#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n;
char B[Maxn][Maxn];

void Fill(int r, int c)
{
    if (r < 0 || c < 0) return;
    if (B[r][c] == '0') return;
    B[r][c] = '0';
    Fill(r - 1, c);
    Fill(r, c - 1);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%s", B[i]);
        for (int i = 0; i < n; i++) {
            Fill(n - 1, i);
            Fill(i, n - 1);
        }
        bool st = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (B[i][j] == '1') st = true;
        printf("%s\n", st? "NO": "YES");
    }
    return 0;
}
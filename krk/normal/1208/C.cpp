#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n;
int B[Maxn][Maxn];

int main()
{
    int pnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i += 4)
        for (int j = 0; j < n; j += 4)
            for (int i2 = i; i2 < i + 4; i2++)
                for (int j2 = j; j2 < j + 4; j2++)
                    B[i2][j2] = pnt++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%d%c", B[i][j], j + 1 < n? ' ': '\n');
    return 0;
}
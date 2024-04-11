#include <bits/stdc++.h>
using namespace std;

const int Maxn = 405;

int n;
int b[Maxn];
int res[Maxn][Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        for (int j = 0; j < n; j++)
            res[i][(i + j) % n] = (b[i] + i * j) % n;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%d%c", res[i][j], j + 1 < n? ' ': '\n');
    return 0;
}
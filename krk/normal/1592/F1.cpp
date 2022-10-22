#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int n, m;
char B[Maxn][Maxn];
bool inv[Maxn];
bool tk[Maxn][Maxn];
int res;

bool Special()
{
    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j + 1 < m; j++)
            if (tk[i][j] && tk[n - 1][j] && tk[i][m - 1] && tk[n - 1][m - 1])
                return true;
    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    for (int i = n - 1; i >= 0; i--) {
        bool cur = false;
        for (int j = m - 1; j >= 0; j--) {
            cur ^= inv[j];
            if ((B[i][j] == 'B') ^ cur) {
                inv[j] ^= true;
                cur ^= true;
                tk[i][j] = true;
                res++;
            }
        }
    }
    if (Special()) res--;
    printf("%d\n", res);
    return 0;
}
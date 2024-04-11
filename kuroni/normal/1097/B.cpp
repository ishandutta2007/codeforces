#include <iostream>
#include <cstdio>
using namespace std;

const int N = 20;

int n, u;
bool f[N][360];

int main()
{
    scanf("%d", &n);
    f[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &u);
        for (int j = 0; j < 360; j++)
            if (f[i - 1][j])
            {
                f[i][(j + u) % 360] = true;
                f[i][(j + 360 - u) % 360] = true;
            }
    }
    printf("%s\n", f[n][0] ? "YES" : "NO");
}
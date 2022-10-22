#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    scanf("%d %d", &n, &m);
    if (n == 1)
        if (m == 1) printf("0\n");
        else for (int i = 1; i <= m; i++)
                printf("%d%c", i + 1, i + 1 <= m? ' ': '\n');
    else if (m == 1)
        for (int i = 1; i <= n; i++)
            printf("%d\n", i + 1);
    else for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                printf("%d%c", i * (n + j), j + 1 <= m? ' ': '\n');
    return 0;
}
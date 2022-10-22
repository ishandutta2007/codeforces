#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                printf("%d%c", j == 0 || j + 1 == i? 1: 0, j + 1 < i? ' ': '\n');
    }
    return 0;
}
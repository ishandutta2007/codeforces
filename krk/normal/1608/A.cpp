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
            printf("%d%c", i + 1, i + 1 <= n? ' ': '\n');
    }
    return 0;
}
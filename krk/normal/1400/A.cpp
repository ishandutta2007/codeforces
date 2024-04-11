#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        for (int i = 0; i < n; i++)
            printf("%c", str[2 * i]);
        printf("\n");
    }
    return 0;
}
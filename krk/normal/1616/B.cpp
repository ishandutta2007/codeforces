#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        if (n == 1 || n > 1 && str[0] <= str[1]) printf("%c%c\n", str[0], str[0]);
        else {
            int i = 1;
            while (i + 1 < n && str[i + 1] <= str[i]) i++;
            for (int j = 0; j <= i; j++)
                printf("%c", str[j]);
            for (int j = i; j >= 0; j--)
                printf("%c", str[j]);
            printf("\n");
        }
    }
    return 0;
}
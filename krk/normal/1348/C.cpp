#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, k;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str);
        sort(str, str + n);
        if (str[0] == str[k - 1]) {
            printf("%c", str[0]);
            if (k < n && str[k] == str[n - 1]) {
                int has = (n - k - 1) / k + 1;
                for (int j = 0; j < has; j++)
                    printf("%c", str[k]);
                printf("\n");
            } else {
                for (int i = k; i < n; i++)
                    printf("%c", str[i]);
                printf("\n");
            }
        }
        else printf("%c\n", str[k - 1]);
    }
    return 0;
}
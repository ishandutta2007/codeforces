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
        bool found = false;
        for (int i = 0; i < n / 2 && !found; i++)
            if (str[i] == '0') {
                printf("%d %d %d %d\n", i + 1, n, i + 2, n);
                found = true;
            }
        if (found) continue;
        for (int i = n / 2; i < n && !found; i++)
            if (str[i] == '0') {
                printf("1 %d 1 %d\n", i + 1, i);
                found = true;
            }
        if (found) continue;
        printf("1 %d 1 %d\n", n / 2 * 2, n / 2);
    }
    return 0;
}
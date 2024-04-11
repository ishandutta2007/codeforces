#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n, m;
int a[Maxn];
int atot;
int b[Maxn];
int btot;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        atot ^= a[i];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        btot ^= b[i];
    }
    if (atot != btot) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 1; i < n; i++)
        atot ^= a[i];
    for (int j = 1; j < m; j++)
        atot ^= b[j];
    a[0] = atot;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int my;
            if (j == 0) my = a[i];
            else if (i == 0) my = b[j];
            else my = 0;
            printf("%d%c", my, j + 1 < m? ' ': '\n');
        }
    return 0;
}
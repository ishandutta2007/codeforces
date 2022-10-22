#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int T;
int n, a, b;
char res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &a, &b);
        for (int i = 0; i < a; i++)
            res[i] = 'a' + min(i, b - 1);
        for (int i = a; i < n; i++)
            res[i] = res[i - a];
        res[n] = '\0';
        printf("%s\n", res);
    }
    return 0;
}
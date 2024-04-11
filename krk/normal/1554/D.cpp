#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
char res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n == 1) { printf("a\n"); continue; }
        int pnt = 0;
        for (int i = 0; i < n / 2; i++)
            res[pnt++] = 'a';
        res[pnt++] = 'b';
        if (n % 2) res[pnt++] = 'c';
        for (int i = 0; i < n / 2 - 1; i++)
            res[pnt++] = 'a';
        res[pnt] = '\0';
        printf("%s\n", res);
    }
    return 0;
}
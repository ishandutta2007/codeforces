#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int n;
bool tk[Maxn];
int a[Maxn];

int Ask(int a, int b)
{
    printf("? %d %d\n", a, b); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &n);
    int has = 1;
    for (int i = 2; i <= n; i++) {
        int ab = Ask(has, i);
        int ba = Ask(i, has);
        if (ab > ba) {
            a[has] = ab;
            tk[ab] = true;
            has = i;
        } else {
            a[i] = ba;
            tk[ba] = true;
        }
    }
    int pnt = 1;
    while (tk[pnt]) pnt++;
    a[has] = pnt;
    printf("!");
    for (int i = 1; i <= n; i++)
        printf(" %d", a[i]);
    printf("\n"); fflush(stdout);
    return 0;
}
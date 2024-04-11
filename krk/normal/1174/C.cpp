#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int mx[Maxn];
int pnt, my[Maxn];

int main()
{
    for (int i = 2; i < Maxn; i++) if (mx[i] == 0) {
        my[i] = ++pnt;
        for (int j = i; j < Maxn; j += i)
            mx[j] = i;
    }
    int n; scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        printf("%d%c", my[mx[i]], i + 1 <= n? ' ': '\n');
    return 0;
}
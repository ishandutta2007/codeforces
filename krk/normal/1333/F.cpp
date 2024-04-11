#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;

int n;
bool er[Maxn];
int res[Maxn];
int pnt;

int main()
{
    scanf("%d", &n);
    pnt = n;
    for (int my = n / 2 * 2; my >= 2; my -= 2) {
        int big = my / 2;
        for (int i = big + big; i <= n; i += big)
            if (!er[i]) { res[pnt--] = big; er[i] = true; }
    }
    while (pnt > 0) res[pnt--] = 1;
    for (int i = 2; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}
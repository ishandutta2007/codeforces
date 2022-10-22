#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, a, b;
bool tk[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &a, &b);
        fill(tk + 1, tk + n + 1, false);
        res[0] = a; tk[a] = true;
        res[n - 1] = b; tk[b] = true;
        int pnt = n;
        bool fall = false;
        for (int i = 1; i < n / 2; i++) {
            while (tk[pnt]) pnt--;
            res[i] = pnt;
            tk[pnt] = true;
            if (pnt < a) fall = true;
        }
        pnt = 1;
        for (int i = n / 2; i + 1 < n; i++) {
            while (tk[pnt]) pnt++;
            res[i] = pnt;
            tk[pnt] = true;
            if (pnt > b) fall = true;
        }
        if (fall) printf("-1\n");
        else for (int i = 0; i < n; i++)
                printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}
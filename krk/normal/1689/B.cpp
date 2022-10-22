#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n;
int p[Maxn];
bool tk[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            tk[i] = false;
        }
        if (n == 1) { printf("-1\n"); continue; }
        for (int i = 1; i <= n; i++) {
            int pnt = 1;
            while (tk[pnt] || (i < n && p[i] == pnt)) pnt++;
            tk[pnt] = true; res[i] = pnt;
        }
        if (p[n] == res[n]) swap(res[n - 1], res[n]);
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}
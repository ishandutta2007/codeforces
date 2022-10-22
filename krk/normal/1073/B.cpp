#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
int b[Maxn];
bool tk[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int pnt = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        int res = 0;
        if (!tk[b[i]]) {
            while (a[pnt] != b[i]) {
                tk[a[pnt]] = true;
                res++;
                pnt++;
            }
            tk[a[pnt]] = true;
            res++;
            pnt++;
        }
        printf("%d%c", res, i + 1 <= n? ' ': '\n');
    }
    return 0;
}
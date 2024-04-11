#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int pnt = 0;
        int m; scanf("%d", &m);
        while (m--) {
            int b; scanf("%d", &b);
            pnt = (pnt + b) % n;
        }
        printf("%d\n", a[pnt]);
    }
    return 0;
}
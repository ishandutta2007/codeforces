#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];
int b[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int suma = 0, sumb = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            suma += a[i];
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            sumb += b[i];
            res += a[i] != b[i];
        }
        res = min(res, 1 + abs(suma - sumb));
        printf("%d\n", res);
    }
    return 0;
}
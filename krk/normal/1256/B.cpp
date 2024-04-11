#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int q;
int n;
int a[Maxn];
bool tk[Maxn];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            tk[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            int p = 0;
            while (a[p] != i) p++;
            while (p > 0 && !tk[p - 1] && a[p - 1] > a[p]) {
                tk[p - 1] = true;
                swap(a[p - 1], a[p]);
                p--;
            }
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", a[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}
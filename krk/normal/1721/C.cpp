#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int b[Maxn];
int nxt[Maxn];
int resmin[Maxn], resmax[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        nxt[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int ind = lower_bound(b, b + n, a[i]) - b;
            resmin[i] = b[ind] - a[i];
            ind = nxt[i + 1]? nxt[i + 1]: i;
            resmax[i] = b[ind] - a[i];
            if (i > 0)
                if (a[i] <= b[i - 1]) nxt[i] = max(i, nxt[i + 1]);
                else nxt[i] = 0;
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", resmin[i], i + 1 < n? ' ': '\n');
        for (int i = 0; i < n; i++)
            printf("%d%c", resmax[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}
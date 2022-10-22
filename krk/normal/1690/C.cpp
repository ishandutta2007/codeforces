#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int s[Maxn];
int f[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &s[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &f[i]);
        int old = 0;
        for (int i = 0; i < n; i++) {
            s[i] = max(s[i], old);
            printf("%d%c", f[i] - s[i], i + 1 < n? ' ': '\n');
            old = f[i];
        }
    }
    return 0;
}
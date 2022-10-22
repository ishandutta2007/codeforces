#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, m, k;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i + 1 < n && m >= 0; i++) {
            int nd = max(0, a[i + 1] - k);
            if (a[i] < nd) m -= (nd - a[i]);
            else m += a[i] - nd;
        }
        printf("%s\n", m >= 0? "YES": "NO");
    }
    return 0;
}
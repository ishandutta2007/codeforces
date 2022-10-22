#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, m;
int a[Maxn];
bool my[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            my[i] = false;
        }
        while (m--) {
            int ind; scanf("%d", &ind);
            my[ind] = true;
        }
        for (int i = 1, j; i <= n; i = j) {
            j = i;
            while (j <= n && my[j]) j++;
            j++;
            sort(a + i, a + j);
        }
        bool ok = true;
        for (int i = 1; i < n; i++)
            if (a[i] > a[i + 1]) ok = false;
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}
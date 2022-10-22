#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int k, n, m;
int A[Maxn], B[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &k, &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &B[i]);
        int pnt = 0;
        int i = 0, j = 0;
        while (pnt < n + m)
            if (i < n && (A[i] == 0 || A[i] <= k))
                if (A[i] == 0) { res[pnt++] = 0; k++; i++; }
                else { res[pnt++] = A[i]; i++; }
            else if (j < m && (B[j] == 0 || B[j] <= k))
                if (B[j] == 0) { res[pnt++] = 0; k++; j++; }
                else { res[pnt++] = B[j]; j++; }
            else break;
        if (pnt < n + m) printf("-1\n");
        else for (int i = 0; i < n + m; i++)
                printf("%d%c", res[i], i + 1 < n + m? ' ': '\n');
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, k;

int main()
{
    scanf("%d %d", &n, &k); n = k + 1;
    int mx = -1, cnt = 0;
    for (int i = 1; i <= n; i++) {
        printf("?");
        for (int j = 1; j <= n; j++) if (i != j)
            printf(" %d", j);
        printf("\n"); fflush(stdout);
        int tmp, cand; scanf("%d %d", &tmp, &cand);
        if (cand > mx) { mx = cand; cnt = 0; }
        if (cand == mx) cnt++;
    }
    printf("! %d\n", cnt); fflush(stdout);
    return 0;
}
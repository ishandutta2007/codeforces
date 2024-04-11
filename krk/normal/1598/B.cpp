#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int Maxd = 5;

int T;
int n;
int B[Maxn][Maxd];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < Maxd; j++)
                scanf("%d", &B[i][j]);
        if (n % 2) { printf("NO\n"); continue; }
        bool ok = false;
        for (int a = 0; a < Maxd && !ok; a++)
            for (int b = a + 1; b < Maxd && !ok; b++) {
                int sum1 = 0, sum2 = 0, both = 0, none = 0;
                for (int i = 0; i < n; i++)
                    if (B[i][a] && B[i][b]) both++;
                    else if (B[i][a]) sum1++;
                    else if (B[i][b]) sum2++;
                    else none++;
                ok = none == 0 && sum1 <= n / 2 && sum2 <= n / 2;
            }
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}
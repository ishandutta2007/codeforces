#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 120;

int Q;
ll t;
int x, y;
ll B[Maxn][Maxn];
bool odd[Maxn][Maxn];

int main()
{
    scanf("%d", &Q);
    while (Q--) {
        scanf("%I64d %d %d", &t, &x, &y);
        t -= (x + y);
        if (t < 0) { printf("NO\n"); continue; }
        B[0][0] = t;
        for (int i = 0; i < Maxn; i++)
            for (int j = 0; j < Maxn; j++) {
                odd[i][j] = B[i][j] % 2;
                if (B[i][j]) {
                    if (j + 1 < Maxn) B[i][j + 1] += (B[i][j] + 1) / 2;
                    if (i + 1 < Maxn) B[i + 1][j] += B[i][j] / 2;
                    B[i][j] = 0;
                }
            }
        int r = 0, c = 0;
        int steps = x + y;
        for (int i = 0; i < steps && r < Maxn && c < Maxn; i++)
            if (odd[r][c]) r++;
            else c++;
        printf("%s\n", r == x && c == y? "YES": "NO");
    }
    return 0;
}
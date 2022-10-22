#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxb = 20;

int has[Maxn][Maxb];
int T;
int L, R;

int main()
{
    for (int i = 1; i < Maxn; i++)
        for (int j = 0; j < Maxb; j++)
            has[i][j] = has[i - 1][j] + bool(i & 1 << j);
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &L, &R);
        int mx = 0;
        for (int j = 0; j < Maxb; j++)
            mx = max(mx, has[R][j] - has[L - 1][j]);
        printf("%d\n", R - L + 1 - mx);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Inf = 1000000000;

int T;
int n;
int B[2][Maxn];
int pos[2][Maxn], neg[2][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++) {
                scanf("%d", &B[i][j]);
                if (i || j) B[i][j]++;
            }
        pos[0][n] = pos[1][n] = neg[0][n] = neg[1][n] = -Inf;
        for (int i = 0; i < 2; i++)
            for (int j = n - 1; j >= 0; j--) {
                pos[i][j] = max(pos[i][j + 1], B[i][j] + j);
                neg[i][j] = max(neg[i][j + 1], B[i][j] + 2 * (n - 1) + 1 - j);
            }
        int res = 2 * Inf;
        int cur = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            res = min(res, max(cur + 2 * (n - 1) + 1 - 2 * j, max(neg[i][j] - j, pos[1 - i][j] - j)));
            cur = max(cur + 1, B[1 - i][j]);
            if (j + 1 < n)
                cur = max(cur + 1, B[1 - i][j + 1]);
            i = 1 - i;
        }
        res = min(res, cur);
        printf("%d\n", res);
    }
    return 0;
}
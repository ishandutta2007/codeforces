#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1001;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int T;
int n;
int B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
            B[0][j] = 0;
        for (int i = 0; i + 1 < n; i++)
            for (int j = 0; j < n; j++) {
                int cur = 1;
                if (j > 0) cur ^= B[i][j - 1];
                if (j + 1 < n) cur ^= B[i][j + 1];
                if (i > 0) cur ^= B[i - 1][j];
                B[i + 1][j] = cur;
            }
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int val; scanf("%d", &val);
                if (B[i][j]) res ^= val;
            }
        printf("%d\n", res);
    }
    return 0;
}
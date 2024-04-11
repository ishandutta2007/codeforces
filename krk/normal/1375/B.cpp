#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int T;
int n, m;
int B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        bool ok = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                scanf("%d", &B[i][j]);
                int cnt = 0;
                for (int d = 0; d < Maxd; d++) {
                    int ni = i + dy[d], nj = j + dx[d];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m)
                        cnt++;
                }
                if (B[i][j] > cnt) ok = false;
                B[i][j] = cnt;
            }
        if (!ok) printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    printf("%d%c", B[i][j], j + 1 < m? ' ': '\n');
        }
    }
    return 0;
}
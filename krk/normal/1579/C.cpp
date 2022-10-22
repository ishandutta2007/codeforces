#include <bits/stdc++.h>
using namespace std;

const int Maxn = 25;

int T;
int n, m, k;
char B[Maxn][Maxn];
bool tk[Maxn][Maxn];

bool Answer()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (B[i][j] == '*')
            if (!tk[i][j]) return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < n; i++) {
            scanf("%s", B[i]);
            fill(tk[i], tk[i] + m, false);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (B[i][j] == '*') {
                int len = 1;
                while (i - len >= 0 && j - len >= 0 && j + len < m && B[i - len][j - len] == '*' && B[i - len][j + len] == '*')
                    len++;
                len--;
                if (len >= k)
                    for (int z = 0; z <= len; z++)
                        tk[i - z][j - z] = tk[i - z][j + z] = true;
            }
        printf("%s\n", Answer()? "YES": "NO");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

char tmp[Maxn];
int q;
int n, m;
string B[Maxn];
int R[Maxn], C[Maxn];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            R[i] = 0;
        for (int i = 0; i < m; i++)
            C[i] = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", tmp);
            B[i] = tmp;
            for (int j = 0; j < m; j++)
                if (B[i][j] == '*') {
                    R[i]++; C[j]++;
                }
        }
        int res = n + m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int has = R[i] + C[j] - (B[i][j] == '*');
                res = min(res, n + m - 1 - has);
            }
        printf("%d\n", res);
    }
    return 0;
}
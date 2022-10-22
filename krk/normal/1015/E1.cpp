#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 1005;

int n, m;
char B[Maxn][Maxn];
int U[Maxn][Maxn], L[Maxn][Maxn];
int D[Maxn][Maxn], R[Maxn][Maxn];
int row[Maxn][Maxn], col[Maxn][Maxn];
vector <iii> res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", B[i] + 1);
        for (int j = 1; j <= m; j++)
            if (B[i][j] == '*') {
                U[i][j] = U[i - 1][j] + 1;
                L[i][j] = L[i][j - 1] + 1;
            } else U[i][j] = L[i][j] = 0;
    }
    for (int i = n; i > 0; i--)
        for (int j = m; j > 0; j--)
            if (B[i][j] == '*') {
                D[i][j] = D[i + 1][j] + 1;
                R[i][j] = R[i][j + 1] + 1;
            } else D[i][j] = R[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) if (B[i][j] == '*') {
            int mn = min(min(U[i - 1][j], D[i + 1][j]), min(L[i][j - 1], R[i][j + 1]));
            if (mn > 0) {
                res.push_back(iii(ii(i, j), mn));
                row[i][j - mn]++;
                row[i][j + mn + 1]--;
                col[j][i - mn]++;
                col[j][i + mn + 1]--;
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            row[i][j] += row[i][j - 1];
            col[j][i] += col[j][i - 1];
            if (B[i][j] == '*' && row[i][j] == 0 && col[j][i] == 0) {
                printf("-1\n"); return 0;
            }
        }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d %d\n", res[i].first.first, res[i].first.second, res[i].second);
    return 0;
}
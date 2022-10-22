#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 52;

int n, m;
int A[Maxn][Maxn], B[Maxn][Maxn];
vector <ii> seq;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j + 1 < m; j++)
            if (A[i][j] == 1 && A[i + 1][j] == 1 && A[i][j + 1] == 1 && A[i + 1][j + 1] == 1) {
                B[i][j] = B[i + 1][j] = B[i][j + 1] = B[i + 1][j + 1] = 1;
                seq.push_back(ii(i, j));
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (A[i][j] != B[i][j]) { printf("-1\n"); return 0; }
    printf("%d\n", int(seq.size()));
    for (int i = 0; i < seq.size(); i++)
        printf("%d %d\n", seq[i].first + 1, seq[i].second + 1);
    return 0;
}
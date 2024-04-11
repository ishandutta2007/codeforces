#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int n, m;
int A[Maxn][Maxn], B[Maxn][Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &B[i][j]);
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++)
            cur += A[i][j] - B[i][j];
        if (cur % 2) { printf("No\n"); return 0; }
    }
    for (int j = 0; j < m; j++) {
        int cur = 0;
        for (int i = 0; i < n; i++)
            cur += A[i][j] - B[i][j];
        if (cur % 2) { printf("No\n"); return 0; }
    }
    printf("Yes\n");
    return 0;
}
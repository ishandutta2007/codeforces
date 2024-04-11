#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

vector <int> A[Maxn], B[Maxn];
int n, m;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x; scanf("%d", &x);
            A[i + j].push_back(x);
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x; scanf("%d", &x);
            B[i + j].push_back(x);
        }
    for (int i = 0; i < Maxn; i++) {
        sort(A[i].begin(), A[i].end());
        sort(B[i].begin(), B[i].end());
        if (A[i] != B[i]) { printf("NO\n"); return 0; }
    }
    printf("YES\n");
    return 0;
}
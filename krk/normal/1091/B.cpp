#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int n;
int X[Maxn], Y[Maxn];
map <ii, int> M, T;
int A[Maxn], B[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        if (i) M[ii(X[i], Y[i])]++;
    }
    for (int i = 0; i < n; i++)
        scanf("%d %d", &A[i], &B[i]);
    for (int i = 0; i < n; i++) {
        T.clear();
        ii my = ii(X[0] + A[i], Y[0] + B[i]);
        for (int j = 0; j < n; j++) if (i != j)
            T[ii(my.first - A[j], my.second - B[j])]++;
        if (M == T) { printf("%d %d\n", my.first, my.second); return 0; }
    }
    return 0;
}
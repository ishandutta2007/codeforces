#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 404;
const int Inf = 2000000007;
 
int n;
int a[Maxn];
int A[Maxn], B[Maxn];
int res = Inf;

int Solve(int i, int j)
{
    int w = 0;
    int val = a[i - 1] - 1;
    int cost = 0;
    for (int z = i; z <= j; z++) {
        A[z] = val / a[z]; val %= a[z];
        if (z == j) A[z]++;
        cost += A[z];
        w += A[z] * a[z];
    }
    val = w;
    int cost2 = 0;
    for (int z = 1; z <= n; z++) {
        B[z] = val / a[z]; val %= a[z];
        cost2 += B[z];
    }
    return cost < cost2? w: Inf;
}
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 2; i <= n; i++)
        for (int j = i; j <= n; j++)
            res = min(res, Solve(i, j));
    printf("%d\n", res >= Inf? -1: res);
    return 0;
}
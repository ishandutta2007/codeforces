#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int A[Maxn], B[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &A[i], &B[i]);
    if (n == 3)
        for (int i = 1; i <= 3; i++)
            res[i] = i;
    else {
        res[1] = 1;
        for (int i = 1; i < n; i++) {
            int a = A[res[i]], b = B[res[i]];
            if (A[a] == b || B[a] == b)
                res[i + 1] = a;
            else res[i + 1] = b;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}
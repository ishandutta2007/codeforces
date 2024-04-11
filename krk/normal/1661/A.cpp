#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 105;

int T;
int n;
int A[Maxn];
int B[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &B[i]);
        ll res = 0;
        for (int i = 1; i < n; i++)
            res += min(abs(A[i] - A[i - 1]) + abs(B[i] - B[i - 1]),
                       abs(B[i] - A[i - 1]) + abs(A[i] - B[i - 1]));
        printf("%I64d\n", res);
    }
    return 0;
}
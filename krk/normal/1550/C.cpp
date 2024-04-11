#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int A[Maxn];

bool Check(int l, int r)
{
    for (int a = l; a <= r; a++)
        for (int b = a + 1; b <= r; b++)
            for (int c = b + 1; c <= r; c++)
                if (A[a] <= A[b] && A[b] <= A[c] ||
                    A[a] >= A[b] && A[b] >= A[c])
                    return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int l = 1; l <= 4 && i + l <= n; l++)
                res += Check(i, i + l - 1);
        printf("%d\n", res);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int n;
int a[Maxn];
map <int, int> M;
int res;

int Solve(int from)
{
    int res = 0;
    for (int i = n - 1; i >= from; i--)
        if (M[a[i]]++ > 0) {
            res = n - 1 - i;
            for (int j = i; j < n; j++)
                if (--M[a[j]] == 0) M.erase(a[j]);
            return res;
        }
    res = n - from;
    for (int j = from; j < n; j++)
        if (--M[a[j]] == 0) M.erase(a[j]);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++) {
        res = max(res, i + Solve(i));
        if (i < n && M[a[i]]++ > 0) break;
    }
    printf("%d\n", n - res);
    return 0;
}
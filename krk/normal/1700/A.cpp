#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, m;

ll Cost(int r, int c) { return (r - 1) * m + c; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        ll res = 0;
        int i = 1, j = 1;
        while (j < m)
            res += Cost(i, j++);
        while (i < n)
            res += Cost(i++, j);
        res += Cost(i, j);
        printf("%I64d\n", res);
    }
    return 0;
}
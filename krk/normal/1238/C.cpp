#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int q;
int h, n;
int p[Maxn];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &h, &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &p[i]);
        int i = 1, res = 0;
        while (i < n)
            if (i + 1 == n)
                if (p[i] <= 1) break;
                else { res++; break; }
            else if (p[i] == p[i + 1] + 1) i += 2;
                 else { res++; i++; }
        printf("%d\n", res);
    }
    return 0;
}
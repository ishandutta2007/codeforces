#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, q;
int BITR[Maxn], BITC[Maxn];
int R[Maxn], C[Maxn];

void Add(int BIT[], int x, int val)
{
    for (int i = x; i <= n; i += i & -i)
        BIT[i] += val;
}

int Get(int BIT[], int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= q; i++) {
        int typ, x1, y1, x2, y2;
        scanf("%d %d %d", &typ, &x1, &y1);
        if (typ == 1) {
            if (R[x1]++ == 0) Add(BITR, x1, 1);
            if (C[y1]++ == 0) Add(BITC, y1, 1);
        } else if (typ == 2) {
            if (--R[x1] == 0) Add(BITR, x1, -1);
            if (--C[y1] == 0) Add(BITC, y1, -1);
        } else {
            scanf("%d %d", &x2, &y2);
            if (Get(BITR, x2) - Get(BITR, x1 - 1) == x2 - x1 + 1 ||
                Get(BITC, y2) - Get(BITC, y1 - 1) == y2 - y1 + 1)
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
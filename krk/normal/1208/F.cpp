#include <bits/stdc++.h>
using namespace std;

const int Maxb = 21;
const int Maxn = 1000005;

int n;
int a[Maxn];
int best[1 << Maxb][2];

void Add(int ind, int val)
{
    if (val > best[ind][0]) best[ind][1] = best[ind][0], best[ind][0] = val;
    else if (val > best[ind][1]) best[ind][1] = val;
}

int main()
{
    int all = (1 << Maxb) - 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        Add(a[i], i);
        a[i] ^= all;
    }
    for (int b = 0; b < Maxb; b++)
        for (int i = 0; i < 1 << Maxb; i++) if (i & 1 << b) {
            Add((i ^ 1 << b), best[i][0]);
            Add((i ^ 1 << b), best[i][1]);
        }
    int res = all;
    for (int i = n - 3; i >= 0; i--) {
        int cand = 0, nd = 0;
        for (int j = Maxb - 1; j >= 0; j--)
            if (a[i] & 1 << j)
                if (best[nd | 1 << j][1] > i) nd |= 1 << j;
                else cand |= 1 << j;
        res = min(res, cand);
    }
    res ^= all;
    printf("%d\n", res);
    return 0;
}
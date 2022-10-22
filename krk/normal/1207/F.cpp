#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxp = 710;
const int Maxn = 500001;

int a[Maxn];
ll sum[Maxp][Maxp];
ll got[Maxn];

void Update(int val, int delt)
{
    if (val <= 0 || val >= Maxn) return;
    for (int i = 1; i < Maxp; i++)
        sum[i][val % i] += delt;
    got[val] += delt;
}

int main()
{
    int q; scanf("%d", &q);
    while (q--) {
        int typ, x, y; scanf("%d %d %d", &typ, &x, &y);
        if (typ == 1) {
            Update(x, -a[x]);
            a[x] += y;
            Update(x, a[x]);
        } else if (x < Maxp) printf("%I64d\n", sum[x][y]);
        else {
            ll res = 0;
            for (int i = y; i < Maxn; i += x)
                res += got[i];
            printf("%I64d\n", res);
        }
    }
    return 0;
}
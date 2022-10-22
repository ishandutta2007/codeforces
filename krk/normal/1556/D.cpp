#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;
const int Maxb = 30;

int n, k;
int and12, or12;
int and13, or13;
int and23, or23;
int res[Maxn];

int Or(int a, int b)
{
    printf("or %d %d\n", a, b); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int And(int a, int b)
{
    printf("and %d %d\n", a, b); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void Finish(int res)
{
    printf("finish %d\n", res); fflush(stdout);
}

int main()
{
    scanf("%d %d", &n, &k);
    and12 = And(1, 2);
    and13 = And(1, 3);
    and23 = And(2, 3);
    or12 = Or(1, 2);
    or13 = Or(1, 3);
    or23 = Or(2, 3);
    for (int i = 0; i < Maxb; i++)
        if (and12 & 1 << i) {
            res[1] |= 1 << i;
            res[2] |= 1 << i;
            if (and13 & 1 << i)
                res[3] |= 1 << i;
        } else if (!(or12 & 1 << i)) {
            if (or13 & 1 << i)
                res[3] |= 1 << i;
        } else if (and13 & 1 << i) {
            res[1] |= 1 << i;
            res[3] |= 1 << i;
        } else if (!(or13 & 1 << i)) {
            res[2] |= 1 << i;
        } else if (and23 & 1 << i) {
            res[2] |= 1 << i;
            res[3] |= 1 << i;
        } else if (!(or23 & 1 << i)) {
            res[1] |= 1 << i;
        }
    for (int i = 4; i <= n; i++) {
        int gor = Or(1, i);
        int gand = And(1, i);
        for (int b = 0; b < Maxb; b++)
            if (res[1] & 1 << b) {
                if (gand & 1 << b)
                    res[i] |= 1 << b;
            } else if (gor & 1 << b)
                res[i] |= 1 << b;
    }
    sort(res + 1, res + n + 1);
    Finish(res[k]);
    return 0;
}
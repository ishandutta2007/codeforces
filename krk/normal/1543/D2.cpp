#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;

int Ask(int x)
{
    printf("%d\n", x); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int Get(int a, int b, int k, bool add)
{
    if (a == 0 && b == 0) return 0;
    int mya = a % k, myb = b % k;
    int myc = add? (mya + myb) % k: (mya - myb + k) % k;
    return Get(a / k, b / k, k, add) * k + myc;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        int cur = 0;
        bool pl = true;
        for (int i = 0; i < n; i++) {
            int ask = Get(cur, i, k, pl);
            if (Ask(ask)) break;
            cur = Get(ask, cur, k, false);
            pl = !pl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll l, r;

ll getK(int mult, ll val)
{
    ll lef = 1, rig = 1000000000;
    while (lef <= rig) {
        ll mid = lef + rig >> 1ll;
        if (mid * mid + mid * mult <= val)
            lef = mid + 1;
        else rig = mid - 1;
    }
    return rig;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d", &l, &r);
        ll res = 0;
        for (int i = 0; i <= 2; i++)
            res += getK(i, r) - getK(i, l - 1);
        printf("%I64d\n", res);
    }
    return 0;
}
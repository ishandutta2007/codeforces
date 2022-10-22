#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll hc, dc;
ll hm, dm;
ll k, w, a;

bool Solve()
{
    for (ll i = 0; i <= k; i++) {
        ll hn = hc + i * a;
        ll dn = dc + (k - i) * w;
        ll me = (hm - 1) / dn + 1;
        ll he = (hn - 1) / dm + 1;
        if (me <= he) return true;
    }
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d", &hc, &dc);
        scanf("%I64d %I64d", &hm, &dm);
        scanf("%I64d %I64d %I64d", &k, &w, &a);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}
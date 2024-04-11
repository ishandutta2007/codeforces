#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll lim = 4000000000000000000ll;
const int Maxn = 100005;

int n;
ll k;
int a[Maxn];
int b[Maxn];
bool eq[Maxn];

ll Check(ll x)
{
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll lef = 0, rig = a[i] - 1;
        while (lef <= rig) {
            ll mid = lef + rig >> 1ll;
            if (a[i] - 3 * mid * mid - 3 * mid - 1 > x) lef = mid + 1;
            else rig = mid - 1;
        }
        res += lef; b[i] = lef;
        if (lef < a[i] && a[i] - 3 * lef * lef - 3 * lef - 1 == x) eq[i] = true;
        else eq[i] = false;
    }
    return res;
}

int main()
{
    scanf("%d %I64d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    ll lef = 0, rig = lim + 2000000000ll;
    while (lef <= rig) {
        ll mid = (lef + rig) >> 1ll;
        if (Check(mid - lim) >= k) lef = mid + 1;
        else rig = mid - 1;
    }
    ll lft = k - Check(lef - lim);
    for (int i = 0; i < n; i++) if (lft > 0 && eq[i]) {
        lft--; b[i]++;
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", b[i], i + 1 < n? ' ': '\n');
    return 0;
}
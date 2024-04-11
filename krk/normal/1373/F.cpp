#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 1000005;

int T;
int n;
int a[Maxn];
int b[Maxn];

int Get(ll x)
{
    ll mem = x;
    x = b[0] - x;
    for (int i = 1; i < n; i++) {
        if (a[i] <= x) x = b[i];
        else {
            x += b[i] - a[i];
            if (x < 0) return 1;
        }
    }
    if (mem + x < a[0]) return -1;
    return 0;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        ll lef = 0, rig = b[0];
        while (lef <= rig) {
            ll mid = lef + rig >> 1ll;
            int got = Get(mid);
            if (got == -1) lef = mid + 1ll;
            else if (got == 1) rig = mid - 1ll;
            else break;
        }
        printf("%s\n", lef <= rig? "YES": "NO");
    }
    return 0;
}
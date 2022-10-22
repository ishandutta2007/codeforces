#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2000005;

ll seq[Maxn];
ll rig[Maxn];
int n;
ll a[Maxn];

ll Check(ll L, ll R)
{
    for (int i = 0, j; i < n; i = j) {
        int ind = lower_bound(rig, rig + Maxn, a[i] + L) - rig;
        if (ind >= Maxn) return -1;
        L = max(L, seq[ind] - a[i]);
        if (L > R) return -1;
        ll rem = rig[ind] - a[i] - L;
        j = upper_bound(a, a + n, a[i] + rem) - a;
        R = min(R, rig[ind] - a[j - 1]);
        if (L > R) return -1;
    }
    return L;
}

int main()
{
    for (int i = 0; i < Maxn; i++) {
        seq[i] = ll(i + 1) * (i + 1);
        rig[i] = seq[i] + i + 1;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (int i = 0; i < Maxn; i++) if (a[0] <= rig[i]) {
        ll L = max(0ll, seq[i] - a[0]), R = rig[i] - a[0];
        auto got = Check(L, R);
        if (got != -1) {
            cout << got << endl;
            break;
        }
    }
    return 0;
}
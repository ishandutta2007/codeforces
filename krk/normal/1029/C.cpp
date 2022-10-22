#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const int lim = 1000000007;

int n;
int l[Maxn], r[Maxn];
int lef1[Maxn], rig1[Maxn];
int lef2[Maxn], rig2[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    lef1[0] = 0, rig1[0] = lim;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        lef1[i] = max(lef1[i - 1], l[i]);
        rig1[i] = min(rig1[i - 1], r[i]);
    }
    lef2[n + 1] = 0, rig2[n + 1] = lim;
    for (int i = n; i > 0; i--) {
        lef2[i] = max(lef2[i + 1], l[i]);
        rig2[i] = min(rig2[i + 1], r[i]);
    }
    for (int i = 1; i <= n; i++) {
        int L = max(lef1[i - 1], lef2[i + 1]);
        int R = min(rig1[i - 1], rig2[i + 1]);
        if (L < R) res = max(res, R - L);
    }
    cout << res << endl;
    return 0;
}
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
ll s;
int a[Maxn];
int p[Maxn];
int nxt;

void Traverse(int me, int lvl, int deg)
{
    int tk = min(a[lvl], deg);
    a[lvl] -= tk;
    for (int i = 0; i < tk; i++) {
        int got = nxt++;
        p[got] = me;
        Traverse(got, lvl + 1, deg);
    }
}

ll getSum(int b)
{
    int cur = 1;
    ll my = 1;
    ll rem = n;
    ll res = 0;
    while (rem) {
        ll tk = min(my, rem);
        res += tk * cur;
        my *= b; rem -= tk;
        cur++;
    }
    return res;
}

int main()
{
    cin >> n >> s;
    if (ll(n + 1) * n / 2 < s) { printf("No\n"); return 0; }
    int lef = 1, rig = n - 1;
    bool ok = false;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (getSum(mid) > s) lef = mid + 1;
        else { ok = true; rig = mid - 1; }
    }
    rig++;
    if (!ok) { printf("No\n"); return 0; }
    a[1] = 1;
    int lft = n - 1;
    for (int i = 2; i <= n; i++) {
        ll tk = min(ll(a[i - 1]) * rig, ll(lft));
        a[i] = tk; lft -= tk;
    }
    int pnt = 1;
    while (a[pnt]) { s -= ll(pnt) * a[pnt]; pnt++; }
    for (int i = pnt - 1; i > 0 && s > 0; i--)
        while (a[i] > 1 && s > 0) {
            int cur = pnt - i;
            if (cur <= s) { s -= cur; a[i]--; a[pnt]++; pnt++; }
            else { a[i]--; a[i + s]++; s = 0; }
        }
    nxt = 2; a[1]--;
    Traverse(1, 2, rig);
    printf("Yes\n");
    for (int i = 2; i <= n; i++)
        printf("%d%c", p[i], i + 1 <= n? ' ': '\n');
    return 0;
}
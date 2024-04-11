#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 5;
const long long M = 1e9 + 7;
const long long inf = 1e18;

int n, p[N], a[N], ans = inf, f[N], pos[N], t[4*N], pu[4*N];

void build(int v, int vl, int vr) {
    if (vl == vr) {
        t[v] = f[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    build(v + v, vl, vm);
    build(v + v + 1, vm + 1, vr);
    t[v] = min(t[v + v], t[v + v + 1]);
}

void push(int v) {
    pu[v + v] += pu[v];
    t[v + v] += pu[v];

    pu[v + v + 1] += pu[v];
    t[v + v + 1] += pu[v];

    pu[v] = 0;
}

void update(int v, int vl, int vr, int l, int r, int val) {
    if (l > r)
        return;
    if (vl == l && vr == r) {
        t[v] += val;
        pu[v] += val;
        return;
    }
    push(v);
    int vm = (vl + vr) / 2;
    update(v + v, vl, vm, l, min(r, vm), val);
    update(v + v + 1, vm + 1, vr, max(l, vm + 1), r, val);
    t[v] = min(t[v + v], t[v + v + 1]);
}

int get(int v, int vl, int vr, int l, int r) {
    if (l > r)
        return 1e18;
    if (vl == l && vr == r)
        return t[v];
    push(v);
    int vm = (vl + vr) / 2;
    return min(get(v + v, vl, vm, l, min(r, vm)),
               get(v + v + 1, vm + 1, vr, max(l, vm + 1), r));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i], pos[p[i]] = i;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ans = a[1];
    f[0] = 0;
    for (int i = 1; i < pos[1]; i++)
        f[i] = f[i - 1] + a[i];
    for (int i = 0; i < pos[1]; i++)
        f[i] += a[pos[1]];
    f[pos[1]] = f[pos[1] - 1] - a[pos[1]];
    for (int i = pos[1] + 1; i <= n; i++)
        f[i] = f[i - 1] + a[i];
  /*  for (int i = 1; i <= n; i++)
        cout << f[i] << ' ';
    cout << endl;
*/
    build(1, 1, n);
    ans = min(ans, get(1, 1, n, 1, n - 1));
    for (int mx = 2; mx <= n; mx++) {
        update(1, 1, n, 1, pos[mx] - 1, a[pos[mx]]);
        update(1, 1, n, pos[mx], n, -a[pos[mx]]);
        ans = min(ans, get(1, 1, n, 1, n - 1));
    }
    cout << ans;
    return 0;
}
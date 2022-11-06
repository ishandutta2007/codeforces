#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 4e5 + 5;
const long long inf = 2e18;

int n, a[N], cost, x, t[4*N], pref[N], t2[4*N], p[N];

void update(int v, int vl, int vr, int l, int r, int x) {
    if (l > r)
        return;
    if (vl == l && vr == r) {
        t[v] -= x;
        return;
    }
    int vm = (vl + vr) / 2;
    update(v + v, vl, vm, l, min(r, vm), x);
    update(v + v + 1, vm + 1, vr, max(l, vm + 1), r, x);
}


int get(int v, int vl, int vr, int pos) {
    if (vl == vr) {
        return pref[pos] + t[v];
    }
    int vm = (vl + vr) / 2;
    if (pos <= vm)
        return t[v] + get(v + v, vl, vm, pos);
    else
        return t[v] + get(v + v + 1, vm + 1, vr, pos);
}


void update2(int v, int vl, int vr, int l, int r, int x) {
    if (l > r)
        return;
    if (vl == l && vr == r) {
        t2[v] -= x;
        return;
    }
    int vm = (vl + vr) / 2;
    update2(v + v, vl, vm, l, min(r, vm), x);
    update2(v + v + 1, vm + 1, vr, max(l, vm + 1), r, x);
}


int get2(int v, int vl, int vr, int pos) {
    if (vl == vr) {
        return p[pos] + t2[v];
    }
    int vm = (vl + vr) / 2;
    if (pos <= vm)
        return t2[v] + get2(v + v, vl, vm, pos);
    else
        return t2[v] + get2(v + v + 1, vm + 1, vr, pos);
}

set<int> s;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i + n] = a[i], cost += a[i];
    for (int i = 1; i <= n + n; i++)
        pref[i] = pref[i - 1] + a[i], p[i] = p[i - 1] + 1;
    int cur = 1, kol = n, ans = 0;
    while (1) {
        if (cost == 0)
            break;
        ans += kol * (x / cost);
        x %= cost;
        kol--;
       // cout << ans <<' ' << x <<  endl;
        int l = cur - 1, r = cur + n - 1;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (get(1, 1, n + n, m) - get(1, 1, n + n, cur - 1) <= x)
                l = m;
            else
                r = m;
        }
        //cout << r << endl;
        if (r > n)
            r -= n;
        update(1, 1, n + n, r, n + n, a[r]);
        update(1, 1, n + n, r + n, n + n, a[r]);

        update2(1, 1, n + n, r, n + n, 1);
        update2(1, 1, n + n, r + n, n + n, 1);
        cost -= a[r];
        if (r >= cur)
            ans += r == 1 ? 0 : get2(1, 1, n + n, r - 1) - (cur == 1 ? 0 : get2(1, 1, n + n, cur - 1));
        else
            ans += (r == 1 ? 0 : get2(1, 1, n + n, r - 1)) - (cur == 1 ? 0 : get2(1, 1, n + n, cur - 1)) + get2(1, 1, n + n, n);
        if (r >= cur)
            x -= r == 1 ? 0 : get(1, 1, n + n, r - 1) - (cur == 1 ? 0 : get(1, 1, n + n, cur - 1));
        else
            x -= (r == 1 ? 0 : get(1, 1, n + n, r - 1)) - (cur == 1 ? 0 : get(1, 1, n + n, cur - 1)) + get(1, 1, n + n, n);

       // cout << ans << endl;

        cur = r;
        l = cur, r = cur + n;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (get2(1, 1, n + n, m) - get2(1, 1, n + n, cur - 1) == 0)
                l = m;
            else
                r = m;
        }
        if (r > n)
            r -= n;
        cur = r;
        //cout << cur << endl;
    }
    cout << ans;
    return 0;
}
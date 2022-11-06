#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

const int N = 5e5+5;
const long long inf = 2e18;
const long long M = 1e9+7;

int q, pos, val, n, a[N], t[2*N], push[2*N];

void push1(int v) {
    t[2*v] += push[v];
    t[2*v + 1] += push[v];
    push[2*v] += push[v];
    push[2*v + 1] += push[v];
    push[v] = 0;
}

void update(int v, int vl, int vr, int l, int r, int val) {
    if (l > r)
        return;
    if (vl == l && vr == r)
    {
        t[v] += val;
        push[v] += val;
        return;
    }
    int vm = (vl + vr)/2;
    push1(v);
    update(2*v, vl, vm, l, min(r, vm), val);
    update(2*v + 1, vm + 1, vr, max(l, vm + 1), r, val);
    t[v] = max(t[2*v], t[2*v + 1]);
}

int get(int v, int vl, int vr) {
    //cout << vl << ' ' << vr << ' ' << t[v] << ' ' << v << endl;
    if (t[v] < 0)
        return -1;
    if (vl == vr)
    {
        if (t[v] == 0)
            return vl;
        return -1;
    }
    int vm = (vl + vr)/2;
    push1(v);
    int val = get(2*v, vl, vm);
    if (val != -1)
        return val;
    return get(2*v + 1, vm + 1, vr);
}

signed main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(1, 1, n, i+1, n, -a[i]);
        update(1, 1, n, i, i, a[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> pos >> val;
        //cout << t[3] << endl;
        update(1, 1, n, pos + 1, n, -val + a[pos]);
        update(1, 1, n, pos, pos, val-a[pos]);
        //cout << t[3] << endl;
        int p = get(1, 1, n);
        cout << p << "\n";
        a[pos] = val;
    }
    return 0;
}
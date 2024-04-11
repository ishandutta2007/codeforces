#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int inf = 1e9;
const int N = 2e5 + 5;
const int K = (1<<5);

struct cell {
    int a[5];
};

int n, k, t[4*N][K];
cell a[N];

int nott(int mask) {
    int res = 0;
    for (int i = 0; i < k; i++)
        if (!((mask >> i)&1))
            res += (1<<i);
    return res;
}

int f(int mask, cell x) {
    int res = 0;
    for (int i = 0; i < k; i++)
        if ((mask >> i) & 1)
            res += x.a[i];
        else
            res -= x.a[i];
    return res;
}

void build(int v, int vl, int vr) {
    if (vl == vr) {
        for (int mask = 0; mask < (1<<k); mask++)
            t[v][mask] = f(mask, a[vl]);
        return;
    }
    int vm = (vl + vr) / 2;
    build(v + v, vl, vm);
    build(v + v + 1, vm + 1, vr);
    for (int mask = 0; mask < (1<<k); mask++)
        t[v][mask] = max(t[v + v][mask], t[v + v + 1][mask]);
}

void update(int v, int vl, int vr, int pos, cell val) {
    if (vl == vr) {
       // cout << val.a[0] << ' ' << val.a[1] << endl;
        a[vl] = val;
        for (int mask = 0; mask < (1<<k); mask++)
            t[v][mask] = f(mask, a[vl]);
        return;
    }
    int vm = (vl + vr) / 2;
    if (pos <= vm)
        update(v + v, vl, vm, pos, val);
    else
        update(v + v + 1, vm + 1, vr, pos, val);
    for (int mask = 0; mask < (1<<k); mask++)
        t[v][mask] = max(t[v + v][mask], t[v + v + 1][mask]);
   // cout << v << ' ' << mask << ' ' << t[v][mask] << endl;}
}

int get(int v, int vl, int vr, int l, int r, int num) {
    //cout << v << ' ' << vl << ' ' << vr << ' ' << num << endl;
    if (l > r)
        return -inf;
    if (vl == l && vr == r)
        return t[v][num];
    int vm = (vl + vr) / 2;
    return max(get(v + v, vl, vm, l, min(r, vm), num), get(v + v + 1, vm + 1, vr, max(l, vm + 1), r, num));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            cin >> a[i].a[j];
    build(1, 1, n);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int tt;
        cin >> tt;
        if (tt == 1) {
            int pos;
            cin >> pos;
            cell x;
            for (int j = 0; j < k; j++)
                cin >> x.a[j];
            update(1, 1, n, pos, x);
        } else {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for (int mask = 0; mask < (1<<k); mask++) {
                int m1 = nott(mask);
                int x = get(1, 1, n, l, r, mask), y = get(1, 1, n, l, r, m1);
              //  cout << mask << ' ' << m1 << ' ' <<  x << ' '<< y<< ' ' << t[1][mask] << endl;
                ans = max(ans, x + y);
               // cout << endl << endl << endl;
            }
            cout <<ans << "\n";
        }
    }

    return 0;
}
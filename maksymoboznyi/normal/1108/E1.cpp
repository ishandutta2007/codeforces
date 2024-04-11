#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;
int n, m;
int t1[4*N], t2[4*N], a[N], l[N], r[N], p[N];

void build(int v, int vl, int vr) {
    if (vl == vr) {
        t1[v] = t2[v] = a[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    build(v + v, vl, vm);
    build(v + v + 1, vm + 1, vr);
    t1[v] = max(t1[v + v], t1[v + v + 1]);
    t2[v] = min(t2[v + v], t2[v + v + 1]);
}

void push(int v) {
    t1[v + v] += p[v];
    t1[v + v + 1] += p[v];
    t2[v + v] += p[v];
    t2[v + v + 1] += p[v];
    p[v + v] += p[v];
    p[v + v + 1] += p[v];
    p[v] = 0;
}

void update(int v, int vl, int vr, int l, int r, int val) {
    if (l > r)
        return;
    if (vl == l && vr == r) {
        t1[v] += val;
        t2[v] += val;
        p[v] += val;
        return;
    }
    int vm = (vl + vr) / 2;
    push(v);
    update(v + v, vl, vm, l, min(r, vm), val);
    update(v + v + 1, vm + 1, vr, max(l, vm + 1), r, val);
    t1[v] = max(t1[v + v], t1[v + v + 1]);
    t2[v] = min(t2[v + v], t2[v + v + 1]);
}

int get_max(int v, int vl, int vr, int l, int r) {
    if (l > r)
        return -inf;
    if (vl == l && vr == r)
        return t1[v];
    push(v);
    int vm = (vl + vr) / 2;
    return max(get_max(v + v, vl, vm, l, min(r, vm)), get_max(v + v + 1, vm + 1, vr, max(l, vm + 1), r));
}

int get_min(int v, int vl, int vr, int l, int r) {
    if (l > r)
        return inf;
    if (vl == l && vr == r)
        return t2[v];
    push(v);
    int vm = (vl + vr) / 2;
    return max(get_min(v + v, vl, vm, l, min(r, vm)), get_min(v + v + 1, vm + 1, vr, max(l, vm + 1), r));
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i];
    build(1, 1, n);
    vector<int> cur;
    vector<int> an;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> c;
        for (int j = 0; j < cur.size(); j++)
            if (r[cur[j]] < i)
                update(1, 1, n, l[cur[j]], r[cur[j]], 1);
            else
                c.pb(cur[j]);
        for (int j = 1; j <= m; j++)
            if (l[j] == i) {
                c.pb(j);
                update(1, 1, n, l[j], r[j], -1);
            }
        cur = c;
        //cout << '*' << get_max(1, 1, n, 5, 5) << ' ' << cur.size() << endl;
        if (t2[1] != a[i] - cur.size())
            continue;
        /*cout << i << ' ' << t1[1] << ' ' << t2[1] << ' ' << get_max(1, 1, n, 5, 5) << endl;
        for (int j = 0; j < cur.size(); j++)
            cout << cur[j] << ' ';
        cout << endl;
        */
        if (t1[1] - t2[1] > ans)
            ans = t1[1] - t2[1], an = cur;
    }
    cout << ans << endl << an.size() << endl;
    for (int i = 0; i < an.size(); i++)
        cout << an[i] << ' ';
    return 0;
}
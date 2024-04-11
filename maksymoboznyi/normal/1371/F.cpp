#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e6 + 5;

struct node {
    int t1, x1, y1;
    int t2, x2, y2;
    int sz;
    int m0, m1;
};

node t[4*N];
char a[N];
int n, p[4*N];


node combine(node a, node b) {
    node res;
    if (a.sz == 0)
        return b;
    if (b.sz == 0)
        return a;

    res.t1 = a.t1;
    if (a.x1 == a.sz)
        if (b.t1 == a.t1)
            res.x1 = a.sz + b.x1, res.y1 = b.y1;
        else
            res.x1 = a.sz, res.y1 = b.x1;
    else
        if (a.x1 + a.y1 != a.sz || b.t1 == a.t1)
            res.x1 = a.x1, res.y1 = a.y1;
        else
            res.x1 = a.x1, res.y1 = a.y1 + b.x1;

    res.t2 = b.t2;
    if (b.x2 == b.sz)
        if (a.t2 == b.t2)
            res.x2 = b.sz + a.x2, res.y2 = a.y2;
        else
            res.x2 = b.sz, res.y2 = a.x2;
    else
        if (b.x2 + b.y2 != b.sz || a.t2 == b.t2)
            res.x2 = b.x2, res.y2 = b.y2;
        else
            res.x2 = b.x2, res.y2 = b.y2 + a.x2;
    res.sz = a.sz + b.sz;

    res.m0 = max(a.m0, b.m0);
    res.m1 = max(a.m1, b.m1);

    if (a.t2 == 0)
        if (b.t1 == 0)
            res.m0 = max(res.m0, a.x2 + b.x1 + b.y1), res.m1 = max(res.m1, a.x2 + b.x1 + a.y2);
        else
            res.m0 = max(res.m0, a.x2 + b.x1), res.m1 = res.m1;
    else
        if (b.t1 == 0)
            res.m0 = res.m0, res.m1 = max(res.m1, a.x2 + b.x1);
        else
            res.m0 = max(res.m0, a.x2 + a.y2 + b.x1), res.m1 = max(res.m1, a.x2 + b.x1 + b.y1);
    return res;
}

void build(int v, int vl, int vr) {
    if (vl == vr) {
        if (a[vl] == '<') {
            t[v].t1 = t[v].t2 = 0;
            t[v].x1 = t[v].x2 = 1;
            t[v].y1 = t[v].y2 = 0;
            t[v].sz = 1;
            t[v].m0 = t[v].m1 = 0;
        } else {
            t[v].t1 = t[v].t2 = 1;
            t[v].x1 = t[v].x2 = 1;
            t[v].y1 = t[v].y2 = 0;
            t[v].sz = 1;
            t[v].m0 = t[v].m1 = 0;
        }
        return;
    }
    int vm = (vl + vr) / 2;
    build(v + v, vl, vm);
    build(v + v + 1, vm + 1, vr);
    t[v] = combine(t[v + v], t[v + v + 1]);
}

void push(int v) {
    if (p[v]) {
        p[v] = 0;

        t[v + v].t1 ^= 1;
        t[v + v].t2 ^= 1;
        swap(t[v + v].m0, t[v + v].m1);
        p[v + v] ^= 1;

        t[v + v + 1].t1 ^= 1;
        t[v + v + 1].t2 ^= 1;
        swap(t[v + v + 1].m0, t[v + v + 1].m1);
        p[v + v + 1] ^= 1;
    }
}

void rev(int v, int vl, int vr, int l, int r) {
    if (l > r)
        return;
    if (vl == l && vr == r) {
        t[v].t1 ^= 1;
        t[v].t2 ^= 1;
        swap(t[v].m0, t[v].m1);
        p[v] ^= 1;
        return;
    }
    push(v);
    int vm = (vl + vr) / 2;
    rev(v + v, vl, vm, l, min(r, vm));
    rev(v + v + 1, vm + 1, vr, max(l, vm + 1), r);
    t[v] = combine(t[v + v], t[v + v + 1]);
}

node get(int v, int vl, int vr, int l, int r) {
    if (l > r) {
        node res;
        res.sz = 0;
        return res;
    }
    if (vl == l && vr == r)
        return t[v];
    push(v);
    int vm = (vl + vr) / 2;
    node a = get(v + v, vl, vm, l, min(r, vm));
    node b = get(v + v + 1, vm + 1, vr, max(l, vm + 1), r);
    node res = combine(a, b);
    return res;
}

void go(int v, int vl, int vr) {
    if (vl == vr)
        return;
    push(v);
    int vm = (vl + vr) / 2;
    go(v + v, vl, vm);
    go(v + v + 1, vm + 1, vr);
    t[v] = combine(t[v + v], t[v + v + 1]);
    cout << vl << ' ' << vr<< ' '<< t[v].m1 << ' '<< t[v].x1 << ' ' << t[v].x2 << endl;
    cout << "   " << t[v].t1 << ' ' << t[v].t2 << endl;
    cout << "   " << t[v].y1 << ' ' << t[v].y2 << endl;

}


signed main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        /*if (rand() % 2)
            a[i] = '>';
        else
            a[i] = '<';
        cout << a[i];
        */
        cin >> a[i];
    }
    //cout << "\n";
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        //l = rand() % n + 1;
        //r = rand() % n + 1;
        if (l > r)
            swap(l, r);
        //cout << l << ' ' << r << endl;
        rev(1, 1, n, l, r);
        node res = get(1, 1, n, l, r);
        int x = max(max(res.x1, res.x2), res.m1);
        cout << x << "\n";
        /*for (int j = l; j <= r; j++)
            if (a[j] == '<')
                a[j] = '>';
            else
                a[j] = '<';
        int ans = 0;
        int c1 = 0, c2 = 0;
        for (int j = l; j <= r; j++)
            if (a[j] == '>')
                if (c2 != 0)
                    ans = max(ans, c1 + c2), c2 = 0, c1 = 1;
                else
                    c1++;
            else
                c2++;
        //go(1, 1, n);
        ans = max(ans, c1 + c2);
        cout << ans << "\n";
        if (ans != x)
            cout << "WOW\n";
        for (int i = 1; i <= n; i++)
            cout << a[i];*/
    }
    return 0;
}
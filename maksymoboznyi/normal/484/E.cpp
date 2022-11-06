#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;
const int K = 80;

struct node {
    int pref, suff, ans, is;
    node(int x) {
        pref = suff = ans = is = x;
    }
    node () {
        pref = suff = ans = 0;
        is = 0;
    };
};

int L, R, w, n, a[N], root[N], l[N*K], r[N*K], sz = 0;
node t[N*K];

int vcopy(int v) {
    sz++;
    t[sz] = t[v];
    l[sz] = l[v];
    r[sz] = r[v];
    return sz;
}
node c;

node combine(node a, node b) {
    c.ans = max(a.ans, max(b.ans, a.suff + b.pref));
    c.pref = a.pref;
    c.suff = b.suff;
    if (a.is)
        c.pref += b.pref;
    if (b.is)
        c.suff += a.suff;
    c.is = (a.is & b.is);
    //cout << a.ans << ' '<<b.ans << ' ' << c.ans << endl;
    return c;
}

int update(int v, int vl, int vr, int pos) {
    if (vl == vr) {
        int a = vcopy(v);
        t[a].pref = t[a].suff = t[a].ans = t[a].is = 1;
        //cout << '*' << a << ' ' << t[a].ans << endl;
        return a;
    }
    int tt, vm = (vl + vr) / 2;
    if (pos <= vm) {
        tt = vcopy(v);
        l[tt] = update(l[v], vl, vm, pos);
        //cout << l[tt] << ' ' << r[tt] << endl;
        t[tt] = combine(t[l[tt]], t[r[tt]]);
    } else {
        tt = vcopy(v);
        r[tt] = update(r[v], vm + 1, vr, pos);
        t[tt] = combine(t[l[tt]], t[r[tt]]);
    }
    return tt;
}

node tt;

node get(int v, int vl, int vr, int ll, int rr) {
    if (ll > rr) {
        tt.ans = tt.pref=tt.suff=0;
        tt.is = 1;
        return tt;
    }
    if (vl == ll && vr == rr) {
       // cout << ll << ' ' << rr << ' ' << t[v].ans << ' ' << t[v].is << ' ' << t[v].pref << ' ' << t[v].suff << endl;
        return t[v];
    }
    int vm = (vl + vr) / 2;
    tt = combine(get(l[v], vl, vm, ll, min(rr, vm)), get(r[v], vm + 1, vr, max(ll, vm + 1), rr));
    //cout << vl << ' ' << vr << ' ' << ll << ' ' << rr << ' '<< tt.ans << endl;
    return tt;
}

vector<pair<int, int> > v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first)
        return a.first > b.first;
    return a.second > b.second;
}

int build(int vl, int vr) {
    sz++;
    if (vl == vr)
        return sz;
    int vm = (vl + vr) / 2;
    l[sz] = build(vl, vm);
    r[sz] = build(vm + 1, vr);
    return sz;
}

bool check(int h) {
    int ll = 0, rr = v.size();
    while (ll < rr - 1) {
        int m = (ll + rr) / 2;
        if (v[m].first >= h)
            ll = m;
        else
            rr = m;
    }
    int pos = ll;
    //cout << w << endl;
    if (v[pos].first < h)
        return 0;
    if (get(root[pos + 1], 1, n, L, R).ans < w)
        return 0;
    return 1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], v.pb({a[i], i});
    sort(v.begin(), v.end(), cmp);
    root[0] = build(1, n);
    for (int i = 1; i <= n; i++)
        root[i] = update(root[i - 1], 1, n, v[i - 1].second);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> L >> R >> w;
        int ll = 0, rr = 1e9 + 9;
        while (ll < rr - 1)
        {
            int mm = (ll + rr) / 2;
            if (check(mm))
                ll = mm;
            else
                rr = mm;
        }
        cout << ll<<"\n";
    }
    return 0;
}
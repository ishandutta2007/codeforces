#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long

using namespace std;

const int N = 300'050;

struct cell {
    int p, p1, p2, p12, p23, ans;
};

int n, Q, W;
int c[N], l[N], r[N], s[N], cur = 1;

vector<pair<int, int> > g[N];
cell t[4*N];

void dfs(int v, int p) {
    l[v] = cur;
    cur++;
    //cout << v << ' ';
    for (auto [u, i]: g[v])
        if (u != p)
            s[i] = u, dfs(u, v), cur++;
    //cout << v << ' ';
    r[v] = cur;
    cur++;
}

cell combine(cell a, cell b) {
    cell res;
    res.p = 0;
    res.p1 = max(a.p1, b.p1);
    res.p2 = max(a.p2, b.p2);
    res.p12 = max(max(a.p12, b.p12), a.p1 + b.p2);
    res.p23 = max(max(a.p23, b.p23), a.p2 + b.p1);
    res.ans = max(max(a.ans, b.ans), max(a.p1 + b.p23, a.p12 + b.p1));
    return res;
}

void add(cell &a, int x) {
    a.p += x;
    a.p1 += x;
    a.p2 -= 2 * x;
    a.p12 -= x;
    a.p23 -= x;
}

void push(int v) {
    add(t[v + v], t[v].p);
    add(t[v + v + 1], t[v].p);

    t[v].p = 0;
}

void update(int v, int vl, int vr, int l, int r, int x) {
    if (l > r)
        return;
    if (vl == l && vr == r) {
        add(t[v], x);
        //cout << vl << ' ' << vr << ' ' << t[v].ans << endl;
        return;
    }
    int vm = (vl + vr) / 2;
    push(v);
    update(v + v, vl, vm, l, min(r, vm), x);
    update(v + v + 1, vm + 1, vr, max(l, vm + 1), r, x);
    t[v] = combine(t[v + v], t[v + v + 1]);
    //cout << vl << ' ' << vr << ' ' << t[v].ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> Q >> W;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b >> c[i];
        g[a].pb({b, i});
        g[b].pb({a, i});
    }
    dfs(1, 0);
    //cout << endl;
    for (int i = 1; i < n; i++)
        update(1, 1, cur, l[s[i]], r[s[i]], c[i]);//, cout << l[s[i]] << ' ' << r[s[i]] << endl;

    int last = 0;
    while (Q--) {
        int id, x;
        cin >> id >> x;
        id = (id + last) % (n - 1) + 1;
        x = (x + last) % W;
        update(1, 1, cur, l[s[id]], r[s[id]], x - c[id]);
        c[id] = x;
        last = t[1].ans;
        cout << last << "\n";
    }
    //cout << t[1].ans;
    return 0;
}
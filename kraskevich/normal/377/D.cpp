#include <bits/stdc++.h>

using namespace std;

#define PII pair<int, int>
#define F first
#define S second

struct man
{
    int l, r, v;
    int id;

    void read(int i)
    {
        id = i;
        cin >> l >> v >> r;
    }
};

vector<man> mn;

const int INF = 1000 * 1000 * 1000;
const int N = 3 * 100 * 1000 + 10;

vector<int> add[N];
vector<int> del[N];
vector<int> here[N];
int n;

PII tree[4 * N];
int a[4 * N];

PII get(int i, int l, int r, int tl, int tr, int tot)
{
    tot += a[i];
    if (l == tl && r == tr)
        return PII(tree[i].F + tot, tree[i].S);
    PII sl(-INF, -INF);
    PII sr(-INF, -INF);
    int m = (tl + tr) / 2;
    if (l <= m)
        sl = get(2 * i + 1, l, min(r, m), tl, m, tot);
    if (r > m)
        sr = get(2 * i + 2, max(m + 1, l), r, m + 1, tr, tot);
    return max(sl, sr);
}

void build(int i, int l, int r)
{
    if (l == r)
    {
        a[i] = 0;
        tree[i].F = 0;
        tree[i].S = l;
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = tree[2 * i + 1];
}

void put(int i, int l, int r, int tl, int tr, int by)
{
    if (l == tl && r == tr)
    {
        a[i] += by;
        return;
    }
    int m = (tl + tr) / 2;
    if (l <= m)
        put(2 * i + 1, l, min(r, m), tl, m, by);
    if (r > m)
        put(2 * i + 2, max(m + 1, l), r, m + 1, tr, by);
    tree[i] = max(get(2 * i + 1, 0, 0, 0, 0, 0), get(2 * i + 2, 0, 0, 0, 0, 0));
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    build(0, 0, N);

    cin >> n;
    mn.resize(n);
    for (int i = 0; i < n; i++)
        mn[i].read(i + 1);
    for (int i = 0; i < n; i++)
    {
        int l = mn[i].l;
        int r = mn[i].r;
        int v = mn[i].v;
        add[l].push_back(i);
        del[v + 1].push_back(i);
        here[v].push_back(i);
    }
    int res = 0;
    int resx = 0;
    int resl = 0;
    for (int x = 0; x < N; x++)
    {
        for (int id : add[x])
            put(0, mn[id].v, mn[id].r, 0, N, 1);
        for (int id : del[x])
            put(0, mn[id].v, mn[id].r, 0, N, -1);
        for (int id : here[x])
        {
            int lo = mn[id].v;
            int hi = mn[id].r;
            PII cur = get(0, lo, hi, 0, N, 0);
            if (cur.F > res)
            {
                res = cur.F;
                resx = cur.S;
                resl = x;
            }
        }
    }
    assert(res);
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (mn[i].v >= resl && mn[i].r >= resx && mn[i].v <= resx && mn[i].l <= resl)
            ans.push_back(mn[i].id);
    //cerr << res << " " << resx << " " << resl << endl;
    sort(ans.begin(), ans.end());
    assert(ans.size() == res);
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x << " ";


    return 0;
}
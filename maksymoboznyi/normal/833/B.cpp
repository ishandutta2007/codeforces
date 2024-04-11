#include <iostream>
#pragma GCC optimize ("O3")
using namespace std;

const int N = 40000;

int n, a[N], dp[N][51], p[N][51];

struct node
{
    int sum;
    node *l, *r;
    node(int s)
    {
        sum = s;
        l = r = 0;
    }
    node(node *ll, node *rr)
    {
        sum = 0, l = ll, r = rr;
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

typedef node *tnode;
int pre[N], kol[N], last[N];
int root[N], sz = 1, l[64*N], r[64*N], t[64*N];

int getv(int v)
{
    if (!v)
        return 0;
    return t[v];
}


int vcopy(int v) {
    sz++;
    t[sz] = t[v];
    l[sz] = l[v];
    r[sz] = r[v];
    return sz;
}

int go(int ll, int rr, int vl, int vr, int pos) {
    if (vl == vr)
        return t[rr] - t[ll];
    int vm = (vl + vr) / 2;
    if (pos <= vm)
        return go(l[ll], l[rr], vl, vm, pos);
    else
        return getv(l[rr]) - getv(l[ll]) + go(r[ll], r[rr], vm + 1, vr, pos);
}

int get(int l, int r) {
    int x = go(root[l - 1], root[r], 0, n, l-1);
    return x;
}

int update(int v, int vl, int vr, int pos) {
    if (vl == vr) {
        int a = vcopy(v);
        t[a] = kol[pos] + 1;
        kol[pos]++;
        return a;
    }
    int tt, vm = (vl + vr) / 2;
    if (pos <= vm) {
        tt = vcopy(v);
        l[tt] = update(l[v], vl, vm, pos);
        //cout << l[tt] << ' ' << r[tt] << endl;
        t[tt] = t[l[tt]] + t[r[tt]];
    } else {
        tt = vcopy(v);
        r[tt] = update(r[v], vm + 1, vr, pos);
        t[tt] = t[l[tt]] + t[r[tt]];
    }
    return tt;
}


void solve(int k, int l, int r, int tl, int tr) {
    int pos = (l + r) / 2;
    for (int i = tl; i <= tr; i++)
        if (i >= k - 1 && i <= pos && dp[pos][k] < get(i, pos) + dp[i - 1][k - 1])
        {
            dp[pos][k] = get(i, pos) + dp[i - 1][k - 1];
            p[pos][k] = i;
        }
   // cout << pos << ' ' << k << ' ' << dp[pos][k] << ' ' << tl << ' ' << tr << ' ' << p[pos][k] << endl;
    if (l == r)
        return;
    solve(k, l, pos, tl, p[pos][k]);
    solve(k, pos + 1, r, p[pos][k], tr);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int K;
    cin >> n >> K;
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = last[a[i]], last[a[i]] = i;
    root[0] = 0;
    for (int i = 1; i <= n; i++)
        root[i] = update(root[i-1], 0, n, pre[i]);

   for (int i = 1; i <= n; i++)
        dp[i][1] = get(1, i);
    for (int k = 2; k <= K; k++)
        solve(k, 1, n, 1, n);
    cout << dp[n][K];
    return 0;
}
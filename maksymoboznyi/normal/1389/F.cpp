#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 4e5 + 5;

struct cell {
    int l, r, c;
};

vector<int> ls[N][2];
int n, dp[N][2];
cell a[N];
int b0[4*N], b1[4*N], p0[4*N], p1[4*N];

void push0(int v) {
    b0[v + v] += p0[v];
    b0[v + v + 1] += p0[v];

    p0[v + v] += p0[v];
    p0[v + v + 1] += p0[v];

    p0[v] = 0;
}

void add0(int v, int vl, int vr, int l, int r, int x) {
    if (l > r)
        return;
    if (vl == l && vr == r) {
        b0[v] += x;
        p0[v] += x;
        return;
    }
    push0(v);
    int vm = (vl + vr) / 2;
    add0(v + v, vl, vm, l, min(r, vm), x);
    add0(v + v + 1, vm + 1, vr, max(l, vm + 1), r, x);
    b0[v] = max(b0[v + v], b0[v + v + 1]);
}

int get0(int v, int vl, int vr, int l, int r) {
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return b0[v];
    int vm = (vl + vr) / 2;
    push0(v);
    return max(get0(v + v, vl, vm, l, min(r, vm)), get0(v + v + 1, vm + 1, vr, max(l, vm + 1), r));
}




void push1(int v) {
    b1[v + v] += p1[v];
    b1[v + v + 1] += p1[v];

    p1[v + v] += p1[v];
    p1[v + v + 1] += p1[v];

    p1[v] = 0;
}

void add1(int v, int vl, int vr, int l, int r, int x) {
    if (l > r)
        return;
    if (vl == l && vr == r) {
        b1[v] += x;
        p1[v] += x;
        return;
    }
    push1(v);
    int vm = (vl + vr) / 2;
    add1(v + v, vl, vm, l, min(r, vm), x);
    add1(v + v + 1, vm + 1, vr, max(l, vm + 1), r, x);
    b1[v] = max(b1[v + v], b1[v + v + 1]);
}

int get1(int v, int vl, int vr, int l, int r) {
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return b1[v];
    int vm = (vl + vr) / 2;
    push1(v);
    return max(get1(v + v, vl, vm, l, min(r, vm)), get1(v + v + 1, vm + 1, vr, max(l, vm + 1), r));
}


int main()
{
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].c;
        v.pb(a[i].l);
        v.pb(a[i].r);
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    for (int i = 1; i <= n; i++) {
        a[i].l = lower_bound(all(v), a[i].l) - v.begin();
        a[i].r = lower_bound(all(v), a[i].r) - v.begin();
        a[i].c--;
        ls[a[i].r][a[i].c].pb(a[i].l);
    }
    for (int i = 0; i < v.size(); i++) {
        for (auto l: ls[i][0])
            add0(1, 0, v.size() - 1, 0, l, 1);
        for (auto l: ls[i][1])
            add1(1, 0, v.size() - 1, 0, l, 1);

        if (i != 0)
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = max(dp[i][0], get0(1, 0, v.size() - 1, 0, i));
        if (i + 1 != v.size())
            add1(1, 0, v.size() - 1, i + 1, i + 1, dp[i][0]);

        if (i != 0)
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i][1], get1(1, 0, v.size() - 1, 0, i));
        if (i + 1 != v.size())
            add0(1, 0, v.size() - 1, i + 1, i + 1, dp[i][1]);

    }
    cout << max(dp[v.size() - 1][0], dp[v.size() - 1][1]);
    return 0;
}
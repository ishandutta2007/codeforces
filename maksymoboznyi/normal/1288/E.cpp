#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 3e5 + 5;

vector<int> p[N];
int n, m, mn[N], mx[N], a[N], was[N], t[4 * N];

void add(int r) {
    for (; r <= n; r = (r | (r + 1)))
        t[r]++;
}

int sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += t[r];
    return res;
}

int cur[N];

int get(int l, int r) {
    return sum(r) - sum(l - 1);
}

void update(int v, int vl, int vr, int pos, int val) {
    if (vl == vr) {
        t[v] += val;
        return;
    }
    int vm = (vl + vr) / 2;
    if (pos <= vm)
        update(v + v, vl, vm, pos, val);
    else
        update(v + v + 1, vm + 1, vr, pos, val);
    t[v] = t[v + v] + t[v + v + 1];
}

int get1(int v, int vl, int vr, int l, int r) {
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return t[v];
    int vm = (vl + vr) / 2;
    return get1(v + v, vl, vm, l, min(r, vm)) + get1(v + v + 1, vm + 1, vr,  max(l, vm + 1), r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        mn[i] = mx[i] = i;

    int kol = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        p[a[i]].pb(i);
        mn[a[i]] = 1;
        if (p[a[i]].size() == 1) {
           // cout << get(a[i] + 1, n) << endl;
            mx[a[i]] = max(mx[a[i]], a[i] + get(a[i] + 1, n));
            add(a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
        if (p[i].size() == 0)
            mx[i] = max(mx[i], i + get(i + 1, n));

    for (int i = 0; i < N; i++)
        t[i] = 0, cur[i] = -1;

    for (int i = 1; i <= m; i++) {
        if (cur[a[i]] != -1) {
            mx[a[i]] = max(mx[a[i]], 1 + get1(1, 1, m, p[a[i]][cur[a[i]]] + 1, m));
            update(1, 1, m, p[a[i]][cur[a[i]]], -1);
        }
        cur[a[i]]++;
        update(1, 1, m, p[a[i]][cur[a[i]]], 1);
    }
    for (int i = 1; i <= n; i++)
        if (p[i].size() != 0)
            mx[i] = max(mx[i], 1 + get1(1, 1, m, p[i].back() + 1, m));//, cout << "1111" << endl;
    for (int i = 1; i <= n; i++)
        cout << mn[i] << ' ' << mx[i] << "\n";
    return 0;
}
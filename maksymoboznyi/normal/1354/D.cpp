#include <bits/stdc++.h>
#define pb push_back
#define all(q) (q).begin(), (q).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 1e6 + 6;

int n, q, t[4 * N];

void upd(int v, int vl, int vr, int pos, int val) {
    t[v] += val;
    if (vl == vr)
        return;
    int vm = (vl + vr) / 2;
    if (pos <= vm)
        upd(v + v, vl, vm, pos, val);
    else
        upd(v + v + 1, vm + 1, vr, pos, val);
    t[v] = t[v + v] + t[v + v + 1];
}

void go(int v, int vl, int vr, int k) {
    t[v]--;
    if (vl == vr)
        return;
    int vm = (vl + vr) / 2;
    if (t[v + v] >= k)
        go(v + v, vl, vm, k);
    else
        go(v + v + 1, vm + 1, vr, k - t[v + v]);
    t[v] = t[v + v] + t[v + v + 1];
}


void f(int v, int vl, int vr) {
    if (t[v] == 0)
        return;
    if (vl == vr) {
        cout << vl;
        exit(0);
    }
    int vm = (vl + vr) / 2;
    if (t[v + v] > 0)
        f(v + v, vl, vm);
    else
        f(v + v + 1, vm + 1, vr);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        upd(1, 1, n, x, 1);
    }
    for (int i = 1; i <= q; i++) {
        int k;
        cin >> k;
        if (k > 0) {
            upd(1, 1, n, k, 1);
        } else {
            go(1, 1, n, -k);
        }
    }
    f(1, 1, n);
    cout << 0;
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 5e5 + 5;
const int M = 998244353;

struct cell {
    int x, xn, x1, x1n;
    int v1, vn;
};

int n, m, a[N];
cell t[4*N];

int get(int a, int b) {
    if (a != 1 || b == 9)
        return 0;
    return 19 - (a * 10 + b);
}

cell combine(cell a, cell b) {
    cell res;

    int kol = get(a.vn, b.v1);
    res.x = a.x * b.x + a.xn * b.x1 % M * kol;
    res.x %= M;

    res.x1 = a.x1 * b.x + a.x1n * b.x1 % M * kol;
    res.x1 %= M;

    res.xn = a.x * b.xn + a.xn * b.x1n % M * kol;
    res.xn %= M;

    res.x1n = a.x1 * b.xn + a.x1n * b.x1n % M * kol;
    res.x1n %= M;

    res.v1 = a.v1;
    res.vn = b.vn;
    return res;
}

void update(int v, int vl, int vr, int pos) {
    if (vl == vr) {
        t[v].x = a[pos] + 1;
        t[v].xn = t[v].x1 = 1;
        t[v].x1n = 0;
        t[v].v1 = t[v].vn = a[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    if (pos <= vm)
        update(v + v, vl, vm, pos);
    else
        update(v + v + 1, vm + 1, vr, pos);
    t[v] = combine(t[v + v], t[v + v + 1]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
        update(1, 1, n, i);
    }
    //cout << t[1].x << endl;
    for (int i = 1; i <= m; i++) {
        int pos, val;
        cin >> pos >> val;
        a[pos] = val;
        update(1, 1, n, pos);
        cout << t[1].x << "\n";
        //cout << t[2].xn<< ' ' << t[3].x1 << endl;
    }
    return 0;
}
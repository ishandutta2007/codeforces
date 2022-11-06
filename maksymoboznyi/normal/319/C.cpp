#include <iostream>
using namespace std;

const int N = 2e6;

struct Line {
    long long k, b;
};

struct cell {
    Line q;
    int l, r;
};

cell t[N];
int cur = 1;

long long f(Line a, int x) {
    return a.k * x + a.b;
}

void add(int v, int vl, int vr, Line l) {
    int vm = (vl + vr) / 2;
    bool lef = f(t[v].q, vl) > f(l, vl);
    bool mid = f(t[v].q, vm) > f(l, vm);
    if (vr == vl)
        return;
    if (mid) {
        swap(t[v].q, l);
    }
    if (lef != mid) {
        if (t[v].l == 0) {
            cur++;
            if (cur >= N)
                exit(0);
            t[v].l = cur;
        }
        add(t[v].l, vl, vm, l);
    } else {
        if (t[v].r == 0) {
            cur++;

            if (cur >= N)
                exit(0);
            t[v].r = cur;
        }
        add(t[v].r, vm + 1, vr, l);
    }
}

long long get(int v, int vl, int vr, int pos) {
    long long res = f(t[v].q, pos);
    int vm = (vl + vr) / 2;
    if (t[v].l != 0 && pos <= vm)
        res = min(res, get(t[v].l, vl, vm, pos));
    if (t[v].r != 0 && pos > vm)
        res = min(res, get(t[v].r, vm + 1, vr, pos));
    return res;
}

int n, a[N / 10], b[N / 10];

signed main()
{
    cin >> n;
    for (int i = 0; i < N; i++)
        t[i].q.b = 1e18;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    add(1, 1, 1e9, {b[1], 0});
    long long x;
    for (int i = 2; i <= n; i++) {
        x = get(1, 1, 1e9, a[i]);
        add(1, 1, 1e9, {b[i], x});
    }
    cout << x;
    return 0;
}
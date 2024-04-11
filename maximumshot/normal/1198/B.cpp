#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n;
int a[N];
int pu[4 * N];

void push(int v) {
    pu[v << 1] = max(pu[v << 1], pu[v]);
    pu[v << 1 | 1] = max(pu[v << 1 | 1], pu[v]);
    pu[v] = 0;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        pu[v] = a[tl];
    } else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
    }
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if (l <= tl && tr <= r) {
        pu[v] = max(pu[v], x);
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        if (l <= tm) {
            update(v << 1, tl, tm, l, r, x);
        }
        if (r > tm) {
            update(v << 1 | 1, tm + 1, tr, l, r, x);
        }
    }
}

void put(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        pu[v] = val;
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        if (pos <= tm) {
            put(v << 1, tl, tm, pos, val);
        } else {
            put(v << 1 | 1, tm + 1, tr, pos, val);
        }
    }
}

void show(int v, int tl, int tr) {
    if (tl == tr) {
        cout << pu[v] << " ";
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        show(v << 1, tl, tm);
        show(v << 1 | 1, tm + 1, tr);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            put(1, 1, n, p, x);
        } else {
            int x;
            cin >> x;
            update(1, 1, n, 1, n, x);
        }
    }

    show(1, 1, n);

    return 0;
}
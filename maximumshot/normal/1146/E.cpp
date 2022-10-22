#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 50;
const int X = 1e5 + 5;

int n, q;
int a[N];

int ad[4 * N];
int pu[4 * N];
int PU[4 * N];
int AD[4 * N];

void change(int v, int x) {
    if (pu[v] == -1) {
        ad[v] ^= x;
    } else {
        pu[v] ^= x;
    }
}

void put(int v, int x) {
    pu[v] = x;
    ad[v] = 0;
}

void push(int v) {
    if (pu[v] == -1) {
        change(v << 1, ad[v]);
        change(v << 1 | 1, ad[v]);
    } else {
        put(v << 1, pu[v]);
        put(v << 1 | 1, pu[v]);
    }
    ad[v] = 0;
    pu[v] = -1;
}

void change(int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) {
        change(v, 1);
    } else {
        int tm = (tl + tr) / 2;
        push(v);
        if (l <= tm) change(v << 1, tl, tm, l, r);
        if (r > tm) change(v << 1 | 1, tm + 1, tr, l, r);
    };
}

void put(int v, int tl, int tr, int l, int r, int x) {
    if (l <= tl && tr <= r) {
        put(v, x);
    } else {
        int tm = (tl + tr) / 2;
        push(v);
        if (l <= tm) put(v << 1, tl, tm, l, r, x);
        if (r > tm) put(v << 1 | 1, tm + 1, tr, l, r, x);
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        if (pu[v] == -1) {
            AD[tl] = ad[v];
            PU[tl] = -1;
        } else {
            PU[tl] = pu[v];
        }
    } else {
        int tm = (tl + tr) / 2;
        push(v);
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    fill(ad, ad + 4 * N, 0);
    fill(pu, pu + 4 * N, -1);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<pair<char, int>> qs;

    for (int iter = 0; iter < q; iter++) {
        char op;
        cin >> op;
        int x;
        cin >> x;
        qs.push_back({op, x});
    }

    for (pair<char, int> qi : qs) {
        char op;
        int x;
        tie(op, x) = qi;
        if (x >= 0) {
            if (op == '<') {
                put(1, 0, X, x, X, 1);
                if (x)
                    change(1, 0, X, 0, x - 1);
            } else {
                put(1, 0, X, x + 1, X, 0);
            }
        } else {
            if (op == '<') {
                put(1, 0, X, -x + 1, X, 1);
            } else {
                put(1, 0, X, -x, X, 0);
                if (x)
                    change(1, 0, X, 0, -x - 1);
            }
        }
    }

    build(1, 0, X);

    for (int i = 1; i <= n; i++) {
        int x = a[i] >= 0 ? a[i] : -a[i];
        if (PU[x] == -1) {
            cout << (AD[x] ? -a[i] : a[i]) << " ";
        } else {
            cout << (PU[x] ? x : -x) << " ";
        }
    }

    cout << endl;

    return 0;
}
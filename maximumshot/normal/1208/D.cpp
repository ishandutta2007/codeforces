#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n;
ll s[N];
ll p[N];
unordered_map<ll, ll> sm;

ll mn[4 * N];
ll mx[4 * N];
ll pu[4 * N];
ll cn[4 * N];

void inc(int v, ll x) {
    mn[v] += x;
    mx[v] += x;
    pu[v] += x;
}

void push(int v) {
    inc(v << 1, pu[v]);
    inc(v << 1 | 1, pu[v]);
    pu[v] = 0;
}

void merge(int v) {
    mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
    mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
    cn[v] = cn[v << 1] + cn[v << 1 | 1];
}

void update(int v, int tl, int tr, int l, int r, ll x) {
    if (l <= tl && tr <= r) {
        inc(v, x);
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        if (l <= tm) {
            update(v << 1, tl, tm, l, r, x);
        }
        if (r > tm) {
            update(v << 1 | 1, tm + 1, tr, l, r, x);
        }
        merge(v);
    }
}

void put(int v, int tl, int tr, int p, ll x, int act) {
    if (tl == tr) {
        mn[v] = x;
        mx[v] = x;
        pu[v] = 0;
        cn[v] = act * tl;
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        if (p <= tm) {
            put(v << 1, tl, tm, p, x, act);
        } else {
            put(v << 1 | 1, tm + 1, tr, p, x, act);
        }
        merge(v);
    }
}

ll get(int v, int tl, int tr, ll x) {
    if (tl == tr) {
        if (mx[v] <= x) {
            return cn[v];
        } else {
            return 0;
        }
    } else {
        int tm = (tl + tr) >> 1;
        ll res = 0;
        push(v);
        if (mx[v << 1] <= x) {
            res += cn[v << 1];
            res += get(v << 1 | 1, tm + 1, tr, x);
        } else {
            res += get(v << 1, tl, tm, x);
        }
        merge(v);
        return res;
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
        cin >> s[i];
    }

    {
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            cur += i;
            sm[cur] = i + 1;
        }
    }

    p[n] = sm[s[n]];
    put(1, 1, n, p[n], s[n], 1);

    for (int i = n - 1; i >= 1; i--) {
        ll hlp = get(1, 1, n, s[i]);
        p[i] = sm[s[i] + hlp];
        put(1, 1, n, p[i], s[i], 1);
        if (p[i] < n) {
            update(1, 1, n, p[i] + 1, n, -p[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";

    return 0;
}
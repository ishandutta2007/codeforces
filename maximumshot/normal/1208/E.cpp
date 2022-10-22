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

const int N = 1e6 + 5;

int n, w;
vector<int> a[N];
ll S[N];

ll pu[4 * N];

void upd(int v, ll x) {
    pu[v] = max(pu[v], x);
}

void push(int v) {
    upd(v << 1, pu[v]);
    upd(v << 1 | 1, pu[v]);
}

void update(int v, int tl, int tr, int l, int r, ll x) {
    if (l <= tl && tr <= r) {
        upd(v, x);
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

void get(int v, int tl, int tr, vector<ll>& vals) {
    if (tl == tr) {
        vals.push_back(pu[v]);
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        get(v << 1, tl, tm, vals);
        get(v << 1 | 1, tm + 1, tr, vals);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w;

    for (int i = 1; i <= n; i++) {
        int sz;
        cin >> sz;
        a[i].resize(sz);
        for (int j = 0; j < sz; j++) {
            cin >> a[i][j];
        }
        vector<pair<int, pii>> segs;
        segs.reserve(sz);
        for (int j = 0; j < sz; j++) {
            segs.push_back({a[i][j], {j, j + w - sz}});
        }
        if (sz < w) {
            segs.push_back({0, {sz, w - 1}});
            segs.push_back({0, {0, w - sz - 1}});
        }
        vector<int> crd;
        crd.push_back(w);
        for (auto it : segs) {
            int x;
            int l, r;
            tie(l, r) = it.second;
            x = it.first;
            crd.push_back(l);
            crd.push_back(r + 1);
        }
        sort(crd.begin(), crd.end());
        crd.resize(unique(crd.begin(), crd.end()) - crd.begin());
        int ss = (int) crd.size() - 1;
        fill(pu, pu + 4 * ss, -inf64);
        for (auto it : segs) {
            int x;
            int l, r;
            tie(l, r) = it.second;
            x = it.first;

            l = lower_bound(crd.begin(), crd.end(), l) - crd.begin();
            r = lower_bound(crd.begin(), crd.end(), r + 1) - crd.begin() - 1;

            update(1, 0, ss - 1, l, r, x);
        }

        vector<ll> vals;
        vals.reserve(ss);
        get(1, 0, ss - 1, vals);

        for (int it = 0; it < (int) vals.size(); it++) {
            int l = crd[it];
            int r = crd[it + 1] - 1;
            S[l] += vals[it];
            S[r + 1] -= vals[it];
        }
    }

    for (int i = 0; i < w; i++) {
        S[i + 1] += S[i];
    }

    for (int i = 0; i < w; i++) {
        cout << S[i] << " ";
    }
    cout << "\n";

    return 0;
}
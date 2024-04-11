#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct DSU {
    int n = 0;
    vector<int> p, sz;

    DSU() = default;

    DSU(int nn) {
        n = nn;
        p.resize(n);
        sz.resize(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
    }
};

const int X = 1e6 + 5;

int pr[X];
vector<int> dv[X];

void precalc() {
    fill(pr, pr + X, 1);
    pr[0] = pr[1] = 0;
    for (int p = 2; p * p < X; p++) {
        if (!pr[p])
            continue;
        for (int x = p * p; x < X; x += p)
            pr[x] = 0;
    }
    for (int p = 2; p < X; p++) {
        if (!pr[p])
            continue;
        for (int x = p; x < X; x += p)
            dv[x].push_back(p);
    }
}

ll gcd(ll x, ll y) {
    return !x ? y : gcd(y % x, x);
}

bool check(vector<ll> a, int s, int t) {
    int n = (int) a.size();
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd(a[i], a[j]) > 1)
                dsu.merge(i, j);
        }
    }
    return dsu.find(s) == dsu.find(t);
}

vector<int> slow(int n, int q, vector<int> a, vector<pii> b) {
    vector<ll> A(a.begin(), a.end());
    vector<int> res(q);
    for (int it = 0; it < q; it++) {
        auto [s, t] = b[it];
        s--, t--;
        if (check(A, s, t)) {
            res[it] = 0;
        } else {
            res[it] = 2;
            for (int i = 0; i < n; i++) {
                A.push_back(1ll * a[i] * (a[i] + 1));
                if (check(A, s, t)) {
                    res[it] = 1;
                    A.pop_back();
                    break;
                }
                A.pop_back();
            }
        }
    }
    return res;
}

vector<int> fast(int n, int q, vector<int> a, vector<pii> b) {
    vector<vector<int>> seq(X);
    for (int i = 0; i < n; i++) {
        for (int p : dv[a[i]])
            seq[p].push_back(i);
    }
    DSU dsu(n);
    for (int p = 2; p < X; p++) {
        for (int i = 0; i + 1 < (int) seq[p].size(); i++)
            dsu.merge(seq[p][i], seq[p][i + 1]);
    }
    unordered_set<ll> edges;
    for (int i = 0; i < n; i++) {
        for (int p1 : dv[a[i]]) {
            if (seq[p1].empty())
                continue;
            for (int p2 : dv[a[i] + 1]) {
                if (seq[p2].empty())
                    continue;
                int c1 = dsu.find(seq[p1].back());
                int c2 = dsu.find(seq[p2].back());
                ll e = 1ll * n * min(c1, c2) + max(c1, c2);
                edges.insert(e);
            }
        }
        for (int x : {a[i], a[i] + 1}) {
            for (int p1 : dv[x]) {
                if (seq[p1].empty())
                    continue;
                for (int p2 : dv[x]) {
                    if (seq[p2].empty())
                        continue;
                    int c1 = dsu.find(seq[p1].back());
                    int c2 = dsu.find(seq[p2].back());
                    ll e = 1ll * n * min(c1, c2) + max(c1, c2);
                    edges.insert(e);
                }
            }
        }
    }
    vector<int> res(q);
    for (int it = 0; it < q; it++) {
        auto [s, t] = b[it];
        s--, t--;
        int ps = dsu.find(s);
        int pt = dsu.find(t);
        if (ps == pt) {
            res[it] = 0;
            continue;
        }
        ll e = 1ll * n * min(ps, pt) + max(ps, pt);
        if (edges.count(e)) res[it] = 1;
        else res[it] = 2;
    }
    return res;
}

void work() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pii> b(q);
    for (auto& [s, t] : b)
        cin >> s >> t;
    vector<int> res = fast(n, q, a, b);
    for (auto x : res)
        cout << x << "\n";
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 200;
    const int MAXX = 1000000;
    while (1) {
        int n = rnd() % MAXN + 2;
        int q = rnd() % MAXN + 1;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = rnd() % MAXX + 2;
        vector<pii> b(q);
        for (auto& [s, t] : b) {
            s = rnd() % n + 1;
            while (1) {
                t = rnd() % n + 1;
                if (s != t)
                    break;
            }
        }
        vector<int> fs = fast(n, q, a, b);
        vector<int> sl = slow(n, q, a, b);
        if (fs == sl) {
            cout << "OK( "; for (auto x : fs) cout << x << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = "; for (auto x : sl) cout << x << " "; cout << "\n";
            cout << "fnd = "; for (auto x : fs) cout << x << " "; cout << "\n";
            cout << n << " " << q << "\n";
            for (auto x : a)
                cout << x << " ";
            cout << "\n";
            for (auto [s, t] : b)
                cout << s << " " << t << "\n";
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();
    work();
//    test();

    return 0;
}
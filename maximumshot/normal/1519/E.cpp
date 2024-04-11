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

ll gcd(ll x, ll y) {
    return !x ? y : gcd(y % x, x);
}

vector<pii> slow(int n, vector<tuple<int, int, int, int>> ps) {
    vector<pii> res;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<pair<pll, int>> A;
        for (int i = 0; i < n; i++) {
            ll a, b, c, d;
            tie(a, b, c, d) = ps[i];
            if ((1 << i) & mask) {
                ll p = c * b;
                ll q = d * (a + b);
                ll g = gcd(p, q);
                p /= g;
                q /= g;
                A.emplace_back(make_pair(p, q), i);
            } else {
                ll p = (c + d) * b;
                ll q = d * a;
                ll g = gcd(p, q);
                p /= g;
                q /= g;
                A.emplace_back(make_pair(p, q), i);
            }
        }

        sort(A.begin(), A.end());
        vector<int> used(n);
        vector<pii> hlp;
        for (int i = 0; i < (int) A.size(); i++) {
            int j = i;
            vector<int> tmp;
            while (j < (int) A.size() && A[i].first == A[j].first) {
                int id = A[j++].second;
                if (used[id])
                    continue;
                tmp.push_back(id);
            }
            if ((int) tmp.size() % 2)
                tmp.pop_back();
            for (int it = 0; it < (int) tmp.size(); it += 2) {
                int u = tmp[it];
                int v = tmp[it + 1];
                if (u > v)
                    swap(u, v);
                hlp.emplace_back(u + 1, v + 1);
                used[u] = used[v] = 1;
            }
            i = j - 1;
        }

        if (hlp.size() > res.size())
            res = hlp;
    }
    return res;
}

vector<pii> fast(int n, vector<tuple<int, int, int, int>> ps) {
    vector<pair<pll, int>> A;

    auto get_pair = [&](ll p, ll q) -> pll {
        ll g = gcd(p, q);
        return {p / g, q / g};
    };

    int V = 0;
    map<pll, int> id;
    vector<vector<int>> g;
    vector<pii> edges;

    auto get_to = [&](int eid, int fr) -> int {
        return edges[eid].first == fr ? edges[eid].second : edges[eid].first;
    };

    auto get_id = [&](pll p) -> int {
        if (!id.count(p)) {
            id[p] = V++;
            g.emplace_back();
        }
        return id[p];
    };

    auto add_edge = [&](int u, int v) {
        g[u].push_back((int) edges.size());
        g[v].push_back((int) edges.size());
        edges.emplace_back(u, v);
    };

    for (int i = 0; i < n; i++) {
        ll a, b, c, d;
        tie(a, b, c, d) = ps[i];
        int u = -1, v = -1;
        {
            ll p = c * b;
            ll q = d * (a + b);
            tie(p, q) = get_pair(p, q);
            u = get_id({p, q});
        }
        {
            ll p = (c + d) * b;
            ll q = d * a;
            tie(p, q) = get_pair(p, q);
            v = get_id({p, q});
        }
        add_edge(u, v);
    }

    vector<int> used(V), tin(V);
    int timer = 0;

    vector<pii> res;

    function<int(int, int)> dfs = [&](int v, int from) -> int {
        used[v] = 1;
        tin[v] = timer++;
        vector<int> can;
        for (int eid : g[v]) {
            int to = get_to(eid, v);
            if (used[to]) {
                if (tin[v] < tin[to])
                    can.push_back(eid);
            } else {
                if (dfs(to, eid))
                    can.push_back(eid);
            }
        }
        for (int it = 0; it + 1 < (int) can.size(); it += 2) {
            int x = can[it];
            int y = can[it + 1];
            res.emplace_back(x + 1, y + 1);
        }
        if ((int) can.size() % 2 == 1) {
            if (from != -1)
                res.emplace_back(can.back() + 1, from + 1);
            return false;
        }
        return true;
    };

    for (int v = 0; v < V; v++) {
        if (!used[v])
            dfs(v, -1);
    }

    return res;
}

void work() {
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> ps(n);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ps[i] = {a, b, c, d};
    }
    auto res = fast(n, ps);
    cout << (int) res.size() << "\n";
    for (auto [u, v] : res)
        cout << u << " " << v << "\n";
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 15;
    const int MAXX = 10;
    while (1) {
        int n = rnd() % MAXN + 1;
        vector<tuple<int, int, int, int>> ps(n);
        for (int i = 0; i < n; i++) {
            int a = rnd() % MAXX + 1;
            int b = 1;
            int c = rnd() % MAXX + 1;
            int d = 1;
            ps[i] = {a, b, c, d};
        }
        auto fs = fast(n, ps);
        auto sl = slow(n, ps);
        if (fs.size() == sl.size()) {
            cout << "OK(" << (int) fs.size() << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << (int) sl.size() << "\n";
            for (auto [u, v] : sl) cout << u << " " << v << "\n";
            cout << "fnd = " << (int) fs.size() << "\n";
            for (auto [u, v] : fs) cout << u << " " << v << "\n";
            cout << "\n";
            cout << n << "\n";
            for (auto [a, b, c, d] : ps)
                cout << a << " " << b << " " << c << " " << d << "\n";
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

    work();
//    test();

    return 0;
}
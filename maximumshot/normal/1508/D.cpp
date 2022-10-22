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

struct pt {
    int x = 0;
    int y = 0;
    int a = 0;

    pt operator - (const pt& o) const {
        return {x - o.x, y - o.y};
    }

    ld angle() const {
        return atan2(y, x);
    }

    ll vector_mul(const pt& o) const {
        return 1ll * x * o.y - 1ll * y * o.x;
    }
};

struct DSU {
    int n = 0; // [0, n)
    vector<int> p;
    DSU(int nn) {
        n = nn;
        p.resize(n);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        p[y] = x;
        return true;
    }
};

vector<pii> fast(int n, vector<pt> p) {
    vector<int> color(n, -1);
    int cc = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] != -1)
            continue;
        for (int x = i; color[x] == -1; x = p[x].a)
            color[x] = cc;
        cc++;
    }
    vector<int> sz(cc);
    for (int i = 0; i < n; i++)
        sz[color[i]]++;
    int C = -1;
    for (int c = 0; c < cc; c++) {
        if (sz[c] > 1)
            C = c;
    }
    if (C == -1)
        return {};
    for (int i = 0; i < n; i++) {
        if (color[i] == C) {
            C = i;
            break;
        }
    }
    vector<int> perm;
    for (int i = 0; i < n; i++) {
        if (i == C)
            continue;
        perm.push_back(i);
    }
    sort(perm.begin(), perm.end(), [&](int i, int j) {
        return (p[i] - p[C]).angle() < (p[j] - p[C]).angle();
    });
    for (int i = 0; i < (int) perm.size(); i++) {
        int j = (i + 1) % (int) perm.size();
        if ((p[perm[i]] - p[C]).vector_mul(p[perm[j]] - p[C]) < 0) {
            rotate(perm.begin(), perm.begin() + j, perm.end());
            break;
        }
    }
    DSU dsu(cc);
    vector<pii> res;
    for (int i = 0; i + 1 < (int) perm.size(); i++) {
        if (dsu.merge(color[perm[i]], color[perm[i + 1]])) {
            res.emplace_back(perm[i] + 1, perm[i + 1] + 1);
            swap(p[perm[i]].a, p[perm[i + 1]].a);
        }
    }
    for (int x = p[C].a; x != C; x = p[x].a)
        res.emplace_back(C + 1, x + 1);
    return res;
}

void work() {
    int n;
    cin >> n;
    vector<pt> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y >> p[i].a, p[i].a--;
    vector<pii> fs = fast(n, p);
    cout << (int) fs.size() << "\n";
    for (auto [i, j] : fs)
        cout << i << " " << j << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}
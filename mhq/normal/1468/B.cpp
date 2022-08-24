#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 2e5 + 10;
int a[maxN];
struct ConvexHullLine {
    int64_t a, b;

    inline int64_t f(int64_t x) {
        return a*x + b;
    }

    ConvexHullLine() {
    }

    ConvexHullLine(int64_t a, int64_t b)
        : a(a), b(b) {
    }
};

inline bool operator<(const ConvexHullLine &a, const ConvexHullLine &b) {
    return make_pair(a.a, -a.b) < make_pair(b.a, -b.b);
}

ll pref[maxN];

#ifdef DEBUG
#define __int128_t ll
#endif

class ConvexHullTrick {
public:
    vector<ConvexHullLine> convexHull;

    inline void add(const ConvexHullLine &ln) {
        while (convexHull.size() > 1) {
            ConvexHullLine
                _1 = convexHull[convexHull.size() - 2],
                _2 = convexHull[convexHull.size() - 1],
                _3 = ln;
            if (
                __int128_t(_2.a - _1.a) * (_2.b - _3.b) <=
                __int128_t(_1.b - _2.b) * (_3.a - _2.a)
                ) {
                convexHull.pop_back();
            } else {
                break;
            }
        }
        convexHull.push_back(ln);
    }
public:
    inline int64_t query(int64_t x) {
        int l = 0, r = (int)convexHull.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (convexHull[m].f(x) > convexHull[m+1].f(x)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return convexHull[l].f(x);
    }

    ConvexHullTrick() {
    }
};

ll when[maxN];
int clr[maxN];
int sz[maxN];
int p[maxN];
int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}
int TOT = 0;
void unite(int a, int b) {
    a = get(a);
    b = get(b);
    assert(a != b);
    sz[a] += sz[b];
    TOT = max(TOT, sz[a]);
    p[b] = a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    ConvexHullTrick F;
    ConvexHullLine T(0, 0);
    F.add(T);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        ConvexHullLine G(i, -pref[i]);
        ll r = 1e9 + 10;
        ll l = 0;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (G.f(mid) >= F.query(mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        when[i] = r;
        F.add(G);
    }
    when[n] = -1;
    vector<pair<ll,int>> ask;
    vector<int> ans(m + 1);
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        ask.emplace_back(k, i);
    }
    for (int i = 1; i <= n; i++) {
        ask.emplace_back(when[i], ~i);
    }
    sort(ask.begin(), ask.end());
    reverse(ask.begin(), ask.end());
    for (auto& it : ask) {
        if (it.second < 0) {
            int pos = ~it.second;
            p[pos] = pos;
            sz[pos] = 1;
            TOT = max(TOT, 1);
            clr[pos] = 1;
            if (pos > 0 && clr[pos - 1] != 0) unite(pos, pos - 1);
            if (pos + 1 < n && clr[pos + 1] != 0) unite(pos, pos + 1);
        }
        else {
            ans[it.second] = TOT;
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";

    return 0;
}
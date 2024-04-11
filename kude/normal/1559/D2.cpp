#include<bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    dsu d1(n), d2(n);
    set<int> l1, l2;
    rep(i, n) l1.insert(i), l2.insert(i);
    rep(_, m1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int lu = d1.leader(u), lv = d1.leader(v);
        l1.erase(lu), l1.erase(lv);
        d1.merge(lu, lv);
        l1.insert(d1.leader(lu));
    }
    rep(_, m2) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int lu = d2.leader(u), lv = d2.leader(v);
        l2.erase(lu), l2.erase(lv);
        d2.merge(lu, lv);
        l2.insert(d2.leader(lu));
    }
    if (l1.size() > l2.size()) {
        swap(l1, l2);
        swap(d1, d2);
    }
    vector<P> ans;
    auto unite = [&](int u, int v) -> bool {
        int lu1 = d1.leader(u), lv1 = d1.leader(v);
        int lu2 = d2.leader(u), lv2 = d2.leader(v);
        if (lu1 == lv1 || lu2 == lv2) return false;
        ans.emplace_back(u, v);
        l1.erase(lu1), l1.erase(lv1);
        l2.erase(lu2), l2.erase(lv2);
        d1.merge(lu1, lv1);
        d2.merge(lu2, lv2);
        l1.insert(d1.leader(lu1));
        l2.insert(d2.leader(lu2));
        return true;
    };
    while(l1.size() >= 2) {
        auto it1 = l1.begin();
        int u1 = *it1, v1 = *next(it1);
        auto it2 = l2.begin();
        int u2 = *it2, v2 = *next(it2);
        unite(u1, v1) || unite(u1, u2) || unite(v1, u2) || unite(u1, v2) || unite(v1, v2);
    }
    int sz = ans.size();
    cout << sz << '\n';
    for(auto [u, v]: ans) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
}
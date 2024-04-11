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
    int n;
    cin >> n;
    VI p(n);
    rep(i, n) cin >> p[i];
    dsu d(2 * n);
    rep(i, n - 1) {
        if (p[i] < p[i+1]) d.merge(i, i + 1);
        if (p[i] > p[i+1]) d.merge(n + i, n + i + 1);
    }
    vector<P> lns;
    rep(i, 2 * n) if (d.leader(i) == i) {
        lns.emplace_back(i, d.size(i));
    }
    sort(all(lns), [&](P x, P y) {return x.second > y.second;});
    int ans = 0;
    for(int i = 1; i < n - 1; ++i) if (p[i-1] < p[i] && p[i] > p[i+1]) {
        bool ok = true;
        int li1 = d.leader(i), li2 = d.leader(n + i);
        int sz1 = d.size(i), sz2 = d.size(n + i);
        if (sz1 > sz2) swap(sz1, sz2);
        // sz1 <= sz2
        int ln = sz2 / 2 * 2;
        if (sz1 <= ln) ok = false;
        int j = 0;
        //cout << ok << ' ' << li1 << ' ' << li2 << endl;
        while(j < lns.size() && (lns[j].first == li1 || lns[j].first == li2)) j++;
        if (j < lns.size() && lns[j].first != li1 && lns[j].first != li2) {
            if (sz2 <= lns[j].second) ok = false;
        }
        //if (ok) cout << i << endl;
        ans += ok;
    }
    cout << ans << endl;
}
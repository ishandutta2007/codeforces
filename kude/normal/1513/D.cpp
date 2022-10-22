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
    int tt;
    cin >> tt;
    while(tt--) {
        int n, p;
        cin >> n >> p;
        VI a(n);
        rep(i, n) cin >> a[i];
        VI ord(n);
        rep(i, n) ord[i] = i;
        sort(all(ord), [&](int i, int j) {return a[i] < a[j];});
        /*struct T {
            int type, i, cost;
            bool operator<(const T& x) const {return cost > x.cost;}
            T(int x, int y, int z): type(x), i(y), cost(z) {}
        };
        priority_queue<T> q;*/
        VI visited(n);
        dsu d(n);
        ll ans = 0;
        for(int i: ord) {
            if (a[i] > p) break;
            if (visited[i]) continue;
            visited[i] = true;
            rrep(j, i) {
                if (a[j] % a[i] != 0) break;
                if (!d.same(i, j)) {
                    d.merge(i, j);
                    ans += a[i];
                }
                if (visited[j]) break;
                visited[j] = true;
            }
            for(int j = i + 1; j < n; j++) {
                if (a[j] % a[i] != 0) break;
                if (!d.same(i, j)) {
                    d.merge(i, j);
                    ans += a[i];
                }
                if (visited[j]) break;
                visited[j] = true;
            }
        }
        rep(i, n - 1) if (!d.same(i, i + 1)) {
            ans += p;
            d.merge(i, i + 1);
        }
        cout << ans << '\n';
    }
}
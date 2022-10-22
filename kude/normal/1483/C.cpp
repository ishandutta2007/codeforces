#include<bits/stdc++.h>
using namespace std;
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

template<class T>
std::pair<std::vector<int>, std::vector<int>> min_heap_cartesian_tree(const std::vector<T>& a) {
    const unsigned int n = a.size();
    std::pair<std::vector<int>, std::vector<int>> res;
    auto& l = res.first;
    auto& r = res.second;
    l.resize(n, -1);
    r.resize(n, -1);
    std::stack<int> s;
    for(unsigned int i = 0; i < n; i++) {
        int last_popped = -1;
        while(!s.empty() && a[s.top()] >= a[i]) {
            last_popped = s.top(); s.pop();
        }
        if (!s.empty()) {
            r[s.top()] = i;
        }
        s.push(i);
        if (last_popped != -1) {
            l[i] = last_popped;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    VI h(n), b(n);
    rep(i, n) cin >> h[i];
    rep(i, n) cin >> b[i];
    auto [c1, c2] = min_heap_cartesian_tree(h);
    int r0 = min_element(all(h)) - h.begin();
    auto dfs = [&](auto&& self, int u, int l, int r) -> ll {
        if (u == -1) return 0;
        //if (r - l == 1) {
        //    if (l != 0 || r != n) return max(0, b[u]);
        //    else return b[u];
        //}
        int v1 = c1[u], v2 = c2[u];
        ll res1 = self(self, v1, l, u), res2 = self(self, v2, u + 1, r);
        ll ret = res1 + res2 + b[u];
        if (l != 0) {
            chmax(ret, res2);
        }
        if (r != n) {
            chmax(ret, res1);
        }
        return ret;
    };
    cout << dfs(dfs, r0, 0, n) << '\n';
}
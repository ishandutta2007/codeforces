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
std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> max_heap_cartesian_tree(const std::vector<T>& a) {
    const unsigned int n = a.size();
    std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> res;
    auto& p = std::get<0>(res);
    auto& l = std::get<1>(res);
    auto& r = std::get<2>(res);
    p.resize(n, -1);
    l.resize(n, -1);
    r.resize(n, -1);
    std::stack<int> s;
    for(unsigned int i = 0; i < n; i++) {
        int last_popped = -1;
        while(!s.empty() && a[s.top()] <= a[i]) {
            last_popped = s.top(); s.pop();
        }
        if (!s.empty()) {
            r[s.top()] = i;
            p[i] = s.top();
        }
        s.push(i);
        if (last_popped != -1) {
            l[i] = last_popped;
            p[last_popped] = i;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VI a(n);
        rep(i, n) cin >> a[i];
        auto [p, l, r] = max_heap_cartesian_tree(a);
        VI ans(n, -1);
        auto dfs = [&](auto&& self, int i, int depth) -> void {
            ans[i] = depth;
            if (l[i] != -1) self(self, l[i], depth + 1);
            if (r[i] != -1) self(self, r[i], depth + 1);
        };
        int cnt = 0;
        rep(i, n) if (p[i] == -1) {
            cnt++;
            dfs(dfs, i, 0);
        }
        assert(cnt == 1);
        rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    }
}
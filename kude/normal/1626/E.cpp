#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
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

template<class S, class E>
struct Rerooting {
    const vector<vector<E>>& g;
    const int n;
    const int root;
    vector<vector<S>> dp, sl, sr;

    Rerooting(const vector<vector<E>>& g, int root=0): g(g), n(g.size()), root(root), dp(n), sl(n), sr(n) {
        dfs1(root);
        dfs2(root);
    }

    S dfs1(int u, int p=-1) {
        const int sz = g[u].size();
        dp[u].resize(sz);
        sl[u].resize(sz + 1);
        sr[u].resize(sz + 1);

        S res;
        for(int i = 0; i < sz; i++) {
            const E& e = g[u][i];
            int v = dest(e);
            if (v == p) continue;
            dp[u][i] = dfs1(v, u).apply(e);
            res = res.merge(dp[u][i]);
        }
        return res;
    }

    void dfs2(int u, int p=-1) {
        const int sz = g[u].size();

        {
            S s{};
            for(int i = 0; i < sz; i++) {
                s = s.merge(dp[u][i]);
                sl[u][i + 1] = s;
            }
        }
        {
            S s{};
            for(int i = sz - 1; i >= 0; i--) {
                s = dp[u][i].merge(s);
                sr[u][i] = s;
            }
        }

        for(int i = 0; i < sz; i++) {
            int v = dest(g[u][i]);
            if (v == p) continue;
            const int sz_v = g[v].size();
            for(int j = 0; j < sz_v; j++) {
                const E& e = g[v][j];
                int w = dest(e);
                if (w != u) continue;
                dp[v][j] = sl[u][i].merge(sr[u][i + 1]).apply(e);
                break;
            }
            dfs2(v, u);
        }
    }

    S get_acc(int v) { return sr[v][0]; }
    S get_res(int v, E e) { return sr[v][0].apply(e); }

    private:
    int dest(const E& e) {
        if constexpr (is_same<E, int>::value) return e;
        else return e.to;
    };
};

vector<char> c;
struct S {
    int cnt = 0;
    bool ok = false;
    S apply(int e) const {
        return S{cnt + c[e], c[e] || (cnt >= 2 && ok)};
    }
    S merge(const S& rhs) const {
      return S{cnt + rhs.cnt, ok || rhs.ok};
    }
};


} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  c.resize(n);
  rep(i, n) {
    int x;
    cin >> x;
    c[i] = x;
  }
  VVI to(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    to[u].emplace_back(v);
    to[v].emplace_back(u);
  }
  Rerooting<S, int> rt(to);
  rep(i, n) {
    int ans = rt.get_acc(i).ok || c[i];
    cout << ans << " \n"[i + 1 == n];
  }
}
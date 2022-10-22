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

int ans[610];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<P>> to(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        to[a].emplace_back(b, c);
    }
    rep(i, n) {
        sort(all(to[i]));
        int sz = to[i].size();
        vector<bool> unnecessary(sz);
        auto [bi, ci] = to[i][0];
        for(int j = 1; j < sz; j++) {
            auto [bj, cj] = to[i][j];
            if (bj - bi + ci <= cj) {
                unnecessary[j] = true;
            } else {
                bi = bj, ci = cj;
            }
        }
        for(int j = 0; j < sz; j++) if (!unnecessary[j]) {
            auto [bj, cj] = to[i][j];
            if (bi == bj) break;
            if ((bj - bi + n) % n + ci <= cj) {
                unnecessary[j] = true;
            } else {
                bi = bj, ci = cj;
            }
        }
        vector<P> nto;
        rep(j, sz) if (!unnecessary[j]) nto.push_back(to[i][j]);
        to[i] = move(nto);
    }
    constexpr int INF = 1001001001;
    rep(s, n) {
        rep(i, n) ans[i] = INF;
        ans[s] = 0;
        int mn = INF;
        for(auto [b, c]: to[s]) chmin(mn, c);
        // ans ranges between [mn, mn + n)
        vector<vector<int>> evs(n); // events at mn + i
        {
            int sz = to[s].size();
            for(int i = 0; i < sz; i++) {
                auto [bi, ci] = to[s][i];
                auto [bj, cj] = to[s][(i + 1) % sz];
                bool first = true;
                for(int b = bi; first || b != bj; b = (b + 1) % n) {
                    first = false;
                    int dest = b % n;
                    int cost = ci + (b - bi + n) % n;
                    if (cost < ans[dest]) {
                        ans[dest] = cost;
                        if (cost - mn < n) evs[cost - mn].push_back(dest);
                    }
                }
            }
        }
        rep(tt, n) {
            const int time = tt + mn;
            for(int u: evs[tt]) {
                if (ans[u] != time) continue;
                // currently pointing at b + time
                int sz = to[u].size();
                for(int i = 0; i < sz; i++) {
                    auto [bi, ci] = to[u][i];
                    auto [bj, cj] = to[u][(i + 1) % sz];
                    bool first = true;
                    for(int b = bi; first || b != bj; b = (b + 1) % n) {
                        first = false;
                        int dest = (b + time) % n;
                        int cost = time + ci + (b - bi + n) % n;
                        if (cost < ans[dest]) {
                            ans[dest] = cost;
                            if (cost - mn < n) evs[cost - mn].push_back(dest);
                        }
                    }
                }
            }
        }
        rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    }
}
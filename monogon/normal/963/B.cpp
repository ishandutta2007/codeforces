
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    rep(i, 1, n + 1) {
        int p;
        cin >> p;
        if(p != 0) {
            g[p].push_back(i);
            g[i].push_back(p);
        }
    }
    vector<array<bool, 2>> dp(n + 1);
    auto dfs = [&](auto dfs, int x, int p) -> void {
        int cnt[2][2] = {{0, 0}, {0, 0}};
        int deg = 1;
        for(int y : g[x]) {
            if(y != p) {
                dfs(dfs, y, x);
                cnt[dp[y][0]][dp[y][1]]++;
                deg++;
            }
        }
        dp[x][0] = dp[x][1] = false;
        rep(amt, 0, deg) {
            if(cnt[0][1] + cnt[1][1] >= amt && cnt[1][0] + cnt[1][1] >= deg - 1 - amt && cnt[0][0] == 0) {
                dp[x][(deg % 2) ^ ((deg - 1 - amt) % 2)] = true;
            }
        }
    };
    dfs(dfs, 1, -1);
    // rep(x, 1, n + 1) {
    //     cout << x << ": " << dp[x][0] << ' ' << dp[x][1] << '\n';
    // }
    if(dp[1][1]) {
        cout << "YES\n";
        auto solve = [&](auto solve, int x, int p, bool flag) -> void {
            array<array<vi, 2>, 2> cnt{};
            int deg = 1;
            for(int y : g[x]) {
                if(y != p) {
                    cnt[dp[y][0]][dp[y][1]].push_back(y);
                    deg++;
                }
            }
            rep(amt, 0, deg) {
                if(((deg % 2) ^ ((deg - 1 - amt) % 2)) == flag && 
                        sz(cnt[0][1]) + sz(cnt[1][1]) >= amt && sz(cnt[1][0]) + sz(cnt[1][1]) >= deg - 1 - amt && cnt[0][0].empty()) {
                    vi A;
                    vi B;
                    A.insert(A.end(), all(cnt[0][1]));
                    B.insert(B.end(), all(cnt[1][0]));
                    while(sz(A) < amt) {
                        assert(!cnt[1][1].empty());
                        int y = cnt[1][1].back();
                        cnt[1][1].pop_back();
                        A.push_back(y);
                    }
                    B.insert(B.end(), all(cnt[1][1]));
                    for(int y : B) {
                        solve(solve, y, x, 0);
                    }
                    cout << x << '\n';
                    for(int y : A) {
                        solve(solve, y, x, 1);
                    }
                    return;
                }
            }
            assert(false);
        };
        solve(solve, 1, -1, 1);
    }else {
        cout << "NO\n";
    }
}
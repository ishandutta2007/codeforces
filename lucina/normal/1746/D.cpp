#include<bits/stdc++.h>
using namespace std;
const int nax = 4e5 + 10;
int n;
int64_t k;
int64_t s[nax];
int p[nax];
vector <int> g[nax];
map <pair <int, int64_t>, int64_t> memo;

int64_t dfs(int v, int64_t k) {
    int c = g[v].size();
    if (c == 0) return s[v] * k;
    if (memo.count(make_pair(v, k))) return memo[make_pair(v, k)];
    int64_t nk = k / c;
    int64_t lft = k % c; /// => should be allow to add, ?

    vector <int64_t> x;
    int64_t res = s[v] * k;

    for (int to : g[v]) {
        int64_t v = dfs(to, nk + (lft != 0)), u = dfs(to, nk);
        res += u;
        x.emplace_back( v - u);
    }

    sort(x.rbegin(), x.rend());
    assert(lft <= x.size());
    for (int j = 0 ; j < lft ; ++ j)
        res += x[j];
    return memo[make_pair(v, k)] = res;
}

void solve() {
    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++ i)
        g[i].clear();
    for (int i = 2 ; i <= n ; ++ i) {
        cin >> p[i];
        g[p[i]].push_back(i);
    }
    for (int i = 1 ; i <= n ; ++ i)
        cin >> s[i];
    memo.clear();
    cout << dfs(1, k) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    Global round, GL

*/
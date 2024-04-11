#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    const int MOD = 1e9+7;
    int tot = 1;
    vector<int> ans;
    vector<int> par(M); iota(par.begin(), par.end(), 0);
    vector<bool> good(M);
    auto get_par = [&](int v) {
        while (v != par[v]) {
            v = par[v] = par[par[v]];
        }
        return v;
    };
    auto merge = [&](int v, int u) {
        v = get_par(v);
        u = get_par(u);
        if (v != u) {
            par[u] = v;
            if (good[u]) good[v] = true;
            return true;
        } else return false;
    };
    for (int i = 0; i < N; ++i) {
        int sz; cin >> sz;
        vector<int> A(sz);
        for (int &a : A) cin >> a, --a;
        if (sz == 1) {
            int a = A[0];
            if (!good[get_par(a)]) {
                good[get_par(a)] = true;
                tot += tot;
                if (tot >= MOD) tot -= MOD;
                ans.emplace_back(i);
            }
        } else {
            int a = A[0], b = A[1];
            if ((!good[get_par(a)] || !good[get_par(b)]) && merge(a, b)) {
                tot += tot;
                if (tot >= MOD) tot -= MOD;
                ans.emplace_back(i);
            }
        }
    }
    cout << tot << ' ' << int(ans.size()) << '\n';
    for (int i : ans) cout << i+1 << ' '; cout << '\n';
}
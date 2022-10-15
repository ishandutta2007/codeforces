#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct dsu {
    vector<int> parent, size;

    dsu(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }

    int get(int x) { return parent[x] == x ? x : parent[x] = get(parent[x]); }

    void unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return;
        if (size[x] > size[y]) swap(x, y);
        parent[x] = y;
        size[y] += size[x];
    }
};

vector<int> knapsack(const vector<int> &count) {
    // we have `count[coin]` coins of cost `coin`;
    // now we create some super-coins, so that all possible sums are still reachable with the same number of coins
    // super-coin is a union of `count` coins with the same cost
    // we record in `counts[sum]` all possible numbers of coins to create one super-coin of cost `sum`
    vector<vector<int>> counts(count.size());
    for (int i = 1; i < count.size(); ++i) {
        int cur = count[i], j = i;
        for (; cur >= 3; j *= 2) {
            int carry = (cur - 1) / 2;
            for (int x = 0; x < cur - 2 * carry; ++x) {
                counts[j].push_back(j / i);
            }
            cur = carry;
        }
        for (int x = 0; x < cur; ++x) {
            counts[j].push_back(j / i);
        }
    }
    vector<int> knapsack(count.size(), 1e9); // `knapsack[sum]` is minimum number of coins to achieve `sum`
    knapsack[0] = 0;
    for (int i = 1; i < counts.size(); ++i) {
        for (int number: counts[i]) {
            for (int j = (int) knapsack.size() - 1 - i; j >= 0; --j) {
                knapsack[j + i] = min(knapsack[j + i], knapsack[j] + number);
            }
        }
    }
    return knapsack;
}

bool happy(int x) {
    auto str = to_string(x);
    return all_of(str.begin(), str.end(), [](char c) { return c == '4' || c == '7'; });
}

void solve() {
    int n, m;
    cin >> n >> m;
    dsu dsu(n);
    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        dsu.unite(--u, --v);
    }
    vector<int> count(n + 1);
    for (int i = 0; i < n; ++i) {
        if (dsu.get(i) == i) count[dsu.size[i]]++;
    }
    vector<int> coins_count = knapsack(count);
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        if (happy(i)) ans = min(ans, coins_count[i]);
    }
    cout << (ans == 1e9 ? -1 : ans - 1) << '\n';
}
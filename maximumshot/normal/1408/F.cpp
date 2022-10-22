#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    vector<pii> res;

    std::function<void(int, int)> rec = [&](int l, int r) {
        if (l == r)
            return;
        int m = (l + r) / 2;
        rec(l, m);
        rec(m + 1, r);
        int len = m - l + 1;
        for (int i = 0; i < len; i++)
            res.emplace_back(l + i, m + 1 + i);
    };

    vector<vector<int>> blocks;
    int l = 1;

    for (int bit = 0; (1 << bit) <= n; bit++) {
        if (n & (1 << bit)) {
            rec(l, l + (1 << bit) - 1);
            vector<int> block;
            for (int j = l; j < l + (1 << bit); j++)
                block.push_back(j);
            blocks.push_back(block);
            l += (1 << bit);
        }
    }

    for (int it = 0; it + 2 < (int) blocks.size(); it++) {
        while (blocks[it].size() < blocks[it + 1].size()) {
            int need = (int) blocks[it].size();
            for (int jit = 0; jit < need; jit++) {
                int x = blocks.back().back();
                blocks.back().pop_back();
                res.emplace_back(blocks[it][jit], x);
                blocks[it].push_back(x);
            }
        }
        for (int jit = 0; jit < (int) blocks[it].size(); jit++) {
            res.emplace_back(blocks[it][jit], blocks[it + 1][jit]);
            blocks[it + 1].push_back(blocks[it][jit]);
        }
    }

    cout << (int) res.size() << "\n";
    for (auto [i, j] : res) {
        cout << i << " " << j << "\n";
    }

    return 0;
}
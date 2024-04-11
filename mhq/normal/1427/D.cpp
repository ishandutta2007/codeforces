#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    vector<pair<int,int>> blocks;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        blocks.emplace_back(x, 1);
    }
    vector<vector<int>>all;
    while (true) {
        bool fnd = false;
        vector<pair<int,int>> nblocks;
        for (int i = 0; i < blocks.size(); i++) {
            if (fnd) break;
            for (int j = i + 1; j < blocks.size(); j++) {
                if (fnd) break;
                if (blocks[i].first == blocks[j].first + blocks[j].second) {
                    fnd = true;
                    vector<int> sz;
                    for (int p = 0; p <= i; p++) {
                        sz.emplace_back(blocks[p].second);
                    }
                    int tot = 0;
                    for (int p = i + 1; p <= j; p++) {
                        tot += blocks[p].second;
                    }
                    sz.emplace_back(tot);
                    for (int p = j + 1; p < blocks.size(); p++) {
                        sz.emplace_back(blocks[p].second);
                    }
                    all.emplace_back(sz);
                    for (int t = (int)blocks.size() - 1; t >= j + 1; t--) nblocks.emplace_back(blocks[t]);
                    for (int t = i + 1; t <= j - 1; t++) nblocks.emplace_back(blocks[t]);
                    nblocks.emplace_back(blocks[j].first, blocks[j].second + blocks[i].second);
                    for (int t = i - 1; t >= 0; t--) nblocks.emplace_back(blocks[t]);
                    assert(nblocks.size() == blocks.size() - 1);
                    break;
                }
            }
        }
        if (!fnd) break;
        blocks = nblocks;
    }
    cout << all.size() << '\n';
    for (auto& it : all) {
        cout << it.size() << " ";
        for (int v : it) cout << v << " ";
        cout << '\n';
    }
    return 0;
}
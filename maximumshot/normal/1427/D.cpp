#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<vector<int>> blocks(n), nblocks;
    for (int i = 0; i < n; i++)
        blocks[i] = {c[i]};

    vector<vector<int>> res;

    while (1) {
        nblocks.clear();
        for (int i = 0; i < (int) blocks.size(); i++) {
            if (!nblocks.empty() && nblocks.back().back() + 1 == blocks[i].front()) {
                for (auto x : blocks[i])
                    nblocks.back().push_back(x);
            } else {
                nblocks.push_back(blocks[i]);
            }
        }
        blocks = nblocks;
        if ((int) blocks.size() == 1)
            break;
        int ok = 0;
        for (int i = 0; i < (int) blocks.size() && !ok; i++) {
            for (int j = i + 1; j < (int) blocks.size() && !ok; j++) {
                if (blocks[j].back() + 1 == blocks[i].front()) {
                    ok = 1;
                    int L = 0, R = 0, M = 0;
                    for (int q = 0; q < (int) blocks.size(); q++) {
                        if (q == i || q == j)
                            continue;
                        if (q < i)
                            L += blocks[q].size();
                        else if (q > j)
                            R += blocks[q].size();
                        else
                            M += blocks[q].size();
                    }
                    res.push_back({L, (int) blocks[i].size(), M + (int) blocks[j].size(), R});
                    nblocks.clear();
                    for (int q = j + 1; q < (int) blocks.size(); q++)
                        nblocks.push_back(blocks[q]);
                    for (int q = i + 1; q <= j; q++)
                        nblocks.push_back(blocks[q]);
                    for (auto x : blocks[i])
                        nblocks.back().push_back(x);
                    for (int q = 0; q < i; q++)
                        nblocks.push_back(blocks[q]);
                    blocks = nblocks;
                }
            }
        }
    }

    cout << (int) res.size() << "\n";
    for (auto row : res) {
        vector<int> hlp;
        for (auto x : row)
            if (x)
                hlp.push_back(x);
        cout << (int) hlp.size() << " ";
        for (auto x : hlp)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
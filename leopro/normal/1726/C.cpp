#ifdef LOCAL
  #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }
#define answerExit(answer) { cout << (answer) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct DSU {
    int n;
    vector<int> parent, size, value;

    int get(int i) { return parent[i] == i ? i : parent[i] = get(parent[i]); }

    DSU(int n) : value(n), parent(n, 1), size(n, 1) { iota(parent.begin(), parent.end(), 0); }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    DSU dsu(2 * n);
    vector<int> pair;
    for (int i = 0; i < 2 * n; ++i) {
        if (s[i] == '(') {
            pair.push_back(i);
        } else {
            int x = pair.back();
            pair.pop_back();
            dsu.unite(i, x);
            if (x && s[x - 1] == ')') dsu.unite(x, x - 1);
        }
    }
    set<int> o;
    for (int i = 0; i < 2 * n; ++i) o.insert(dsu.get(i));
    cout << o.size() << '\n';
}
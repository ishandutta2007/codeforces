#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "/home/lesha/codes/Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, l, r) for (int i = int(l); i < int(r); i++)

struct aho_korasik {
    struct node {
        int nxt[26];
        int link = -1;
        int supper_link = -1;

        int parent = 0;
        char ch = 0;
        bool term = false;

        node() {
            forn (i, 0, 26) nxt[i] = -1;
        }
    };

    int root = 0;
    vector<node> aho{node()};

    inline void reserve(int len) {
        aho.reserve(len);
    }

    inline int new_node() {
        aho.push_back(node());
        return len(aho) - 1;
    }

    inline int add_string(const string &s) {
        int v = root;
        for (auto ch : s) {
            int c = ch - 'a';
            if (aho[v].nxt[c] == -1) {
                int nv = new_node();
                aho[v].nxt[c] = nv;
                aho[nv].parent = v;
                aho[nv].ch = ch;
            }
            v = aho[v].nxt[c];
        }
        aho[v].term = true;
        return v;
    }

    int supper_link(int v) {
        if (aho[v].supper_link != -1) return aho[v].supper_link;
        if (!aho[v].parent) return aho[v].supper_link = 0;
        if (aho[link(v)].term) return aho[v].supper_link = aho[v].link;
        return aho[v].supper_link = supper_link(aho[v].link);
    }

    int link(int v) {
        if (aho[v].link != -1) return aho[v].link;
        if (!aho[v].parent) return aho[v].link = 0;
        return aho[v].link = go(link(aho[v].parent), aho[v].ch);
    }

    int go(int v, char ch) {
        int c = ch - 'a';
        if (aho[v].nxt[c] != -1) return aho[v].nxt[c];
        if (!v) return aho[v].nxt[c] = 0;
        return aho[v].nxt[c] = go(link(v), ch);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    aho_korasik aho;
    vector<int> ends(n);
    forn (i, 0, n) {
        string s;
        cin >> s;
        ends[i] = aho.add_string(s);
    }
    dbg(ends);

    int aho_size = len(aho.aho);
    vector<multiset<int>> values(aho_size);
    forn (i, 0, n) values[ends[i]].insert(0);

    vector<int> cur_val(n);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int index, x;
            cin >> index >> x;
            index--;

            values[ends[index]].erase(values[ends[index]].find(cur_val[index]));
            cur_val[index] = x;
            values[ends[index]].insert(x);
        } else if (type == 2) {
            string s;
            cin >> s;

            int v = aho.root;
            int best = INT_MIN;
            for (auto ch : s) {
                v = aho.go(v, ch);

                for (int u = v; u; u = aho.supper_link(u)) {
                    if (len(values[u])) best = max(best, *values[u].rbegin());
                }
            }

            if (best == INT_MIN) best = -1;
            cout << best << '\n';
        } else assert(false);
    }
}
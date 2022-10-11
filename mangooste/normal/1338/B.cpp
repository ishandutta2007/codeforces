#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

struct min_ans {
    int cnt_odd, cnt_even;
    bool bad;

    min_ans(int cnt_odd = 0, int cnt_even = 0, bool bad = false) :
        cnt_odd(cnt_odd), cnt_even(cnt_even), bad(bad)
    {}
};

struct max_ans {
    int cnt;
    bool is_leave;

    max_ans(int cnt = 0, bool is_leave = false) :
        cnt(cnt), is_leave(is_leave)
    {}
};

int n, root;
vector<vector<int>> G;

min_ans dfs_min(int v, int pr) {
    if (G[v].size() == 1)
        return min_ans(0, 1, false);
    vector<min_ans> anses;
    bool cur_bad = false;
    int cur_even = 0, cur_odd = 0;
    for (auto u : G[v]) {
        if (u == pr)
            continue;
        min_ans cur = dfs_min(u, v);
        swap(cur.cnt_odd, cur.cnt_even);
        cur_bad |= cur.bad;
        cur_even += cur.cnt_even;
        cur_odd += cur.cnt_odd;
        anses.push_back(cur);
    }
    for (auto i : anses)
        if (i.cnt_odd != 0)
            cur_bad |= (cur_even - i.cnt_even != 0);
    return min_ans(cur_odd, cur_even, cur_bad);
}

int get_min() {
    return (dfs_min(root, root).bad ? 3 : 1);
}

max_ans dfs_max(int v, int pr) {
    if (G[v].size() == 1)
        return max_ans(0, true);
    int cur_cnt = 0, cnt_leaves = 0;
    for (auto u : G[v]) {
        if (u == pr)
            continue;
        max_ans cur = dfs_max(u, v);
        cur_cnt += cur.cnt;
        cnt_leaves += cur.is_leave;
    }
    cur_cnt += max(0, cnt_leaves - 1);
    return max_ans(cur_cnt, false);
}

ll get_max() {
    return n - 1 - dfs_max(root, root).cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    G.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    while (G[root].size() == 1)
        root++;
    // cerr << "root = " << root << '\n';
    cout << get_min() << ' ' << get_max() << '\n';
}
#pragma comment(linker, "/STACK:512000000")
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
    string s = FILENAME;
//    assert(!s.empty());
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    precalc();
    cout.precision(10);
    cout << fixed;
//    cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    auto end = clock();

    usleep(10000);
    print_stats(end - start);
    usleep(10000);
#endif

    return 0;
}

void precalc() {
}

template<typename T>
inline T nxt() {
    T cur;
    cin >> cur;
    return cur;
}

//#define int li
//const int mod = 1000000007;

struct Edge {
    int a, b, cost;
};

struct SegTree {
    int shift;
    vector<int> tree;
    SegTree(int n) {
        shift = 1;
        while (shift < n) {
            shift *= 2;
        }
        tree.assign(2 * shift, 0);
    }
    void update(int v, int val) {
        v += shift;
        tree[v] = max(tree[v], val);
        v /= 2;
        while (v) {
            tree[v] = max(tree[2 * v], tree[2 * v + 1]);
            v /= 2;
        }
    }
    int get_res(int l, int r) {
        l += shift;
        r += shift;
        int res = 0;
        while (l < r) {
            if (l & 1) {
                res = max(res, tree[l++]);
                continue;
            }
            if (r & 1) {
                res = max(res, tree[--r]);
                continue;
            }
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

void solve(__attribute__((unused)) bool read) {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    vector<vector<int>> xs(n);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
        --edges[i].a;
        --edges[i].b;
        for (int t = 0; t < 2; ++t) {
            int v = (t == 0) ? edges[i].a : edges[i].b;
            xs[v].push_back(edges[i].cost);
        }
    }
    vector<SegTree> trees;
    for (int i = 0; i < n; ++i) {
        sort(all(xs[i]));
        xs[i].erase(unique(all(xs[i])), xs[i].end());
        trees.emplace_back(xs[i].size());
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
        int a = edges[i].a, b = edges[i].b, cost = edges[i].cost;
        int a_id = lower_bound(all(xs[a]), cost) - xs[a].begin();
        int new_dp = trees[a].get_res(0, a_id) + 1;
        res = max(res, new_dp);
        int b_id = lower_bound(all(xs[b]), cost) - xs[b].begin();
        trees[b].update(b_id, new_dp);
    }
    cout << res << "\n";

}
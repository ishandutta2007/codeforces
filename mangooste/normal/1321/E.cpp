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

namespace Debug {
    // #define DEBUG

    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()

struct monster {
    int x, y, cost;

    monster(int x = 0, int y = 0, int cost = 0) :
        x(x), y(y), cost(cost)
    {}
};

const int INF = 2e9;
int n, m, p;
vector<pair<int, int>> a, b;
vector<monster> mons;
int ans = -INF;
vector<int> tree, mod;

inline void push(int v) {
    tree[v] += mod[v];
    mod[2 * v] += mod[v];
    mod[2 * v + 1] += mod[v];
    mod[v] = 0;
}

void upd(int v, int vl, int vr, int L, int R, int del) {
    if (R <= vl || vr <= L)
        return;
    if (L <= vl && vr <= R) {
        mod[v] += del;
        return;
    }
    push(v);
    int vm = (vl + vr) / 2;
    upd(2 * v, vl, vm, L, R, del);
    upd(2 * v + 1, vm, vr, L, R, del);
    tree[v] = max(tree[2 * v] + mod[2 * v], tree[2 * v + 1] + mod[2 * v + 1]);
}

int get(int v, int vl, int vr, int L, int R) {
    if (R <= vl || vr <= L)
        return -INF;
    if (L <= vl && vr <= R)
        return tree[v] + mod[v];
    push(v);
    int vm = (vl + vr) / 2;
    return max(get(2 * v, vl, vm, L, R), get(2 * v + 1, vm, vr, L, R));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> p;
    a.resize(n);
    for (auto &i : a)
        cin >> i.first >> i.second;
    b.resize(m);
    for (auto &i : b)
        cin >> i.first >> i.second;
    mons.resize(p);
    for (auto &i : mons)
        cin >> i.x >> i.y >> i.cost;
    sort(all(a));
    sort(all(b));
    sort(all(mons), [](monster &a, monster &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    debug(a);
    debug(b);
    tree.resize(4 * m);
    mod.resize(4 * m);
    for (int i = 0; i < m; i++)
        upd(1, 0, m, i, i + 1, -b[i].second);
    int mon_pos = 0;
    for (int i = 0; i < n; i++) {
        while (mon_pos < p && mons[mon_pos].x < a[i].first) {
            int j = lower_bound(all(b), make_pair(mons[mon_pos].y, INF)) - b.begin();
            debug("upd", j, mons[mon_pos].x, mons[mon_pos].y, mons[mon_pos].cost);
            upd(1, 0, m, j, m, mons[mon_pos].cost);
            mon_pos++;
        }
        int cur_ans = -a[i].second;
        cur_ans += get(1, 0, m, 0, m);
        ans = max(ans, cur_ans);
    }
    cout << ans << '\n';
}
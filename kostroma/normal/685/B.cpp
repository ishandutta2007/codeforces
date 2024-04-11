#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <deque>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve();
        ++testNumber;
        //++timer;
    }

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

void precalc() {


}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

//#define int li

//const int mod = 1000000007;

//#define double ld

const int shift = 1 << 19;

struct Node {
    int mn;
    int pos_mn;
};

Node tree[2 * shift + 5];

Node merge(const Node& l, const Node& r) {
    Node res = l;
    if (res.mn > r.mn) {
        res = r;
    }
    return res;
}

void update(int v, int val, int id) {
    v += shift;
    tree[v] = {val, id};
    v /= 2;
    while (v) {
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
        v /= 2;
    }
}

Node rmq(int l, int r) {
    if (l >= r) {
        return {(int)2e9, -1};
    }
    if (l & 1) {
        return merge(tree[l], rmq(l + 1, r));
    }
    if (r & 1) {
        return merge(tree[r - 1], rmq(l, r - 1));
    }
    return rmq(l / 2, r / 2);
}

vector<vector<int>> g;

vector<int> tin, tout;

vector<int> depth, cnt, max_cnt;

int TIM = 0;

void dfs(int v, int d) {
    cnt[v] = 1;
    depth[v] = d;
    tin[v] = TIM++;
    for (int to : g[v]) {
        dfs(to, d + 1);
        cnt[v] += cnt[to];
        max_cnt[v] = max(max_cnt[v], cnt[to]);
    }
    tout[v] = TIM;
}

void solve() {
    int n;
    cin >> n;
    int Q;
    cin >> Q;
    g.resize(n);
    tin.resize(n);
    tout.resize(n);
    depth.resize(n);
    cnt.resize(n);
    max_cnt.resize(n);
    for (int i = 1; i < n; ++i) {
        int cur;
        cin >> cur;
        --cur;
        g[cur].push_back(i);
    }
    dfs(0, 0);

    vector<vector<pair<int, int>>> q(n + 1);
    for (int i = 0; i < Q; ++i) {
        int v;
        cin >> v;
        --v;
        q[cnt[v]].push_back({v, i});
    }
    vector<vector<int>> adds(n + 1);
    for (int i = 0; i < n; ++i) {
        if (max_cnt[i] * 2 <= n) {
            adds[max_cnt[i] * 2].push_back(i);
        }
    }

    for (int i = 0; i < 2 * shift; ++i) {
        tree[i] = {(int)2e9, -1};
    }
    vector<int> res(Q);
    for (int sz = 0; sz <= n; ++sz) {
        for (int v : adds[sz]) {
            update(tin[v], n - cnt[v], v);
            //cout << "add " << v << ' ' << tin[v] << ' ' << depth[v] << "\n";
        }
        for (auto qu : q[sz]) {
            Node cur_node = rmq(tin[qu.first] + shift, tout[qu.first] + shift);
            res[qu.second] = cur_node.pos_mn;
            //cout << qu.first << ' ' << tin[qu.first] << ' ' << tout[qu.first] << ' ' << ' ' << cur_node.mn << ' ' << cur_node.pos_mn << "\n";
        }
    }

    for (int i = 0; i < Q; ++i) {
        cout << res[i] + 1 << "\n";
    }

}
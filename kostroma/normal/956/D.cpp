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

#define int li
//const int mod = 1000000007;

struct Fraction {
    int p, q;
    Fraction(int p, int q) : p(p), q(q) {}
    bool operator < (const Fraction& ot) const {
        return p * ot.q < ot.p * q;
    }
    bool operator == (const Fraction& ot) const {
        return p * ot.q == ot.p * q;
    }
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
    void update(int v) {
        v += shift;
        ++tree[v];
        v /= 2;
        while (v) {
            tree[v] = tree[2 * v] + tree[2 * v + 1];
            v /= 2;
        }
    }
    int get_res(int l, int r) {
        l += shift;
        r += shift;
        int res = 0;
        while (l < r) {
            if (l & 1) {
                res += tree[l];
                ++l;
                continue;
            }
            if (r & 1) {
                --r;
                res += tree[r];
                continue;
            }
            l /= 2;
            r /= 2;
        }
        return res;
    }

};

void solve(__attribute__((unused)) bool read) {
    int n, W;
    cin >> n >> W;
    vector<vector<Fraction>> vec;
    vector<Fraction> coords[2];
    for (int i = 0; i < n; ++i) {
        int x, v;
        cin >> x >> v;
        bool swapped = false;
        if (x < 0) {
            x = -x;
            v = -v;
            swapped = true;
        }
        assert(v < 0);
        v = -v;
        if (swapped) {
            vec.push_back({Fraction(x, v + W), Fraction(x, v - W)});
        } else {
            vec.push_back({Fraction(x, v - W), Fraction(x, v + W)});
        }
        for (int j = 0; j < 2; ++j) {
            coords[j].push_back(vec[i][j]);
            //cout << vec[i][j].p << " " << vec[i][j].q << endl;
        }
    }
    for (int i = 0; i < 2; ++i) {
        sort(all(coords[i]));
        coords[i].erase(unique(all(coords[i])), coords[i].end());
        //cout << coords[i].size() << endl;
    }
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            a[i][j] = lower_bound(all(coords[j]), vec[i][j]) - coords[j].begin();
            //cout << a[i][j] << " \n"[j == 1];
        }
    }
    int tree_size = (int)coords[1].size();
    SegTree tree(tree_size);
    sort(all(a));
    li res = 0;
    for (int i = 0; i < a.size(); ) {
        int j = i;
        while (j < a.size() && a[j][0] == a[i][0]) {
            res += tree.get_res(a[j][1], a[j][1] + 1);
            tree.update(a[j][1]);
            ++j;
        }
        for (int r = i; r < j; ++r) {
            int cur_add = tree.get_res(a[r][1] + 1, tree_size);
            res += cur_add;
        }
        i = j;
    }
    cout << res << "\n";

}
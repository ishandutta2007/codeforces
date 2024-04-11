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
    #define DEBUG

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

struct segment {
    int L, R, num;

    segment(int L = 0, int R = 0, int num = 0) :
        L(L), R(R), num(num)
    {}
};

const int INF = 2e9;
int n, m;
vector<int> a;
#define left asdfasdwqeuqrwpeoiupqwoeirfsadkjfhasdlfkajsdfhla
#define right asdfasgdfhasgkhgaskdhfasdjkfasgdjkfgaskdjfgaskj
vector<segment> left, right, start;
vector<int> mn_left, mn_right;
vector<int> tree, mod;

void build(int v, int vl, int vr) {
    if (vr - vl == 1) {
        tree[v] = a[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    build(2 * v, vl, vm);
    build(2 * v + 1, vm, vr);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

inline void push(int v) {
    tree[v] += mod[v];
    mod[2 * v] += mod[v];
    mod[2 * v + 1] += mod[v];
    mod[v] = 0;
}

inline int get_value(int v) {
    return tree[v] + mod[v];
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
    tree[v] = min(get_value(2 * v), get_value(2 * v + 1));
}

int get(int v, int vl, int vr, int L, int R) {
    if (R <= vl || vr <= L)
        return INF;
    if (L <= vl && vr <= R)
        return tree[v] + mod[v];
    push(v);
    int vm = (vl + vr) / 2;
    return min(get(2 * v, vl, vm, L, R), get(2 * v + 1, vm, vr, L, R));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    a.resize(n);
    for (int &el : a)
        cin >> el;
    for (int i = 0; i < m; i++) {
        int L, R;
        cin >> L >> R, L--, R--;
        start.push_back(segment(L, R, i));
        left.push_back(segment(L, R, i));
        right.push_back(segment(L, R, i));
    }
    if (m == 0)
        return cout << (*max_element(all(a)) - *min_element(all(a))) << "\n0\n", 0;
    sort(all(left), [](segment &a, segment &b) {
        return a.R < b.R;
    });
    sort(all(right), [](segment &a, segment &b) {
        return a.L < b.L;
    });
    mn_left.resize(m);
    tree.resize(4 * n);
    mod.resize(4 * n);
    build(1, 0, n);
    for (int i = 0; i < m; i++) {
        upd(1, 0, n, left[i].L, left[i].R + 1, -1);
        mn_left[i] = get(1, 0, n, 0, left[i].R + 1);
    }
    fill(all(mod), 0);
    build(1, 0, n);
    mn_right.resize(m);
    for (int i = m - 1; i >= 0; i--) {
        upd(1, 0, n, right[i].L, right[i].R + 1, -1);
        mn_right[i] = get(1, 0, n, right[i].L, n);
    }
    auto get_right = [&](int pos) {
        int L = -1, R = m;
        while (R - L > 1) {
            int mid = (L + R) / 2;
            if (right[mid].L > pos)
                R = mid;
            else
                L = mid;
        }
        if (R == m)
            return INF;
        return mn_right[R];
    };
    auto get_left = [&](int pos) {
        int L = -1, R = m;
        while (R - L > 1) {
            int mid = (L + R) / 2;
            if (left[mid].R < pos)
                L = mid;
            else
                R = mid;
        }
        if (L == -1)
            return INF;
        return mn_left[L];
    };
    int pos = 0;
    int ans = a[0] - min({get_left(pos), get_right(pos), a[0]});
    for (int i = 1; i < n; i++) {
        int cur_ans = a[i] - min({get_left(i), get_right(i), a[i]});
        if (cur_ans > ans) {
            ans = cur_ans;
            pos = i;
        }
    }
    if (ans < (*max_element(all(a)) - *min_element(all(a))))
        return cout << (*max_element(all(a)) - *min_element(all(a))) << "\n0\n", 0;
    vector<int> segs;
    for (auto i : start)
        if (i.R < pos || pos < i.L)
            segs.push_back(i.num);
    cout << ans << '\n' << segs.size() << '\n';
    for (auto i : segs)
        cout << i + 1 << ' ';
    cout << '\n';
}
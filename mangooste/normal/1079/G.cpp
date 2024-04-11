#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()


template<typename T, typename unite_t, T neutral>
struct SegmentTree {
    unite_t unite;
    int n;
    vector<T> tree;

    inline void build() {
        for (int i = n - 1; i; i--)
            tree[i] = unite(tree[i << 1], tree[(i << 1) ^ 1]);
    }

    SegmentTree() {}
    SegmentTree(vector<T> a) : n(int(a.size())), tree(n << 1, neutral) {
        tree.shrink_to_fit();
        for (int i = 0; i < n; i++)
            tree[i + n] = a[i];
        build();
    }
    SegmentTree(int n, T val = neutral) : n(n), tree(n << 1, val) {
        tree.shrink_to_fit();
        build();
    }

    inline void rebuild(int pos) {
        for (pos >>= 1; pos; pos >>= 1)
            tree[pos] = unite(tree[pos << 1], tree[(pos << 1) ^ 1]);
    }

    inline void change(int pos, T val, const function<void(T &value, T x)> relax) {
        pos += n;
        relax(tree[pos], val);
        rebuild(pos);
    }

    inline void set(int pos, T val) {
        pos += n;
        tree[pos] = val;
        rebuild(pos);
    }

    inline void add(int pos, T val) {
        pos += n;
        tree[pos] += val;
        rebuild(pos);
    }

    inline void setmax(int pos, T val) {
        pos += n;
        if (tree[pos] < val) {
            tree[pos] = val;
            rebuild(pos);
        }
    }

    inline void setmin(int pos, T val) {
        pos += n;
        if (tree[pos] > val) {
            tree[pos] = val;
            rebuild(pos);
        }
    }

    inline T get(int l, int r) const {
        if (l < 0)
            l = 0;
        if (r > n)
            r = n;
        T left_res = neutral, right_res = neutral;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                left_res = unite(left_res, tree[l++]);
            if (r & 1)
                right_res = unite(tree[--r], right_res);
        }
        return unite(left_res, right_res);
    }
};


template<typename T>
struct SegmentTreeSumComparator {
    inline T operator () (const T &a, const T& b) const {
        return a + b;
    }
};

template<typename T>
struct SegmentTreeMinComparator {
    inline T operator () (const T &a, const T &b) const {
        return a < b ? a : b;
    }
};

template<typename T>
struct SegmentTreeMaxComparator {
    inline T operator () (const T &a, const T &b) const {
        return a > b ? a : b;
    }
};


template<typename T>
using SegmentTreeSum = SegmentTree<T, SegmentTreeSumComparator<T>, T(0)>;

template<typename T>
using SegmentTreeMin = SegmentTree<T, SegmentTreeMinComparator<T>, numeric_limits<T>::max()>;

template<typename T>
using SegmentTreeMax = SegmentTree<T, SegmentTreeMaxComparator<T>, numeric_limits<T>::min()>;


const int lg = 22;

vec<int> operator + (vec<int> a, vec<int> b) {
    vec<int> res;
    for (auto x : a)
        res.push_back(x);
    for (auto x : b)
        res.push_back(x);
    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> a(n);
    for (auto &x : a)
        cin >> x;
    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    a = a + a + a;
    vec<vec<int>> left(lg, vec<int>(3 * n));
    vec<vec<int>> right(lg, vec<int>(3 * n));
    vec<SegmentTreeMin<int>> trees_left(lg, SegmentTreeMin<int>(3 * n));
    vec<SegmentTreeMax<int>> trees_right(lg, SegmentTreeMax<int>(3 * n));

    for (int i = 0; i < 3 * n; i++) {
        left[0][i] = max(-1, i - a[i]);
        right[0][i] = min(3 * n, i + a[i]);
        trees_left[0].set(i, left[0][i]);
        trees_right[0].set(i, right[0][i]);
    }

    for (int j = 1; j < lg; j++)
        for (int i = 0; i < 3 * n; i++) {
            int l = left[j - 1][i];
            int r = right[j - 1][i];
            left[j][i] = trees_left[j - 1].get(l, r + 1);
            right[j][i] = trees_right[j - 1].get(l, r + 1);
            trees_left[j].set(i, left[j][i]);
            trees_right[j].set(i, right[j][i]);
        }

    for (int i = 0; i < n; i++) {
        int a = n + i, b = n + i;
        int ans = 0;
        int cnt_left = n - 1;
        for (int j = lg - 1; j >= 0; j--) {
            int aa = trees_left[j].get(a, b + 1);
            int bb = trees_right[j].get(a, b + 1);
            int dista = a - aa;
            int distb = bb - b;
            if (dista + distb < cnt_left) {
                cnt_left -= dista + distb;
                a = aa;
                b = bb;
                ans += (1 << j);
            }
        }
        cout << ans + 1 << ' ';
    }
    cout << '\n';
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

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


void solve_test() {
    string s;
    cin >> s;
    int n = len(s);

    vec<int> count(26);
    for (auto c : s)
        count[c - 'A']++;

    vec<char> who;
    for (int i = 0; i < 26; i++)
        if (count[i])
            who.push_back('A' + i);

    ll best = -1;
    string answer;

    do {
        vec<vec<int>> positions(26);
        for (int i = 0; i < 26; i++)
            positions[i].reserve(count[i]);

        SegmentTreeSum<int> tree(n, 1);

        ll local = 0;

        int pos = 0;
        for (auto c : who)
            for (int i = 0; i < count[c - 'A']; i++)
                positions[c - 'A'].push_back(pos++);

        for (int i = n - 1; i >= 0; i--) {
            int current = s[i] - 'A';
            assert(len(positions[current]));

            int pos = positions[current].back();
            positions[current].pop_back();

            int where = tree.get(0, pos);
            tree.set(pos, 0);

            assert(i >= where);
            local += i - where;
        }

        if (local > best) {
            best = local;
            answer.clear();
            for (auto c : who)
                for (int i = 0; i < count[c - 'A']; i++)
                    answer.push_back(c);
        }
    } while (next_permutation(all(who)));

    dbg(best);
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve_test();
}
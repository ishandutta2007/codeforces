#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using int128 = __int128;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

mt19937 __rng__(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
struct MySet {
    struct Node {
        T x;
        int left, right;
        int sz;
        int y;

        int128 sum_down, sum_up, sum;

        Node(T x) : x(x), left(-1), right(-1), sz(1), y(__rng__()),
            sum_down(x), sum_up(x), sum(x)
        {}
    };

    int root;
    vector<Node> nds;

    MySet() : root(-1) {}

    inline void relax(int v) {
        nds[v].sz = 1 + size(nds[v].left) + size(nds[v].right);
        nds[v].sum = nds[v].x + sum(nds[v].left) + sum(nds[v].right);
        nds[v].sum_up = sum_up(nds[v].left) + (size(nds[v].left) + 1) * (nds[v].x + sum(nds[v].right)) + sum_up(nds[v].right);
        nds[v].sum_down = sum_down(nds[v].right) + (size(nds[v].right) + 1) * (nds[v].x + sum(nds[v].left)) + sum_down(nds[v].left);
    }

    inline int128 sum(int v) {
        if (v == -1)
            return 0;
        return nds[v].sum;
    }

    inline int128 sum_up(int v) {
        if (v == -1)
            return 0;
        return nds[v].sum_up;
    }

    inline int128 sum_down(int v) {
        if (v == -1)
            return 0;
        return nds[v].sum_down;
    }

    inline int size(int v) {
        if (v == -1) return 0;
        return nds[v].sz;
    }

    inline int newNode(T x) {
        int id = int(nds.size());
        nds.push_back(Node(x));
        return id;
    }

    pair<int, int> splitX(int v, T x) {
        if (v == -1) return {v, v};
        if (nds[v].x <= x) {
            pair<int, int> cur = splitX(nds[v].right, x);
            nds[v].right = cur.first;
            relax(v);
            return {v, cur.second};
        } else {
            pair<int, int> cur = splitX(nds[v].left, x);
            nds[v].left = cur.second;
            relax(v);
            return {cur.first, v};
        }
    }

    pair<int, int> splitN(int v, int n) {
        if (v == -1) return {v, v};
        if (size(nds[v].left) + 1 <= n) {
            pair<int, int> cur = splitN(nds[v].right, n - size(nds[v].left) - 1);
            nds[v].right = cur.first;
            relax(v);
            return {v, cur.second};
        } else {
            pair<int, int> cur = splitN(nds[v].left, n);
            nds[v].left = cur.second;
            relax(v);
            return {cur.first, v};
        }
    }

    int merge(int left, int right) {
        if (left == -1) return right;
        if (right == -1) return left;

        if (nds[left].y > nds[right].y) {
            nds[left].right = merge(nds[left].right, right);
            relax(left);
            return left;
        } else {
            nds[right].left = merge(left, nds[right].left);
            relax(right);
            return right;
        }
    }

    int insert(int v, T x, int nv) {
        if (v == -1) return nv;
        if (nds[nv].y < nds[v].y) {
            if (x < nds[v].x) {
                nds[v].left = insert(nds[v].left, x, nv);
            } else {
                nds[v].right = insert(nds[v].right, x, nv);
            }
            relax(v);
            return v;
        } else {
            auto [left, right] = splitX(v, x);
            nds[nv].left = left;
            nds[nv].right = right;
            relax(nv);
            return nv;
        }
    }

    inline void insert(T x) {
        int v = newNode(x);
        root = insert(root, x, v);
    }

    int erase(int v, T x) {
        if (v == -1) return -1;
        if (nds[v].x == x) return merge(nds[v].left, nds[v].right);
        if (x < nds[v].x) {
            nds[v].left = erase(nds[v].left, x);
        } else {
            nds[v].right = erase(nds[v].right, x);
        }
        relax(v);
        return v;
    }

    inline void erase(T x) {
        root = erase(root, x);
    }

    inline int size() {
        return size(root);
    }

    int128 get_sum_left(int v, int cnt) {
        if (v == -1 || !cnt)
            return 0;
        if (size(nds[v].left) >= cnt)
            return get_sum_left(nds[v].left, cnt);
        return sum(nds[v].left) + nds[v].x + get_sum_left(nds[v].right, cnt - size(nds[v].left) - 1);
    }

    int128 get_sum_right(int v, int cnt) {
        if (v == -1 || !cnt)
            return 0;
        if (size(nds[v].right) >= cnt)
            return get_sum_right(nds[v].right, cnt);
        return sum(nds[v].right) + nds[v].x + get_sum_right(nds[v].left, cnt - size(nds[v].right) - 1);
    }

    inline int128 get_sum(int l, int r) {
        if (l == 0)
            return get_sum_left(root, r);
        if (r == size(root))
            return get_sum_right(root, r - l);
        auto [left, right] = splitN(root, l);
        int128 res = get_sum_left(right, r - l);
        root = merge(left, right);
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);


    int n, q;
    cin >> n >> q;
    vec<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(all(a));

    MySet<ll> st;
    st.nds.reserve(4.5e5);
    for (int i = 0; i < n; i++)
        st.insert(a[i]);

    auto solve = [&]() {
        int n = st.size();
        if (n <= 1) {
            cout << "0\n";
            return;
        }

        int128 res = st.sum_up(st.root) - st.sum(st.root);
        int half = (n + 1) / 2;
        {
            int l = 0, r = half;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (st.get_sum(0, mid + 1) >= st.get_sum(n - mid, n))
                    l = mid;
                else
                    r = mid;
            }
            {
                auto [left, right] = st.splitN(st.root, l + 1);
                res -= st.sum_down(left);
                st.root = st.merge(left, right);
            }
            if (l != half - 1) {
                int ls = n - half + 1;
                int rs = n - l - 1;
                auto [left, midright] = st.splitN(st.root, ls);
                auto [mid, right] = st.splitN(midright, rs - ls + 1);
                res -= st.sum_up(mid) + st.size(mid) * st.sum(right);
                st.root = st.merge(left, st.merge(mid, right));
            }
        }
        if (half + 1 < n) {
            int l = half - 1, r = n - 1;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (st.get_sum(0, mid + 1) >= st.get_sum(n - mid, n))
                    r = mid;
                else
                    l = mid;
            }
            if (l != half - 1) {
                int ls = n - l;
                int rs = n - half;
                auto [left, midright] = st.splitN(st.root, ls);
                auto [mid, right] = st.splitN(midright, rs - ls + 1);
                res -= st.sum_up(mid) + st.sum(right) * st.size(mid);
                st.root = st.merge(left, st.merge(mid, right));
            }
            if (r != n - 1) {
                int ls = r;
                int rs = n - 2;
                auto [left, midright] = st.splitN(st.root, ls);
                auto [mid, right] = st.splitN(midright, rs - ls + 1);
                res -= st.sum_down(mid) + st.sum(left) * st.size(mid);
                st.root = st.merge(left, st.merge(mid, right));
            }
        }
        cout << ll(res) << '\n';
    };

    solve();
    while (q--) {
        char t;
        ll x;
        cin >> t >> x;
        if (t == '1')
            st.insert(x);
        else
            st.erase(x);
        solve();
    }
}
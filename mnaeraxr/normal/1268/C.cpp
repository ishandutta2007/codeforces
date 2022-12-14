/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author marX
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>
#include <vector>

template<typename sum_type>
sum_type add(sum_type &a, sum_type &b) {
    return a + b;
}

template<typename any>
void pass(any &a, any &b, any &c) {}

template<
        typename node_type,
        typename update_type,
        void (*_update)(node_type &, update_type &),
        node_type (*merge)(node_type &, node_type &) = add<node_type>,
        void (*push_lazy)(node_type &, node_type &, node_type &) = pass<node_type>
>
class SegmentTree {
    std::vector<node_type> st;
    int n;

    void build(int p, int b, int e, std::function<node_type(int)> &data_fn) {
        if (b + 1 == e) {
            st[p] = data_fn(b);
        } else {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            build(l, b, m, data_fn);
            build(r, m, e, data_fn);
            st[p] = merge(st[l], st[r]);
        }
    }

    node_type query(int p, int b, int e, int x, int y) {
        if (x <= b && e <= y) {
            return st[p];
        } else {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            push_lazy(st[p], st[l], st[r]);

            if (x < m) {
                auto ans = query(l, b, m, x, y);

                if (m < y) {
                    auto nxt = query(r, m, e, x, y);
                    ans = merge(ans, nxt);
                }

                return ans;
            } else {
                return query(r, m, e, x, y);
            }
        }
    }

    void update(int p, int b, int e, int x, int y, update_type &value) {
        if (x <= b && e <= y) {
            _update(st[p], value);
        } else {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            push_lazy(st[p], st[l], st[r]);
            if (x < m) update(l, b, m, x, y, value);
            if (m < y) update(r, m, e, x, y, value);
            st[p] = merge(st[l], st[r]);
        }
    }

public:
    SegmentTree(int n) : n(n) {
        st.resize(4 * n);
    }

    static SegmentTree from(int n, std::function<node_type(int)> data_fn) {
        SegmentTree st(n);
        st.build(1, 0, n, data_fn);
        return st;
    }

    static SegmentTree build_from(std::vector<node_type> &data) {
        return from(data.size(), [&](int ix) {
            return data[ix];
        });
    }

    node_type query(int pos) {
        return query(pos, pos + 1);
    }

    node_type query(int left, int right) {
        if (right <= left)
            return node_type();
        return query(1, 0, n, left, right);
    }

    void update(int left, int right, update_type value) {
        if (right <= left)
            return;
        update(1, 0, n, left, right, value);
    }

    void update(int pos, update_type value) {
        update(pos, pos + 1, value);
    }
};


using namespace std;

struct Node {
    int b, e;
    long long value, lazy;

    Node operator+(const Node &right) const {
        return {b, right.e, value + right.value, 0};
    }
};

void push_lazy(Node &u, Node &l, Node &r) {
    if (u.lazy) {
        l.value += u.lazy * (l.e - l.b);
        l.lazy += u.lazy;

        r.value += u.lazy * (r.e - r.b);
        r.lazy += u.lazy;

        u.lazy = 0;
    }
}

void update(Node &u, long long &value) {
    u.lazy += value;
    u.value += value * (u.e - u.b);
}

typedef SegmentTree<Node, long long, update, add, push_lazy> segment_tree;

class CKIntegers {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;

        vector<int> inv(n);
        auto le = segment_tree::from(n, [](int i) { return (Node) {i, i + 1, 0, 0}; });
        auto ri = segment_tree::from(n, [](int i) { return (Node) {i, i + 1, 0, 0}; });

        for (int i = 0; i < n; ++i) {
            int u;
            in >> u;
            u--;
            inv[u] = i;
        }

        long long inversions = 0;

        for (int i = 0; i < n; ++i) {
            int p = inv[i];
            inversions += ri.query(p).value;

            le.update(p + 1, n, +1);
            ri.update(0, p, +1);

            int tot = i + 1;
            int target = (tot + 1) / 2;

            int lo = 0, hi = n;

            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;

                if (le.query(mid).value >= target) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }

            // hi

            long long tle = target;
            long long tri = tot - tle;

            long long LE = le.query(0, hi).value - tle * (tle - 1) / 2;
            long long RI = ri.query(hi, n).value - tri * (tri - 1) / 2;

            out << inversions + LE + RI << " ";
        }
        out << endl;
    }
};


int main() {
    CKIntegers solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}
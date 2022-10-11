#include <bits/stdc++.h>

using namespace std;

struct Segment_tree {
    int n;
    vector<int> sum, mod;

    Segment_tree(int n) : n(n), sum(4 * n), mod(4 * n, -1) {}

    inline void push(int v, int vl, int vr) {
        if (mod[v] == -1)
            return;
        sum[v] = mod[v] * (vr - vl);
        if (vr - vl > 1)
            mod[2 * v] = mod[2 * v + 1] = mod[v];
        mod[v] = -1;
    }

    inline void apply(int left, int right, int value) {
        apply(1, 0, n, left, right, value);
    }

    void apply(int v, int vl, int vr, int left, int right, int value) {
        push(v, vl, vr);
        if (right <= vl || vr <= left)
            return;
        if (left <= vl && vr <= right)
            return mod[v] = value, void();

        int vm = (vl + vr) / 2;
        apply(2 * v, vl, vm, left, right, value);
        apply(2 * v + 1, vm, vr, left, right, value);

        push(2 * v, vl, vm), push(2 * v + 1, vm, vr);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    inline int get_sum(int left, int right) {
        return get_sum(1, 0, n, left, right);
    }

    int get_sum(int v, int vl, int vr, int left, int right) {
        push(v, vl, vr);
        if (right <= vl || vr <= left)
            return 0;
        if (left <= vl && vr <= right)
            return sum[v];

        int vm = (vl + vr) / 2;
        return get_sum(2 * v, vl, vm, left, right) + get_sum(2 * v + 1, vm, vr, left, right);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string from, to;
        cin >> from >> to;

        vector<int> left(q), right(q);
        for (int i = q - 1; i >= 0; i--)
            cin >> left[i] >> right[i], left[i]--;

        Segment_tree tree(n);
        for (int i = 0; i < n; i++)
            tree.apply(i, i + 1, to[i] - '0');

        [&]() {
            for (int i = 0; i < q; i++) {
                int sum = tree.get_sum(left[i], right[i]);
                if (sum * 2 == right[i] - left[i])
                    return cout << "NO\n", void();
                tree.apply(left[i], right[i], sum * 2 > right[i] - left[i]);
            }
            bool yes = true;
            for (int i = 0; i < n; i++)
                yes &= tree.get_sum(i, i + 1) == from[i] - '0';
            cout << (yes ? "YES" : "NO") << '\n';
        }();   
    }
}
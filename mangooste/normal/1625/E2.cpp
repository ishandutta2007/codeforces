#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename T>
struct binary_indexed_tree {
    std::vector<T> bit;

    binary_indexed_tree(int n = 0, T value = 0) : bit(n + 1) {
        for (int i = 1; i <= n; i++)
            bit[i] = value * (i & -i);
    }

    void add(int pos, T delta) {
        for (pos++; pos < int(bit.size()); pos += pos & -pos)
            bit[pos] += delta;
    }

    T query(int pref) {
        T sum = 0;
        for (pref++; pref > 0; pref -= pref & -pref)
            sum += bit[pref];

        return sum;
    }

    T query(int l, int r) {
        if (r >= int(bit.size()))
            r = int(bit.size()) - 1;

        if (l < 0)
            l = 0;

        if (r <= l)
            return 0;

        return query(r - 1) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    string s;
    cin >> n >> q >> s;

    const int V = 2 * n;
    vector<int> parent(V, -1), childs(V), id(V), tin(V), vertex(n, -1);
    int cur = 0;

    for (int i = 0, j = 0; i < n; i = j) {
        int balance = 0;
        while (j < n && balance >= 0) {
            balance += s[j] == '(' ? 1 : -1;
            j++;
        }

        if (j == i + 1)
            continue;

        int v = cur++;
        for (; i < j; i++)
            if (s[i] == '(') {
                int u = cur++;
                parent[u] = v;
                id[u] = childs[v]++;
                tin[u] = i;
                v = u;
                vertex[i] = v;
            } else {
                vertex[i] = v;
                v = parent[v];
            }
    }

    vector<binary_indexed_tree<int>> bits(cur);
    for (int i = 0; i < cur; i++)
        bits[i] = binary_indexed_tree<int>(childs[i], 1);

    auto get = [&](int x) {
        return 1ll * x * (x + 1) / 2;
    };

    binary_indexed_tree<ll> bit(n);
    for (int i = 0; i < n; i++)
        if (s[i] == '(')
            bit.add(i, get(childs[vertex[i]]));

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        l--, r--;

        if (type == 2) {
            cout << bit.query(r) - bit.query(l - 1) + get(bits[parent[vertex[l]]].query(id[vertex[l]], id[vertex[r]] + 1)) << '\n';
        } else if (type == 1) {
            int v = parent[vertex[l]];
            bits[v].add(id[vertex[l]], -1);
            bit.add(tin[v], -get(childs[v]));
            childs[v]--;
            bit.add(tin[v], get(childs[v]));
        } else {
            throw;
        }
    }
}
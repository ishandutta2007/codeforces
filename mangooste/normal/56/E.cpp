#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

struct person {
    int x, h, id;

    person() {}

    friend istream& operator >> (istream &in, person &p) {
        return in >> p.x >> p.h;
    }

    bool operator < (person p) {
        assert(x != p.x);
        return x < p.x;
    }
};

struct segtree {
    int n;
    vec<int> tree;

    segtree(int n) : n(n), tree(2 * n) {}

    inline void update(int pos, int val) {
        pos += n;
        tree[pos] = val;
        for (pos /= 2; pos; pos /= 2)
            tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
    }

    inline int get(int l, int r) {
        int mx = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2)
                mx = max(mx, tree[l++]);
            if (r % 2)
                mx = max(mx, tree[--r]);
        }
        return mx;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<person> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i].id = i;
    }
    sort(all(a));
    segtree tree(n);
    vec<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        int l = 0, r = n - i;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[i + mid].x < a[i].x + a[i].h)
                l = mid;
            else
                r = mid;
        }
        if (l == 0)
            tree.update(i, 1 + i);
        else
            tree.update(i, max(1 + i, tree.get(i, i + r)));
        ans[a[i].id] = tree.get(i, i + 1) - i;

    }
    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';
}
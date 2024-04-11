#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

template<typename T>
struct Fenwick {
    int n;
    vector<T> bit;

    Fenwick() : n(0) {}
    Fenwick(int n) : n(n), bit(n + 1) {}

    Fenwick(int n, T val) : n(n), bit(n + 1) {
        for (int i = 1; i <= n; i++)
            bit[i] = T(i & -i) * val;
    }

    Fenwick(vector<T> a) : n(int(a.size())), bit(n + 1) {
        vector<T> pr(n + 1, 0);
        for (int i = 0; i < n; i++)
            pr[i + 1] = pr[i] + a[i];
        for (int i = 1; i <= n; i++)
            bit[i] = pr[i] - pr[i - (i & -i)];
    }

    inline void add(int pos, T x) {                 // a[pos] += x
        for (pos++; pos <= n; pos += pos & -pos)
            bit[pos] += x;
    }

    inline T preffixSum(int pos) {                  // [0; pos)
        T sum = 0;
        for (; pos > 0; pos -= pos & -pos)
            sum += bit[pos];
        return sum;
    }

    inline T getSum(int l, int r) {                 // [l, r)
        return preffixSum(r) - preffixSum(l);
    }

    inline T at(int pos) {                          // a[pos]
        return preffixSum(pos + 1) - preffixSum(pos);
    }

    inline void set(int pos, T x) {                 //  a[pos] = x
        add(pos, x - at(pos));
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> sizes(n);
    vec<int> st(n);
    vec<pr<int>> a;
    for (int i = 0; i < n; i++) {
        if (i)
            st[i] += st[i - 1] + sizes[i - 1];
        cin >> sizes[i];
        int sz = sizes[i];
        vec<pr<int>> points(sz);
        for (auto &[x, y] : points)
            cin >> x >> y;

        // for (auto [x, y] : points)
        //     cerr << "(" << x << ", " << y << ") ";
        // cerr << endl;

        rotate(points.begin(), min_element(all(points)), points.end());
        for (int i = 0; i < sz; i++) {
            int j = (i + 1) % sz;
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;
            int g = gcd(abs(dx), abs(dy));
            a.emplace_back(dx / g, dy / g);
        }
    }

    vec<vec<pr<int>>> queries(len(a));
    int q;
    cin >> q;
    vec<int> ans(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        // cerr << st[r] + sizes[r] - 1 << ' ' << st[l] << endl;
        queries[st[r] + sizes[r] - 1].emplace_back(st[l], i);
    }

    // for (auto [x, y] : a)
    //     cerr << "(" << x << ", " << y << ") ";
    // cerr << endl;

    Fenwick<int> bit(len(a));
    map<pr<int>, int> mp;
    for (int i = 0; i < len(a); i++) {
        if (mp.find(a[i]) != mp.end())
            bit.add(mp[a[i]], -1);
        mp[a[i]] = i;
        bit.add(i, 1);
        for (auto [l, j] : queries[i])
            ans[j] = bit.getSum(l, i + 1);
        // cerr << "i = " << i << endl;
        // for (int i = 0; i < len(a); i++)
        //     cerr << bit.getSum(i, i + 1) << ' ';
        // cerr << endl;
    }
    for (auto x : ans)
        cout << x << '\n';
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
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

struct segtree {
    int n;
    vec<int> tree;

    segtree(int sz) {
        n = 1;
        while (n < sz)
            n <<= 1;
        tree.resize(n << 1);
    }

    inline void inc(int pos) {
        pos += n;
        tree[pos]++;
        for (pos >>= 1; pos; pos >>= 1)
            tree[pos] = tree[pos << 1] + tree[(pos << 1) | 1];
    }

    inline int get(int k) {
        int l = 0, r = n, v = 1;
        while (r - l > 1) {
            if (tree[v << 1] > k) {
                v <<= 1;
                r = (l + r) >> 1;
            } else {
                k -= tree[v << 1];
                v = (v << 1) | 1;
                l = (l + r) >> 1;
            }
        };
        return r;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vec<int> cnt(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x - 1]++;
    }
    vec<int> ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&](int a, int b) {
        return cnt[a] < cnt[b] || (cnt[a] == cnt[b] && a < b);
    });
    vec<ll> pref(m);
    for (int i = 1; i < m; i++)
        pref[i] = pref[i - 1] + 1ll * abs(cnt[ord[i]] - cnt[ord[i - 1]]) * i;

    vec<int> ans(q);
    vec<vec<pair<int, int>>> queries(m);
    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;
        k -= n;
        int where = lower_bound(all(pref), k) - pref.begin();
        queries[where - 1].emplace_back((k - pref[where - 1] - 1) % where, i);
    }

    segtree tree(m);
    for (int i = 0; i < m; i++) {
        tree.inc(ord[i]);
        for (auto [which, num] : queries[i])
            ans[num] = tree.get(which);
    }
    for (auto x : ans)
        cout << x << '\n';
}
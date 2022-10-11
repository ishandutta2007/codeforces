#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
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

inline int power(int a, int b, int m) {
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = ll(res) * a % m;
        a = ll(a) * a % m;
    }
    return res;
}

inline int get_cnt(vec<int> &a, int delta, int m) {
    map<int, int> cnt;
    for (auto x : a) {
        cnt[x]++;
    }
    assert(delta != 0);
    int res = 0;
    for (auto x : a) {
        res += cnt[(x + delta) % m];
    }
    return res;    
}

pair<int, int> solve(vec<int> &a, int m) {
    int n = len(a);
    assert(2 * n <= m);
    if (n == 0) return {0, 1};
    if (n == 1) return {a[0], 1};
    int delta = a[1] - a[0];
    int delta_i = n - get_cnt(a, delta, m);
    int step = ll(delta) * power(delta_i, m - 2, m) % m;
    set<int> st(1 + all(a));
    int cur;
    for (cur = (a[0] + step) % m;; cur = (cur + step) % m) {
        if (!st.count(cur)) break;
        st.erase(cur);
    }
    for (cur = (a[0] - step + m) % m;; cur = (cur - step + m) % m) {
        if (!st.count(cur)) break;
        st.erase(cur);
    }
    if (len(st)) return {-1, -1};
    cur = (cur + step) % m;
    return {cur, step};
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vec<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(all(a));
    if (2 * n <= m) {
        auto [start, step] = solve(a, m);
        if (start == -1) {
            cout << "-1\n";
        } else {
            cout << start << ' ' << step << '\n';
        }
        return 0;
    }
    set<int> st(all(a));
    vec<int> inv;
    for (int i = 0; i < m; i++) {
        if (!st.count(i)) inv.push_back(i);
    }
    auto [start, step] = solve(inv, m);
    if (start == -1) {
        cout << "-1\n";
        return 0;
    }
    cout << (start + ll(step) * len(inv)) % m << ' ' << step << '\n';
}
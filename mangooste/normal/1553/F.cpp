#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>
struct binary_indexed_tree {
    std::vector<T> bit;

    binary_indexed_tree(int n = 0, T value = T()) : bit(n + 1) {
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
            return T(0);

        return query(r - 1) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    const int A = 3e5 + 4;
    binary_indexed_tree<ll> bit_cnt(A);
    binary_indexed_tree<ll> bit_sum(A);
    binary_indexed_tree<ll> bit_relax_sum(A);
    binary_indexed_tree<ll> bit_relax_cnt(A);

    ll answer = 0;
    while (n--) {
        int x;
        cin >> x;
        answer += bit_relax_cnt.query(x) * x - bit_relax_sum.query(x);
        for (int l = 0; l < A; l += x)
            answer += bit_sum.query(l, l + x) - l * bit_cnt.query(l, l + x);

        cout << answer << ' ';

        for (int l = 0; l < A; l += x) {
            int r = min(l + x, A);
            bit_relax_sum.add(l, l);
            bit_relax_sum.add(r, -l);
            bit_relax_cnt.add(l, 1);
            bit_relax_cnt.add(r, -1);
        }
        bit_cnt.add(x, 1);
        bit_sum.add(x, x);
    }
    cout << '\n';
}
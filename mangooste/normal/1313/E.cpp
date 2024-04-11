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

template<typename T>
std::vector<int> z_function(const T &str) {
    int n = int(str.size());
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i < r)
            z[i] = std::min(r - i, z[i - l]);

        while (i + z[i] < n && str[z[i]] == str[i + z[i]])
            z[i]++;

        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    string a, b, s;
    cin >> n >> m >> ws;
    getline(cin, a);
    getline(cin, b);
    getline(cin, s);

    vector<int> lens_a(n);
    {
        auto z = z_function(s + char(0) + a);
        for (int i = len(s) + 1; i < len(z); i++)
            lens_a[i - len(s) - 1] = min(m - 1, z[i]);
    }

    vector<int> lens_b(n);
    {
        reverse(all(s));
        reverse(all(b));
        auto z = z_function(s + char(0) + b);

        for (int i = len(s) + 1; i < len(z); i++)
            lens_b[n - 1 - i + len(s) + 1] = min(m - 1, z[i]);
    }

    vector<vector<int>> events1(m);
    for (int i = 0; i < n; i++)
        if (lens_a[i] > 0)
            events1[lens_a[i] - 1].push_back(i);

    vector<vector<int>> events2(m);
    for (int i = 0; i < n; i++)
        if (lens_b[i] > 0)
            events2[m - lens_b[i]].push_back(i);

    binary_indexed_tree<ll> bit_sum(2 * n);
    binary_indexed_tree<int> bit_cnt(2 * n);
    int ptr = 0;

    ll answer = 0;
    for (int st = m - 1; st > 0; st--, ptr++) {
        for (auto position : events1[st - 1]) {
            int bit_position = ptr + position + st - 1;
            bit_cnt.add(bit_position, 1);
            bit_sum.add(bit_position, lens_a[position] + 1 - m);
        }

        for (auto position : events2[st]) {
            int from = position - (m - st) + 1, to = position + st;
            answer += bit_sum.query(ptr + from, ptr + to) + 1ll * bit_cnt.query(ptr + from, ptr + to) * lens_b[position];
        }
    }

    cout << answer << '\n';
}
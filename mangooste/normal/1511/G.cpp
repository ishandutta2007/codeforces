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

struct fenwick {
    int n;
    vector<int> bit;

    fenwick(int n) : n(n), bit(n + 1) {}

    inline void add(int pos, int value) {
        for (pos++; pos <= n; pos += pos & -pos)
            bit[pos] += value;
    }

    inline int get(int pos) const {
        int sum = 0;
        for (pos++; pos; pos -= pos & -pos)
            sum += bit[pos];

        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> count(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x - 1]++;
    }

    int q;
    cin >> q;
    vector<vector<int>> queries_l(m + 1);
    vector<vector<pair<int, int>>> queries_r(m + 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        queries_l[l].push_back(i);
        queries_r[r].emplace_back(l, i);
    }

    const int lg = __lg(m) + 1;
    vector<fenwick> bits(lg, fenwick(m));

    auto get_current_xor = [&](int pos) {
        int result = 0;
        for (int i = 0; i < lg; i++)
            result ^= (((bits[i].get(pos & ((2 << i) - 1))) & 1) << i);

        return result;
    };

    vector<int> answer(q);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < lg; j++) {
            int step = (2 << j);
            int last = (i + (step >> 1)) & (step - 1);
            int first = last - (step >> 1) + 1;
            bits[j].add(max(0, first), count[i]);
            bits[j].add(last + 1, -count[i]);

            if (first < 0) {
                bits[j].add(first + step, count[i]);
                bits[j].add(step, -count[i]);
            }
        }

        for (auto id : queries_l[i])
            answer[id] ^= get_current_xor(i);

        for (const auto &[l, id] : queries_r[i])
            answer[id] ^= get_current_xor(l);
    }

    dbg(answer);
    for (auto x : answer)
        cout << (x ? 'A' : 'B');

    cout << '\n';
}
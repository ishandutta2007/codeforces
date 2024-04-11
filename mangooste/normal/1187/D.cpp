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

    fenwick(int n) : n(n), bit(n + 1, -1) {}

    void update(int pos, int val) {
        for (pos++; pos <= n; pos += pos & -pos)
            bit[pos] = max(bit[pos], val);
    }

    int get(int pos) {
        int result = -1;
        for (pos++; pos; pos -= pos & -pos)
            result = max(result, bit[pos]);

        return result;
    }
};

void solve() {
    int n;
    cin >> n;

    map<int, int> count;

    auto read = [&](int p) {
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
            count[x] += p;
        }

        vector<int> ord(n);
        iota(all(ord), 0);
        stable_sort(all(ord), [&](int i, int j) {
            return a[i] < a[j];
        });

        for (int i = 0; i < n; i++)
            a[ord[i]] = i;

        return a;
    };

    auto a = read(1);
    auto b = read(-1);

    for (auto [_, x] : count)
        if (x) {
            cout << "NO\n";
            return;
        }

    vector<int> where(n);
    for (int i = 0; i < n; i++)
        where[b[i]] = i;

    fenwick bit(n);
    for (int i = 0; i < n; i++) {
        if (bit.get(a[i] - 1) > where[a[i]]) {
            cout << "NO\n";
            return;
        }
        bit.update(a[i], where[a[i]]);
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
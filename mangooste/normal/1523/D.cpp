#pragma GCC optimize("O3")

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



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p >> ws;
    vector<ll> a(n);
    vector<vector<int>> bits(n);
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        for (int j = 0; j < m; j++)
            if (s[j] == '1') {
                bits[i].push_back(j);
                a[i] |= (1ll << j);
            }
    }

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> order(n);
    iota(all(order), 0);
    shuffle(all(order), rng);

    ll best = 0;

    order.resize(10);
    for (auto who : order) {
        vector<int> id(m, -1);
        for (int i = 0; i < len(bits[who]); i++)
            id[bits[who][i]] = i;

        int sz = len(bits[who]);
        const int MASK = (1 << sz);

        vector<int> count(MASK);
        for (int i = 0; i < n; i++) {
            int current = 0;
            for (auto j : bits[i])
                if (id[j] != -1)
                    current |= (1 << id[j]);

            count[current]++;
        }

        for (int mask = 0; mask < MASK; mask++)
            for (int submask = (mask - 1) & mask; submask > 0; submask = (submask - 1) & mask)
                count[submask] += count[mask];

        for (int mask = MASK - 1; mask >= 0; mask--)
            if (count[mask] * 2 >= n) {
                ll current = 0;
                for (int i = 0; i < len(bits[who]); i++)
                    if ((mask >> i) & 1)
                        current |= (1ll << bits[who][i]);

                if (__builtin_popcountll(current) > __builtin_popcountll(best))
                    best = current;
            }
    }

    for (int i = 0; i < m; i++)
        cout << (best >> i) % 2;

    cout << '\n';
}
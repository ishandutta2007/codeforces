#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define hash __hash__

const int SZ = 2;
const int mod[]{ int(1e9) + 9, int(1e9) + 21 };
const int base[]{ 239, 241 };
vec<int> power[SZ];
int inv[SZ];

inline int mult(int a, int b, int i) {
    return 1ll * a * b % mod[i];
}

inline int add(int a, int b, int i) {
    a += b;
    if (a >= mod[i])
        a -= mod[i];

    return a;
}

inline int sub(int a, int b, int i) {
    a -= b;
    if (a < 0)
        a += mod[i];

    return a;
}

inline int my_power(int a, int b, int i) {
    int prod = 1;
    for (; b; b >>= 1) {
        if (b & 1)
            prod = mult(prod, a, i);

        a = mult(a, a, i);
    }

    return prod;
}

const int N = 1e5 + 4;

struct hash {
    ar<int, SZ> h;
    int size;

    hash() : size(0), h({0, 0}) {}

    hash(int _) {
        for (int i = 0; i < SZ; i++)
            h[i] = add(mult(base[i], '(', i), ')', i);

        size = 2;
    }

    inline hash operator+(const hash hh) const {
        hash res;
        res.size = size + hh.size;

        for (int i = 0; i < SZ; i++)
            res.h[i] = add(hh.h[i], mult(h[i], power[i][hh.size], i), i);

        return res;
    }

    inline void push_back(char c) {
        for (int i = 0; i < SZ; i++)
            h[i] = add(mult(h[i], base[i], i), c, i);

        size++;
    }

    inline void push_front(char c) {
        for (int i = 0; i < SZ; i++)
            h[i] = add(h[i], mult(power[i][size], c, i), i);

        size++;
    }

    inline void pop_front() {
        for (int i = 0; i < SZ; i++)
            h[i] = sub(h[i], mult('(', power[i][size - 1], i), i);

        size--;
    }

    inline void pop_back() {
        for (int i = 0; i < SZ; i++)
            h[i] = mult(sub(h[i], ')', i), inv[i], i);

        size--;
    }

    inline bool operator<(const hash hh) const {
        if (size != hh.size)
            return size < hh.size;

        return h < hh.h;
    }

    inline bool operator==(const hash hh) const {
        return size == hh.size && h == hh.h;
    }

    inline bool operator<=(const hash hh) const {
        return *this < hh || *this == hh;
    }

    friend ostream& operator<<(ostream &out, hash h) {
        return out << '(' << h.h << ", " << h.size << ')';
    }
};

int n;
vec<int> g[N];

vec<hash> pref[N];
hash dp[N];
hash without[N];

map<hash, int> mp;
pair<int, int> answer;

inline void insert(const hash &h) {
    mp[h]++;
}

inline void erase(const hash &h) {
    if (--mp[h] == 0)
        mp.erase(h);
}

void init(int v) {
    if (!len(g[v])) {
        dp[v] = hash(0);
        without[v] = hash();
        pref[v].push_back(hash());

        insert(dp[v]);
        return;
    }

    for (auto u : g[v]) {
        g[u].erase(find(all(g[u]), v));
        init(u);
    }

    sort(all(g[v]), [&](int v, int u) {
        return dp[v] < dp[u];
    });

    hash res;
    for (auto u : g[v])
        res = res + dp[u];

    without[v] = res;

    res.push_front('(');
    res.push_back(')');

    dp[v] = res;
    insert(dp[v]);

    pref[v].resize(len(g[v]) + 1, hash());
    for (int i = 0; i < len(g[v]); i++)
        pref[v][i + 1] = pref[v][i] + dp[g[v][i]];
}

inline int find_position(int v, const hash &h) {
    int l = -1, r = len(g[v]);
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (dp[g[v][mid]] < h)
            l = mid;
        else
            r = mid;
    }

    return r;
}

void solve(int v, hash up) {
    answer = max(answer, pair<int, int>{ len(mp), v });

    for (int i = 0; i < len(g[v]); i++) {
        int u = g[v][i];

        hash new_hash_v = dp[v];
        new_hash_v.pop_front();
        new_hash_v.pop_back();

        hash to_sub = pref[v][i];

        if (up.size != 0 && up <= dp[u]) {
            int pos = find_position(v, up);
            int between = pref[v][i].size - pref[v][pos].size;

            for (int i = 0; i < SZ; i++)
                to_sub.h[i] = add(to_sub.h[i], mult(power[i][between], up.h[i], i), i);

            for (int i = 0; i < SZ; i++)
                to_sub.h[i] = add(to_sub.h[i], mult(pref[v][pos].h[i], sub(power[i][between + up.size], power[i][between], i), i), i);
        }

        new_hash_v.size -= dp[u].size;

        int after = pref[v].back().size - pref[v][i + 1].size;
        if (up.size != 0 && dp[u] < up)
            after += up.size;

        for (int i = 0; i < SZ; i++)
            new_hash_v.h[i] = sub(new_hash_v.h[i], mult(to_sub.h[i], sub(power[i][after + dp[u].size], power[i][after], i), i), i);

        for (int i = 0; i < SZ; i++)
            new_hash_v.h[i] = sub(new_hash_v.h[i], mult(dp[u].h[i], power[i][after], i), i);

        new_hash_v.push_front('(');
        new_hash_v.push_back(')');

        hash new_hash_u = without[u];
        new_hash_u.size += new_hash_v.size;

        int r = find_position(u, new_hash_v);

        after = pref[u].back().size - pref[u][r].size;
        for (int i = 0; i < SZ; i++)
            new_hash_u.h[i] = add(new_hash_u.h[i], mult(pref[u][r].h[i], sub(power[i][new_hash_v.size + after], power[i][after], i), i), i);

        for (int i = 0; i < SZ; i++)
            new_hash_u.h[i] = add(new_hash_u.h[i], mult(power[i][after], new_hash_v.h[i], i), i);

        new_hash_u.push_front('(');
        new_hash_u.push_back(')');

        auto do_swap = [&]() {
            erase(dp[v]);
            erase(dp[u]);

            swap(dp[v], new_hash_v);
            swap(dp[u], new_hash_u);

            insert(dp[v]);
            insert(dp[u]);
        };

        do_swap();
        solve(u, dp[v]);
        do_swap();
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    for (int i = 0; i < SZ; i++) {
        power[i].resize(2 * N + 4, 1);
        for (int j = 1; j < len(power[i]); j++)
            power[i][j] = mult(power[i][j - 1], base[i], i);

        inv[i] = my_power(base[i], mod[i] - 2, i);
    }

    cin >> n;
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    init(0);
    answer = {len(mp), 0};
    solve(0, hash());

    cout << answer.second + 1 << '\n';
}
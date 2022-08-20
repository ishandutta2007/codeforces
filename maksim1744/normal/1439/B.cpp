/*
    author:  Maksim1744
    created: 17.11.2020 18:09:38
*/

#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

struct hash_my {
    size_t operator()(int x) const {
        x = ((x >> 16) ^ x) * 0x119de1f3;
        x = ((x >> 16) ^ x) * 0x119de1f3;
        x = (x >> 16) ^ x;
        return x;
    }

    size_t operator()(long long x) const {
        x = (x ^ (x >> 30)) * (0xbf58476d1ce4e5b9ll);
        x = (x ^ (x >> 27)) * (0x94d049bb133111ebll);
        x = x ^ (x >> 31);
        return x;
    }

    template<typename T, typename U>
    size_t operator()(const pair<T, U> &p) const {
        long long h1 = (*this)(p.first);
        long long h2 = (*this)(p.second);
        return (*this)(h1 ^ (h2 << 32) ^ (h2 >> 32));
    }
};

template<typename Key, typename Value, size_t N, typename Hash = hash_my>
struct static_hash_table {
    static_assert(__builtin_popcount(N) == 1, "N must be a power of 2");
    array<pair<Key, Value>, N> data;
    array<char, N> state;
    Hash hasher;

    const static char STATE_EMPTY = 0;
    const static char STATE_FILLED = 1;
    const static char STATE_REMOVED = 2;

    static_hash_table() {
        state.fill(STATE_EMPTY);
    }

    int find_ind(const Key &k) const {
        int ind = hasher(k) & (N - 1);
        while (state[ind] != STATE_EMPTY) {
            if (state[ind] == STATE_FILLED && data[ind].first == k) return ind;
            ind = (ind + 1) & (N - 1);
        }
        return -1;
    }

    void emplace(const Key &k, const Value &v) {
        (*this)[k] = v;
    }

    Value &operator[](const Key &k) {
        int ind = hasher(k) & (N - 1);
        int rem = -1;
        while (state[ind] != STATE_EMPTY) {
            if (state[ind] == STATE_FILLED && data[ind].first == k) {
                return data[ind].second;
            }
            if (rem == -1 && state[ind] == STATE_REMOVED) rem = ind;
            ind = (ind + 1) & (N - 1);
        }
        if (rem != -1) ind = rem;
        data[ind].first = k;
        data[ind].second = Value();
        state[ind] = STATE_FILLED;
        return data[ind].second;
    }

    void erase(const Key &k) {
        int ind = find_ind(k);
        if (ind != -1) {
            state[ind] = STATE_REMOVED;
        }
    }

    int count(const Key &k) const {
        return find_ind(k) != -1;
    }
};

static_hash_table<pair<int, int>, int, 1 << 20> e;

void test_case(int test) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
        // e.emplace(min(u, v), max(u, v));
    }
    if ((ll)(k - 1) * (k - 1) > m * 2 + 100) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (auto j : g[i]) {
            if (i < j) {
                e[{i, j}] = 1;
            }
        }
    }
    auto cl = [&]() {
        for (int i = 0; i < n; ++i) {
            for (auto j : g[i]) {
                if (i < j) {
                    e.erase({i, j});
                }
            }
        }
    };
    vector<bool> dead(n, false);
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        s.emplace(g[i].size(), i);
    }
    vector<int> deg(n);
    for (int i = 0; i < n; ++i) {
        deg[i] = g[i].size();
    }
    while (!s.empty()) {
        if (s.begin()->first >= k) {
            break;
        }
        auto [dg, v] = *s.begin();
        s.erase(s.begin());
        if (dg == k - 1) {
            vector<int> now;
            for (auto x : g[v]) {
                if (!dead[x]) {
                    now.pb(x);
                }
            }
            now.pb(v);
            // shows;
            // show(s);
            // show(dg, v);
            // show(now);
            // show(k);
            assert(now.size() == k);
            bool ok = true;
            for (auto x : now) {
                for (auto y : now) {
                    if (x >= y) continue;
                    if (!e.count({x, y})) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                cout << 2 << '\n';
                for (auto u : now) {
                    cout << u + 1 << ' ';
                }
                cout << '\n';
                cl();
                return;
            }
        }
        dead[v] = true;
        for (auto x : g[v]) {
            if (!dead[x]) {
                s.erase({deg[x], x});
                deg[x]--;
                s.insert({deg[x], x});
            }
        }
    }
    cl();
    if (s.empty()) {
        cout << -1 << '\n';
        return;
    }
    cout << 1 << ' ' << s.size() << '\n';
    for (auto [d, u] : s) {
        cout << u + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}
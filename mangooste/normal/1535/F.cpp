#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

constexpr int N = 2e5 + 228, SZ = 2;
int MOD[SZ], BASE[SZ], POWER[SZ][N];

struct my_hash {
    array<int, SZ> h;
    int length;

    my_hash() {
        h.fill(0);
        length = 0;
    }

    my_hash(char c) {
        h.fill(c);
        length = 1;
    }

    my_hash& operator+=(const my_hash &x) {
        for (int i = 0; i < SZ; i++) {
            h[i] = 1ll * h[i] * POWER[i][x.length] % MOD[i] + x.h[i];
            if (h[i] >= MOD[i]) h[i] -= MOD[i];
        }
        length += x.length;
        return *this;
    }

    bool operator<(const my_hash &x) const {
        return h != x.h ? h < x.h : length < x.length;
    }

    friend my_hash operator+(const my_hash &a, const my_hash &b) {
        return my_hash(a) += b;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < SZ; i++) {
        auto is_prime = [](int x) {
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) return false;
            }
            return true;
        };
 
        MOD[i] = rng() % int(3e8) + 7e8;
        while (!is_prime(MOD[i])) MOD[i]++;
        BASE[i] = rng() % MOD[i];
        if (!(BASE[i] & 1)) BASE[i]++;
 
        POWER[i][0] = 1;
        for (int j = 1; j < N; j++) {
            POWER[i][j] = 1ll * POWER[i][j - 1] * BASE[i] % MOD[i];
        }
    }

    int n;
    cin >> n;
    map<vector<int>, vector<string>> groups;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<int> cnt(26);
        for (auto &c : s) cnt[c - 'a']++;
        groups[cnt].push_back(s);
    }

    ll ans = 0, tot_pairs = 0;

    auto solve = [&](const vector<string> &a) {
        struct trie_node {
            trie_node* nxt[26];
            vector<my_hash> queries;
            int id;

            trie_node() {
                fill(all(nxt), nullptr);
                id = -1;
            }

            ~trie_node() {
                for (int i = 0; i < 26; i++) {
                    if (nxt[i]) delete nxt[i];
                }
            }
        };

        trie_node* root = new trie_node();
        vector<vector<my_hash>> hs(len(a));
        for (int i = 0; i < len(a); i++) {
            auto s = a[i];

            vector<trie_node*> vers;
            vers.reserve(len(s) + 1);
            vers.push_back(root);
            for (char c : s) {
                auto v = vers.back();
                if (!v->nxt[c - 'a']) {
                    v->nxt[c - 'a'] = new trie_node();
                }
                vers.push_back(v->nxt[c - 'a']);
            }
            assert(vers.back()->id == -1);
            vers.back()->id = i;

            hs[i].resize(len(s) + 1);
            for (int j = len(s) - 1; j >= 0; j--) {
                hs[i][j] = my_hash(s[j]) + hs[i][j + 1];
            }

            for (int i = 0, j = 0; i < len(s); i = j) {
                j++;
                while (j < len(s) && s[j] >= s[j - 1]) j++;
                vers[i]->queries.push_back(hs[vers.back()->id][j]);
            }
        }

        ll cur_pairs = 0;

        y_combinator([&](auto dfs, trie_node* v) -> map<my_hash, int> {
            map<my_hash, int> mp;
            for (int i = 0; i < 26; i++) {
                if (!v->nxt[i]) continue;
                auto cur = dfs(v->nxt[i]);
                if (len(mp) < len(cur)) swap(mp, cur);
                for (auto &[a, b] : cur) {
                    mp[a] += b;
                }
                map<my_hash, int>().swap(cur);
            }

            for (auto &x : v->queries) {
                auto it = mp.find(x);
                assert(it != mp.end());
                cur_pairs += it->second - 1;
            }

            if (v->id != -1) {
                for (auto x : hs[v->id]) {
                    mp[x]++;
                }
            }
            return mp;
        })(root);

        ll cur = 1ll * len(a) * (len(a) - 1) / 2;
        tot_pairs += cur;
        ans += cur_pairs;
        ans += 2 * (cur - cur_pairs);

        delete root;
    };

    for (auto &[_, a] : groups) {
        solve(a);
    }

    ans += (1ll * n * (n - 1) / 2 - tot_pairs) * 1337;
    cout << ans << '\n';
}
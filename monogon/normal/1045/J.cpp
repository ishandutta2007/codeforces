
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>
// #include <bits/extc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    uniform_int_distribution<int> u(l, r);
    return u(mt);
}

bool isprime(ll x) {
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

ll base, prime;

struct trash {
    int trash0;
    int trash1;
    trash() {
        trash0 = 0;
        trash1 = 0;
    }
    inline int& operator[](int i) {
        return i == 0 ? trash0 : trash1;
    }
    bool operator==(const trash &o) const {
        return trash0 == o.trash0 && trash1 == o.trash1;
    }
};

struct ugh {
    int num = 0;
    vector<ll> base, prime;
    ugh(int n) : num(n), base(n), prime(n) {
        rep(i, 0, n) {
            base[i] = rand(1e8, 9e8);
            do {
                prime[i] = rand(9e8 + 1, 1e9 - 1);
            }while(!isprime(prime[i]));
        }
    }
    void addchar(trash &h, char c) {
        rep(i, 0, num) {
            h[i] = (h[i] * 1ll * base[i] + c - 'a' + 1) % prime[i];
        }
    }
};

struct ctrash {
    int operator()(trash T) const {
        return (T[0] * (1LL * T[1] + 6969)) % 998244353;
    }
};

void kmp(int n, const string &s, vi &kmp) {
    kmp[0] = 0;
    int i = 1, j = 0;
    while(i < n) {
        if(s[i] == s[j]) kmp[i++] = ++j;
        else if(j == 0) kmp[i++] = 0;
        else j = kmp[j - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ugh smh(2);
    int n;
    cin >> n;
    vector<vector<pair<int ,char>>> g(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    vector<vi> par(20);
    vector<char> parch(n + 1);
    rep(i, 0, 20) par[i].resize(n + 1);
    vi tin(n + 1), tout(n + 1), dep(n + 1);
    int ti = 0;
    auto dfs = [&](auto dfs, int x, int p) -> void {
        par[0][x] = p;
        tin[x] = ti++;
        for(auto &e : g[x]) {
            int y = e.first;
            if(y != p) {
                dep[y] = 1 + dep[x];
                parch[y] = e.second;
                dfs(dfs, y, x);
            }
        }
        tout[x] = ti++;
    };
    auto lift = [&](int x, int k) {
        rep(l, 0, 20) {
            if(k >> l & 1) {
                x = par[l][x];
            }
        }
        return x;
    };
    dfs(dfs, 1, 1);
    rep(l, 1, 20) {
        rep(i, 1, n + 1) {
            par[l][i] = par[l - 1][par[l - 1][i]];
        }
    }
    auto anc = [&](int x, int y) {
        return  tin[x] <= tin[y] && tout[y] <= tout[x];
    };
    auto lca = [&](int x, int y) {
        if(anc(x, y)) return x;
        for(int l = 19; l >= 0; l--) {
            if(!anc(par[l][x], y)) {
                x = par[l][x];
            }
        }
        return par[0][x];
    };

    int q;
    cin >> q;
    vi ans(2 * q);
    vector<vector<pair<int, trash>>> qu(n + 1);
    string S(3e5 + 5, ' ');
    vi fail(3e5 + 5);
    unordered_map<trash, int, ctrash> trash_table;
    int landfill = 0;
    rep(i, 0, q) {
        int u, v;
        string s;
        cin >> u >> v >> s;
        int len = s.length();
        trash h, h2;
        for(char c : s) {
            smh.addchar(h, c);
        }
        for(int j = len - 1; j >= 0; j--) {
            smh.addchar(h2, s[j]);
        }
        trash_table[h] = landfill++;
        trash_table[h2] = landfill++;
        int c = lca(u, v);
        qu[u].push_back({2 * i, h});
        qu[v].push_back({2 * i, h2});

        // find all occurrences
        // lift u and v, trace path manually
        // create string, and do KMP
        u = lift(u, max(0, dep[u] - dep[c] - len + 1));
        v = lift(v, max(0, dep[v] - dep[c] - len + 1));
        qu[u].push_back({2 * i + 1, h});
        qu[v].push_back({2 * i + 1, h2});
        int slen = 0;
        rep(i, 0, len) {
            S[slen++] = s[i];
        }
        S[slen++] = '$';
        while(u != c) {
            S[slen++] = parch[u];
            u = par[0][u];
        }
        int L = slen;
        while(v != c) {
            S[slen++] = parch[v];
            v = par[0][v];
        }
        int R = slen;
        reverse(S.begin() + L, S.begin() + R);
        kmp(R, S, fail);
        rep(j, len, R) {
            if(fail[j] == len) {
                ans[2 * i]++;
            }
        }
    }
    // dfs tree to find all answers
    vi trashTable2ElectricBugaboo(1e6);

    auto add = [&](int x, int del) {
        trash h;
        for(int d = 1; d <= 100 && x != 1; d++) {
            smh.addchar(h, parch[x]);
            x = par[0][x];
            auto it = trash_table.find(h);
            if(it != trash_table.end()) {
                trashTable2ElectricBugaboo[it->second] += del;
            }
        }
    };
    auto dfs2 = [&](auto dfs2, int x, int p) -> void {
        add(x, 1);
        for(auto &e : qu[x]) {
            ans[e.first] += trashTable2ElectricBugaboo[trash_table[e.second]];
        }
        for(auto &e : g[x]) {
            int y = e.first;
            if(y != p) {
                dfs2(dfs2, y, x);
            }
        }
        add(x, -1);
    };
    dfs2(dfs2, 1, 1);

    rep(i, 0, q) {
        cout << ans[2 * i] - ans[2 * i + 1] << '\n';
    }
}
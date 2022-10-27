#include<bits/stdc++.h>
using namespace std;
int const nax = 8e5 + 10;
constexpr int ALPHA = 26;

struct Aho_Corasick {
    int nxt[nax][ALPHA] = {};
    int link[nax] = {};
    int top = 0;
    /// always be careful with UB.

    int add_query (string const &t) {
        int v = 0;
        for (char ch : t) {
            int c = ch - 'a';
            if (!nxt[v][c]) {
                nxt[v][c] = ++ top;
                v = top;
            } else {
                v = nxt[v][c];
            }
        }

        return v;
    }

    void get_link () {
        static int q[nax];
        int topQ = 0;
        q[topQ ++] = 0;

        for (int _i = 0 ; _i < topQ ; ++ _i) {
            int cur = q[_i];

            for (int i = 0 ; i < ALPHA ; ++ i) {
                if (nxt[cur][i]) {
                    link[nxt[cur][i]] = cur ? nxt[link[cur]][i] : 0;
                    q[topQ ++] = nxt[cur][i];
                } else {
                    nxt[cur][i] = nxt[link[cur]][i];
                }
            }
        }
    }
};

struct fenwick {
    int bit[nax << 1] = {};

    void update (int idx, int val) {
        for (; idx < nax ; idx += idx & -idx)
            bit[idx] += val;
    }

    int get (int idx) {
        int res = 0;
        for (; idx > 0 ; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    int get (int l, int r) {
        return get(r) - get(l - 1);
    }
};

int trie[nax][ALPHA];
int top = 0;
vector <int> memo[nax];
int where[nax];

void add_to_trie (string const &s, int id) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (!trie[v][c]) {
            trie[v][c] = ++ top;
            v = top;
        } else v = trie[v][c];
    }
    memo[v].push_back(id);
    where[id] = v;
}

void append (char x, int from, int id) {
    int v = where[from];
    int c = x - 'a';
    if (!trie[v][c]) {
        trie[v][c] = ++ top;
        v = top;
    } else v = trie[v][c];
    memo[v].push_back(id);
    where[id] = v;
}

int n;
Aho_Corasick dfa;
int nq;
int tin[nax];
int tout[nax];
int timer;
int ans[nax];

vector <int> a[nax];
vector <pair <int, int>> query[nax];
fenwick bit;

void dfs_link (int v) {
    tin[v] = ++ timer;
    for (int u : a[v])
        dfs_link(u);
    tout[v] = ++ timer;
}

void dfs_trie (int v, int state) {
    bit.update(tin[state], 1);
     //   bit.update(tout[state] + 1, -1);
    for (int x : memo[v]) {
        for (pair <int, int> &p : query[x]) {
            ans[p.second] = bit.get(tin[p.first], tout[p.first]);
        }
    }

    for (int i = 0 ; i < ALPHA ; ++ i) {
        if (trie[v][i]) {
            dfs_trie(trie[v][i], dfa.nxt[state][i]);
        }
    }

    bit.update(tin[state], -1);
  //      bit.update(tout[state] + 1, 1);

}

int main() {

    cin.tie(0)->sync_with_stdio(false);

    cin >> n;

    for (int i = 1 ; i <= n ; ++ i) {
        int type;
        cin >> type;
        if (type == 1) {
            string s;
            cin >> s;
            add_to_trie(s, i);
        } else if (type == 2) {
            int from;
            char add;
            cin >> from >> add;
            append(add, from, i);
        } else assert(false);
    }

    cin >> nq;

    for (int i = 1 ; i <= nq ; ++ i) {
        int id;
        string t;
        cin >> id >> t;
        int v = dfa.add_query(t);
        query[id].emplace_back(v, i); /// node in dfa
    }

    dfa.get_link();


    for (int i = 1 ; i <= dfa.top ; ++ i) {
        a[dfa.link[i]].push_back(i);
    }
/*
    function <void (int)> dfs_link = [&] (int v)->void {
        tin[v] = ++ timer;
        for (int u : a[v])
            dfs_link(u);
        tout[v] = ++ timer;
    };
*/
    dfs_link(0);

/*
    function <void (int, int)> dfs_trie = [&] (int v, int state) -> void {

        bit.update(tin[state], 1);
     //   bit.update(tout[state] + 1, -1);
        for (int x : memo[v]) {
            for (pair <int, int> &p : query[x]) {
                ans[p.second] = bit.get(tin[p.first], tout[p.first]);
            }
        }

        for (int i = 0 ; i < ALPHA ; ++ i) {
            if (trie[v][i]) {
                dfs_trie(trie[v][i], dfa.nxt[state][i]);
            }
        }

        bit.update(tin[state], -1);
  //      bit.update(tout[state] + 1, 1);
    };
*/
    dfs_trie(0, 0);


    for (int i = 1 ; i <= nq; ++ i) {
        cout << ans[i] << '\n';
    }

}
/*
    Good Luck
        -Lucina
*/
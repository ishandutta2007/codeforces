/**
    BOI 2020 : Virus
*/
#include<bits/stdc++.h>
using namespace std;
struct Aho_Corasick {
    static const int ALPHA = 2;
    static const int nax = 128;
    /**
        add string and build Aho-Corasick DFA
        status :
        You are given some strings...
        https://codeforces.com/contest/1202/problem/E
        -> This just ensures that DFA is correct, but not accepting state
        More to test...
        Indie Album, codeforces
        /// binary string searching :P
        BOI 2019 Virus
    */

    int nxt[nax][ALPHA] = {};
    int link[nax] = {};
    int val[nax] = {};
    int top = 0; /// would it cause UB again :P, be careful with = {}

    void add_string (string const &s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';

            if (nxt[v][c]) {
                v = nxt[v][c];
            } else {
                nxt[v][c] = ++ top;
                v = top;
            }
        }
        ++ val[v];
    }

    void add_string (vector <int> const &a) {
        int v = 0;
        for (int c : a) {
            if (nxt[v][c])
                v = nxt[v][c];
            else {
                nxt[v][c] = ++ top;
                v = top;
            }
        }
        ++ val[v];
    }

    void get_link () {
        // build DFA
        static int q[nax];
        int topQ = 0;
        q[topQ ++] = 0;
        for (int _i = 0 ; _i < topQ ; ++ _i) {
            int cur = q[_i];

            val[cur] += val[link[cur]];

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
using ull = uint64_t;
const ull INF = 1ull << 63;

struct node_t {
    ull val;
    int from;
    int st;
    int en;
    node_t () : val(), from(), st(), en() {}
    node_t (ull val, int from, int st, int en) : val(val), from(from), st(st), en(en) {}

    bool operator <(const node_t &other) const {
        return val > other.val;
    }
};


priority_queue<node_t> pq;
Aho_Corasick dfa;
int n, g, m;
vector <int> e[228];
vector <pair <int, int>> el[228];
vector <pair <int, int>> er[228];

ull dp[220][220][220];
bool used[220][220][220];


int main () {
    scanf("%d %d %d", &g, &n, &m);

    int tot = g;
    for (int __ = 1 ; __ <= n; ++ __) {
        static int c[150];
        int a, k;
        scanf("%d %d", &a, &k);
        for (int i = 1 ; i <= k; ++ i) {
            scanf("%d", c + i);
        }

        if (k == 1) {
           e[c[1]].push_back(a);
        } else {
            int cur_a = a;
            for (int i = 1 ; i <= k - 2 ; ++ i) {
                int new_gene = ++ tot;
                er[c[i]].emplace_back(cur_a, new_gene);
                el[new_gene].emplace_back(cur_a, c[i]);
                cur_a = new_gene;
            }
            er[c[k - 1]].emplace_back(cur_a, c[k]);
            el[c[k]].emplace_back(cur_a, c[k - 1]);
        }
    }

    for (int __ = 1 ; __ <= m ; ++ __ ) {
        int len;
        scanf("%d", &len);
        vector <int> input(len);
        for (int &i : input)
            scanf("%d", &i);
        dfa.add_string(input);
    }

    dfa.get_link();

    for (int i = 0 ; i < 210 ; ++ i)
    for (int j = 0 ; j < 210 ; ++ j)
    for (int k = 0 ; k < 210 ; ++ k)
        dp[i][j][k] = INF;

    for (int to_add = 0 ; to_add < 2 ; ++ to_add) {
        for (int st = 0 ; st <= dfa.top ; ++ st) {
            if (dfa.val[st] == 0 && dfa.val[dfa.nxt[st][to_add]] == 0) {
                dp[to_add][st][dfa.nxt[st][to_add]] = 1;
                pq.emplace(1, to_add, st, dfa.nxt[st][to_add]);
            }
        }
    }

    while (!pq.empty()) {
        auto [val, node, st, en] = pq.top();
        pq.pop();
        if (used[node][st][en]) continue;
        used[node][st][en] = true;
        for (int to : e[node])
            if (dp[to][st][en] > val) {
                dp[to][st][en] = val;
                pq.emplace(val, to, st, en);
            }

        for (auto [x, y] : er[node]) {
            for (int new_ed = 0 ; new_ed <= dfa.top; ++ new_ed) {
                if (dp[x][st][new_ed] > val + dp[y][en][new_ed]) {
                    dp[x][st][new_ed] = val + dp[y][en][new_ed];
                    pq.emplace(dp[x][st][new_ed], x, st, new_ed);
                }
            }
        }

        for (auto [x, y] : el[node]) {
            for (int new_st = 0; new_st <= dfa.top; ++ new_st) {
                if (dp[x][new_st][en] > dp[y][new_st][st] + val) {
                    dp[x][new_st][en] = dp[y][new_st][st] + val;
                    pq.emplace(dp[x][new_st][en], x, new_st, en);
                }
            }
        }
    }

    for (int i = 2 ; i < g ; ++ i) {
        ull ans = INF;
        for (int j = 0 ; j <= dfa.top; ++ j) {
            ans = min(ans, dp[i][0][j]);
        }
        if (ans == INF) {
            puts("YES");
        } else {
            printf("NO %llu\n", ans);
        }
    }
}
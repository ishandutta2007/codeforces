#include<bits/stdc++.h>
using namespace std;
const int nax = 2e6 + 10;
constexpr int ALPHA = 26;
const int MOD = 1e9 + 7;
const int P = 998244353;
/**
    if the answer <= 10, it means that
    we can just compare

    |         s          ||  t   |


    According to KMP,


*/
string s;

struct Aho_Corasick {
    int nxt[nax][ALPHA] = {};
    int link[nax] = {};
    int dep[nax] = {};
    int top = 0;
    int par[nax];
    /// always be careful with UB.

    int add_query(string const &t) {
        int v = 0;
        int d = 0;
        for (char ch : t) {
            int c = ch - 'a';
            if (!nxt[v][c]) {
                nxt[v][c] = ++ top;
                par[top] = v;
                v = top;
            } else {
                v = nxt[v][c];
            }
            ++ d;
            dep[v] = d;
        }
        return v;
    }

    int add_query_at(int v_at, string const &t) {
        int v = v_at, d = dep[v_at];
        for (char ch : t) {
            int c = ch - 'a';
            if (!nxt[v][c]) {
                nxt[v][c] = ++ top;
                par[top] = v;
                v = top;
            } else {
                v = nxt[v][c];
            }
            ++ d;
            dep[v] = d;
        }
        return v;
    }

    void search_link(int v_at, string const &t) {
        int v = v_at,  d = dep[v_at];
        for (char ch : t) {
            int c = ch - 'a';
            v = nxt[v][c];
            int cv = v;
            int lnk = link[v];
            while (dep[lnk] > s.size()) {
                while (dep[cv] > dep[lnk]) {
                    cv = par[cv];
                }
                if (cv == lnk) {
                    break;
                }
                lnk = link[lnk];
            }
            cout << dep[lnk] << ' ';
        }
    }

    void get_link() {
        vector <int> q;
        q.push_back(0);

        for (int _i = 0 ; _i < q.size() ; ++ _i) {
            int cur = q[_i];

            for (int i = 0 ; i < ALPHA ; ++ i) {
                if (nxt[cur][i]) {
                    link[nxt[cur][i]] = cur ? nxt[link[cur]][i] : 0;
                    q.push_back(nxt[cur][i]);
                } else {
                    nxt[cur][i] = nxt[link[cur]][i];
                }
            }
        }
    }
};




Aho_Corasick dfa;
int q;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> s;
    cin >> q;
    vector <string> t(q);
    int rt = dfa.add_query(s);

    for (int i = 0 ; i < q ; ++ i) {
        cin >> t[i];
        dfa.add_query_at(rt, t[i]);
    }
    dfa.get_link();
    for (int i = 0 ; i < q ; ++ i) {
        dfa.search_link(rt, t[i]);
        cout << '\n';
    }
}
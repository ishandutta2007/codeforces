#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;

struct Aho_Corasick {
    static const int ALPHA = 26;

    int nxt[nax][ALPHA] = {};
    int link[nax] = {};
    int val[nax] = {};
    int top = 0;

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

    void get_link () {
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

    void get_cnt (int *ct, string const &s) {
        int v = 0;
        for (int i = 0 ; i < (int)s.size() ; ++ i) {
            v = nxt[v][s[i] - 'a'];
            ct[i] = val[v];
        }
    }
};

Aho_Corasick pref, suf;
int ct[2][nax];

int main () {
    cin.tie(0)->sync_with_stdio(false);

    string t;
    cin >> t;

    int n;
    string s;
    cin >> n;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> s;
        pref.add_string(s);
        reverse(s.begin(), s.end());
        suf.add_string(s);
    }

    n = t.size();
    pref.get_link();
    suf.get_link();

    pref.get_cnt(ct[0], t);

    reverse(t.begin(), t.end());

    suf.get_cnt(ct[1], t);
    reverse(ct[1], ct[1] + n);

    long long ans = 0;

    for (int i = 0 ; i < n;  ++ i) {
        ans += 1LL * ct[0][i] * ct[1][i + 1];
    }

    cout << ans << '\n';
}
/*
    Good Luck
        -Lucina
*/
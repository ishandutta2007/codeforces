#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 6e5 + 1;

struct node {
    int nxt[26], par, link, sz;
    ll ways;

    node() {
        memset(nxt, -1, sizeof(nxt));
        par = link = ways = -1, sz = 0;
    }
} nds[N];
int id = 1, used[N], timer;

inline int add(int a, char ch) {
    int b = id++;
    nds[b].par = a, nds[b].link = 0;
    for (; a != -1; a = nds[a].link) {
        if (nds[a].nxt[ch - 'a'] == -1) {
            nds[a].nxt[ch - 'a'] = b;
            continue;
        }
        int c = nds[a].nxt[ch - 'a'];
        if (a == nds[c].par) {
            nds[b].link = c;
            break;
        }

        int clone = id++;
        nds[clone].link = nds[c].link;
        nds[clone].par = a;
        nds[b].link = nds[c].link = clone;
        memcpy(nds[clone].nxt, nds[c].nxt, sizeof(nds[c].nxt));

        for (; a != -1 && nds[a].nxt[ch - 'a'] == c; a = nds[a].link)
            nds[a].nxt[ch - 'a'] = clone;
        break;
    }
    return nds[nds[b].par].nxt[ch - 'a'];
}

inline void dfs1(int v) {
    if (v == -1 || used[v] == timer)
        return;
    used[v] = timer, nds[v].ways = -1;
    dfs1(nds[v].par), dfs1(nds[v].link);
}

inline ll dp(int v) {
    if (nds[v].ways >= 0)
        return nds[v].ways;
    nds[v].ways = -nds[v].ways - 1;
    for (int i = 0; i < 26; i++) {
        int u = nds[v].nxt[i];
        if (u != -1 && used[u] > timer - 2)
            dp(u), nds[v].ways += nds[u].ways;
    }
    return nds[v].ways;
}

inline ll dfs2(int v) {
    if (v == -1 || used[v] == timer)
        return 0;
    used[v] = timer;
    return dp(v) * nds[v].sz + dfs2(nds[v].par) + dfs2(nds[v].link);
}

inline ll solve(const string &s) {
    int c = 0;
    for (auto ch : s)
        c = add(c, ch);

    timer++, dfs1(c);
    for (int v = c; v != -1; v = nds[v].link)
        nds[v].ways--;

    return timer++, dfs2(c);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    set<string> ins;
    int q;
    cin >> q >> ws;
    while (q--) {
        int tp;
        string s;
        cin >> tp >> s;

        if (tp == 3) {
            cout << solve(s) << endl;
        } else {
            if (tp == 2 && ins.find(s) == ins.end())
                continue;
            if (tp == 1 && ins.find(s) != ins.end())
                continue;

            if (tp == '-')
                ins.erase(s);
            else
                ins.insert(s);
            int c =  0;
            for (auto ch : s)
                c = add(c, ch);
            nds[c].sz += (tp == 2 ? -1 : 1);
        }
    }
}
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 6e5 + 10;
string s[maxN];
map<char, int> to[maxN];
int link[maxN];
int len[maxN];
int last = 0;
int sz = 1;

void add_letter(char c) {
    int p = last;
    last = sz++;
    len[last] = len[p] + 1;
    for (; to[p][c] == 0; p = link[p]) {
        to[p][c] = last;
    }
    if (to[p][c] == last) {
        link[last] = 0;
        return;
    }
    int q = to[p][c];
    if (len[q] == len[p] + 1) {
        link[last] = q;
        return;
    }
    int cl = sz++;
    to[cl] = to[q];
    link[cl] = link[q];
    len[cl] = len[p] + 1;
    link[last] = link[q] = cl;
    for (; to[p][c] == q; p = link[p]) {
        to[p][c] = cl;
    }
}

int tp[maxN];
string add[maxN];
int val[maxN];
int who[maxN];
vector<int> g[maxN];
int state[maxN];
priority_queue<pair<int,int>> t[4 * maxN];
int timer = 0;
int tin[maxN];
int tout[maxN];

void dfs(int v) {
    tin[v] = timer++;
    for (int to : g[v]) {
        dfs(to);
    }
    tout[v] = timer;
}

int cur[maxN];
void upd(int v, int tl, int tr, int l, int r, int x, int tp) {
    if (r < tl || tr < l) return;
    if (l <= tl && tr <= r) {
        t[v].push(make_pair(cur[x], x));
        return;
    }
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, x, tp);
    upd(2 * v + 1, tm + 1, tr, l, r, x, tp);
}
int getmax(int v, int tl, int tr, int pos) {
    int x = 0;
    while (!t[v].empty() && cur[t[v].top().second] != t[v].top().first) t[v].pop();
    if (!t[v].empty()) x = t[v].top().first;
    if (tl == tr) return x;
    int tm = (tl + tr) / 2;
    if (pos <= tm) x = max(x, getmax(2 * v, tl, tm, pos));
    else x = max(x, getmax(2 * v + 1, tm + 1, tr, pos));
    return x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
//        for (char &c : s[i]) add_letter(c);
    }
    for (int i = 1; i <= m; i++) {
        cin >> tp[i];
        if (tp[i] == 1) {
            cin >> who[i] >> val[i];
            val[i]++;
        }
        else {
            cin >> add[i];
            for (char &c : add[i]) add_letter(c);
        }
    }
    for (int i = 1; i < sz; i++) {
        g[link[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (char &c : s[i]) {
            if (!to[state[i]].count(c)) {
                state[i] = -1;
                break;
            }
            state[i] = to[state[i]][c];
        }
    }
    dfs(0);
    for (int i = 1; i <= n; i++) {
        cur[i] = 1;
        int c = state[i];
        if (c == -1) continue;
        upd(1, 0, sz - 1, tin[c], tout[c] - 1, i, 1);
    }
    for (int i = 1; i <= m; i++) {
        if (tp[i] == 1) {
            int c = who[i];
            int where = state[c];
            if (where == -1) continue;
            cur[c] = val[i];
            upd(1, 0, sz - 1, tin[where], tout[where] - 1, c, 1);
        }
        else {
            int d = -1;
            int f = 0;
            for (char& c : add[i]) {
                f = to[f][c];
                d = max(d, getmax(1, 0, sz - 1, tin[f]) - 1);
            }
            cout << d << '\n';
        }
    }
    return 0;
}
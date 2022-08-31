#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 4 * (int)1e5 + 100;
map < char, int > to[maxN];
int link[maxN];
int len[maxN];
int last = 0;
int sz = 1;
void add_letter(char c) {
    int p = last;
    last = sz++;
    len[last] = len[p] + 1;
    for(; to[p][c] == 0; p = link[p]) {
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
string t;
string s[maxN];
int n;
int val[2][maxN];
vector < int > g[maxN];
int coef[maxN];
void process(string& s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!to[cur].count(s[i])) return;
        cur = to[cur][s[i]];
    }
    coef[cur]++;
}
void dfs(int v) {
    for (int to : g[v]) {
        coef[to] += coef[v];
        dfs(to);
    }
}
void build(string& t, int p) {
    memset(coef, 0, sizeof coef);
    sz = 1;
    last = 0;
    for (int i = 0; i < t.size(); i++) {
        add_letter(t[i]);
    }
    for (int i = 0; i < sz; i++) g[i].clear();
    for (int i = 1; i < sz; i++) {
        g[link[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) process(s[i]);
    dfs(0);
    int cur = 0;
    for (int i = 0; i < t.size(); i++) {
        cur = to[cur][t[i]];
        val[p][i] = coef[cur];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    build(t, 0);
    reverse(t.begin(), t.end());
    for (int i = 0; i < maxN; i++) to[i].clear();
    for (int i = 1; i <= n; i++) {
        reverse(s[i].begin(), s[i].end());
    }
    build(t, 1);
    ll ans = 0;
    int m = t.size();
    // val[0][i] - after i + 1
    // ab val[0][0]   val[1][0]
    for (int i = 0; i + 2 <= m; i++) {
        ans += 1LL * val[0][i] * val[1][m - 2 - i];
    }
    cout << ans;
    return 0;
}
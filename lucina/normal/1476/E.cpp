#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 10;
int n, m, k;
int trie[nax * 4][27];
int f[nax * 4];
int top;
bool found = false;
vector <int> foo;
vector <int> g[nax];
vector <int> ord;
bool vis[nax];
bool d[nax];
bool fail;
int com(char x) {
    if (x == '_') return 0;
    return x - 'a' + 1;
}

void topsort(int node) {
    vis[node] = true;
    d[node] = true;
    for (int to : g[node]) {
        if (!vis[to]) {
            topsort(to);
        } else if (d[to]) {
            fail = true;
        }
    }
    d[node] = false;
    ord.push_back(node);
}

void add(const string &s, int id) {
    int v = 0;
    for (const char &c : s) {
        int nxt = com(c);
        if (trie[v][nxt] == -1) {
            trie[v][nxt] = ++ top;
        }
        v = trie[v][nxt];
    }
    f[v] = id;
}

void go(int v, int sz,const string &s, int mt) {
    if (v == -1) return;
    if (sz == k) {
        if (f[v] == mt) {
            found = true;
        } else if (f[v] != -1) {
            g[mt].push_back(f[v]);
          //  printf("Add edge %d %d\n", mt, f[v]);
        } else assert(false);
    } else {
        int nxt = com(s[sz]);
        go(trie[v][nxt], sz + 1, s, mt);
        go(trie[v][0], sz + 1, s, mt);
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    memset(trie, -1, sizeof(trie));

    cin >> n >> m >> k;

    string pat;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> pat;
        add(pat, i);
    }

    string s;
    int mt;

    for (int i = 1 ; i <= m ; ++ i) {
        cin >> s >> mt;
        found = false;
        go(0, 0, s, mt);
        if (!found) {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = 1 ; i <= n ; ++ i) {
        if (!vis[i]) topsort(i);
    }

    if (fail) return cout << "NO\n", 0;
    cout << "YES\n";

    reverse(ord.begin(), ord.end());
    for (int i : ord) cout << i << ' ';
    cout << '\n';

}
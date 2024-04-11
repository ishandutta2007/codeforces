#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
vector <int> g[nax];
int par[nax];

int ask(vector <int> s) {
    cout << "? " << s.size();
    for (int i : s) cout << " " << i;
    cout << endl;
    int foo;
    cin >> foo;
    return foo;
}

vector <int> ord;

void dfs(int node, int parent) {
    par[node] = parent;
    ord.push_back(node);
    for (int to : g[node])
        if (to != parent) dfs(to, node);
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int mx;
    vector <int> bar(n);
    iota(bar.begin(), bar.end(), 1);
    mx = ask(bar);


    dfs(1, 0);
    int l = 2, r = n;
    int c;
    while (l <= r) {
        int mid = l + r >> 1;
        vector <int> foo;
        for (int i = 0 ; i < mid ; ++ i)
            foo.push_back(ord[i]);
        if (ask(foo) == mx) {
            c = ord[mid - 1];
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << "! " << c << ' ' << par[c];
    cout << endl;
}
/*
    Well, such a long time from last div.2 round
*/
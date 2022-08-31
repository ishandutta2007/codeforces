#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;
const int maxN = 2e5 + 10;
int a[maxN];
int b[maxN];
int ans[maxN];
int freq[maxN];
vector<int> g[maxN];
int prv[maxN];
bool used[maxN];
int par[maxN];
int n;
int clr[maxN];
void dfs(int v, int p) {
    used[v] = true;
    for (int to : g[v]) {
        if (used[to]) continue;
        par[to] = v;
        dfs(to, v);
    }
}
int id[maxN];
int T = 0;
int max_freq;
void go(int v) {
    id[v] = T;
    for (int to : g[v]) {
        if (id[to] != -1 || freq[to] == max_freq) continue;
        go(to);
    }
}
bool OK = true;
void go3(int v) {
    clr[v] = 1;
    for (int to : g[v]) {
        if (freq[to] == max_freq || clr[to] == 2) continue;
        if (clr[to] == 1) {
            OK = false;
        }
        else {
            go3(to);
        }
    }
    clr[v] = 2;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        freq[i] = 0;
        used[i] = false;
        par[i] = -1;
        g[i].clear();
        id[i] = -1;
        clr[i] = 0;
    }
    max_freq = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        freq[a[i]]++;
        max_freq = max(max_freq, freq[a[i]]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        g[a[i]].emplace_back(b[i]);
    }
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (freq[i]) {
            root = i;
        }
    }
    dfs(root, -1);
    vector<int> cyc = {root};
    int t = -1;
    for (int i = 1; i <= n; i++) {
        for (int to : g[i]) {
            if (to == root) {
                t = i;
                break;
            }
        }
    }
    while (t != root) {
        cyc.emplace_back(t);
        t = par[t];
    }
    reverse(cyc.begin(), cyc.end());
    int good = 0;
    for (int i = 1; i <= n; i++) {
        if (freq[i] == max_freq) {
            good++;
        }
    }
    int bad = 0;
    for (int v : cyc) {
        if (freq[v] == max_freq) {
            bad++;
        }
    }
    if (bad != good) {
        cout << "WA\n";
        return;
    }
    T = 0;
    for (int v : cyc) {
        if (freq[v] == max_freq) {
            go(v);
            T++;
        }
    }
    for (int i = 1; i <= n; i++) {
        clr[i] = 0;
    }
    OK = true;
    for (int i = 1; i <= n; i++) {
        if (freq[i] != max_freq && clr[i] == 0 && freq[i] > 0) {
            go3(i);
        }
    }
    if (!OK) {
        cout << "WA\n";
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (freq[i] == max_freq) {
                for (int to : g[i]) {
                    if (freq[to] == max_freq && (id[to] != (id[i] + 1) % T)) {
                        cout << "WA\n";
                        return;
                    }
                    if (freq[to] != max_freq && id[to] != id[i]) {
                        cout << "WA\n";
                        return;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (freq[i] != 0 && freq[i] != max_freq) {
                for (int to : g[i]) {
                    if (freq[to] == max_freq && id[to] != (id[i] + 1) % T) {
                        cout << "WA\n";
                        return;
                    }
                    if (freq[to] != max_freq && id[to] != id[i]) {
                        cout << "WA\n";
                        return;
                    }
                }
            }
        }        
        cout << "AC\n";
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
}
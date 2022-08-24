#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 5005;
const int mod = (int)1e9 + 7;
int n, m;
int c[maxN], p[maxN];
vector < int > all;
int who[maxN];
int when[maxN];
bool used[maxN];
vector < int > g[maxN];
int mt[maxN];
const int INF = (int)1e9;
bool ok[maxN];
bool kuhn1(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || kuhn1(mt[to])) {
            mt[to] = v;
            ok[v] = true;
            return true;
        }
    }
    return false;
}
int find_mex() {
    for (int i = 1; i <= m; i++) {
        if (mt[i] != -1) ok[mt[i]] = true;
    }
    for (int i = 0; ; i++) {
        if (!ok[i]) return i;
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(mt, -1, sizeof mt);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    int days;
    cin >> days;
    for (int i = 1; i <= days; i++) {
        int x;
        cin >> x;
        who[i] = x;
        when[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (when[i] == 0) {
            g[p[i]].push_back(c[i]);
        }
    }
    vector < int > ans;
    int x = 0;
    memset(mt, -1, sizeof mt);
    while (true) {
        memset(used, 0, sizeof used);
        kuhn1(x);
        if (ok[x]) x++;
        else break;
    }
    for (int i = days; i >= 1; i--) {
        ans.push_back(x);
        g[p[who[i]]].push_back(c[who[i]]);
        while (true) {
            memset(used, 0, sizeof used);
            kuhn1(x);
            if (ok[x]) x++;
            else break;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int v : ans) cout << v << '\n';
    return 0;
}
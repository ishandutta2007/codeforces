#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 200 * 1000 + 10;
vector<int> g[N];
int color[N];

int dfs(int v, int par, int cur_col, int par_col) {
    color[v] = cur_col;
    set<int> was;
    was.insert(cur_col);
    was.insert(par_col);
    int c = 0;
    while (was.count(c))
        c++;
    for (int to : g[v]) {
        if (to == par)
            continue;
        was.insert(dfs(to, v, c, cur_col));
        while (was.count(c))
            c++;
    }
    return cur_col;
}

int main() {
#if FALSE
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int v = 0;
    for (int i = 0; i < n; i++)
        if (g[i].size() > g[v].size())
            v = i;
    dfs(v, v, 0, -1);
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, color[i] + 1);
    cout << res << endl;
    for (int i = 0; i < n; i++)
        cout << color[i] + 1 << " ";
    cout << endl;
}
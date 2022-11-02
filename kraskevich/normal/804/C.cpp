#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 1000 * 1000;

vector<int> g[N];
vector<int> at[N];
int ans = 1;
int col[N];

void dfs(int v, int par) {
    set<int> was;
    for (int x : at[v])
        if (col[x] != -1)
            was.insert(col[x]);
    int cur = 0;
    for (int x : at[v])
        if (col[x] == -1) {
            while (was.count(cur))
                cur++;
            was.insert(cur);
            col[x] = cur;
        }
    for (int to : g[v])
        if (to != par)
            dfs(to, v);
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;
        ans = max(ans, cnt);
        for (int j = 0; j < cnt; j++) {
            int x;
            cin >> x;
            --x;
            at[i].push_back(x);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fill(col, col + m, -1);
    dfs(0, 0);
    for (int i = 0; i < m; i++)
        if (col[i] == -1)
            col[i] = 0;
    cout << ans << endl;
    for (int i = 0; i < m; i++)
        cout << col[i] + 1 << " ";
    cout << endl;
}
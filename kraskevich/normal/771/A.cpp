#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define F first
#define S second

const int N = 200 * 1000 + 10;

vector<int> g[N];
bool was[N];
int e;
int cnt;

void dfs(int v) {
    cnt++;
    was[v] = true;
    for (int to : g[v]) {
        e++;
        if (!was[to])
            dfs(to);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) 
        if (!was[i]) {
            e = 0;
            cnt = 0;
            dfs(i);
            if (e != cnt * 1ll * (cnt - 1)) {
                cout << "NO\n";
                return 0;
            }
        }
    cout << "YES\n";
}
#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 200 * 1000 + 10;

vector<int> g[N];
bool was[N];
vector<int> od;

void dfs(int v) {
    od.push_back(v);
    was[v] = true;
    for (int to : g[v]) {
        if (was[to])
            continue;
        dfs(to);
        od.push_back(v);
    }
}

int main() {
#if FALSE
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    int st = 0;
    for (int i = 0; i < k; i++) {
        int len = (2 * n + k - 1) / k;
        vector<int> v;
        if (st >= int(od.size()))
            st = int(od.size()) - 1;
        while (st < od.size() && v.size() < len) {
            v.push_back(od[st]);
            was[od[st]] = true;
            st++;
        }
        cout << v.size() << " ";
        for (int x : v)
            cout << x + 1 << " ";
        cout << "\n";

    }
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = 100100;

int n, m;
vector<int> adj[maxn];
int ma[maxn];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ma[i] = 1;
        for (int j : adj[i])
            ma[i] = max(ma[i], ma[j] + 1);
        ans = max(ans, ll(adj[i].size()) * ma[i]);
    }

    cout << ans << '\n';
}
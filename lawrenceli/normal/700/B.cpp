#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200100;

int N, K, sub[maxn];
bool U[maxn];
vector<int> adj[maxn];
ll ans;

int dfs(int v, int p = -1) {
    int num = U[v];
    sub[v] = U[v];
    for (int i : adj[v])
        if (i != p) {
            int x = dfs(i, v);
            ans += x;
            num += x;
            sub[v] += sub[i];
        }

    int x = 2 * K - sub[v];
    while (num > x) num -= 2;
    //cout << v << ' ' << num << endl;
    return num;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < 2 * K; i++) {
        int a; cin >> a;
        U[a] = 1;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    cout << ans << '\n';
}
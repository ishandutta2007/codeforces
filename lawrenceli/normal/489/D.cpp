#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 3005;

int n, m, num[MAXN][MAXN];
vector<int> adj[MAXN], bdj[MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        bdj[b].push_back(a);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<adj[i].size(); j++)
            for (int k=0; k<bdj[i].size(); k++)
                num[adj[i][j]][bdj[i][k]]++;
    }

    ll ans = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (i != j)
                ans += ll(num[i][j])*(num[i][j]-1)/2;
    cout << ans << '\n';
}
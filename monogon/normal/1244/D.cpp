
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5;
int n, u, v;
ll c[N][3];
// c1 = color this cell must be.
// c2 = color of parent
ll dp[N][3][3];
int col[N];
bool vis[N];
vector<int> adj[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c[i][0];
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i][1];
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i][2];
    }
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        if(adj[i].size() == 1) u = i;
        else if(adj[i].size() > 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll Msum = LLONG_MAX;
    vector<int> bestperm;
    vector<int> perm = {0, 1, 2};
    do {
        ll sum = 0;
        v = u;
        int prev = -1;
        for(int i = 0; ; i++) {
            sum += c[v][perm[i % 3]];
            if(adj[v][0] == prev) {
                if(adj[v].size() == 1) break;
                prev = v;
                v = adj[v][1];
            }else {
                prev = v;
                v = adj[v][0];
            }
        }
        if(sum < Msum) {
            bestperm = perm;
            Msum = sum;
        }
        Msum = min(Msum, sum);
    }while(next_permutation(perm.begin(), perm.end()));
    cout << Msum << endl;
    v = u;
    int prev = -1;
    for(int i = 0; ; i++) {
        col[v] = bestperm[(i % 3)];
        if(adj[v][0] == prev) {
            if(adj[v].size() == 1) break;
            prev = v;
            v = adj[v][1];
        }else {
            prev = v;
            v = adj[v][0];
        }
    }
    for(int i = 0; i < n; i++) {
        cout << (col[i] + 1) << " ";
    }
    cout << endl;
}
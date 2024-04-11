
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// choose something as the root
// we can permute its child subtrees however we like
// then the subtrees become their own segments
// product of how many ways to do them, times number of ways to permute them with the root itself

// 1 -- 2 -- 4
// |
// 3 

// 3: 1 way. 4: 1 way. 2: 2 ways. 1: 2*1*3! ways.

// 4 -- 1 -- 2
//      |
//      3
// 1*1*1*4! = 4! = 24

const int N = 2e5 + 5, M = 998244353;
int n, u, v;
vector<int> adj[N];
bool vis[N];
ll fact[N];

ll dfs(int x) {
    vis[x] = true;
    ll prod = 1, num = 1;
    for(int y : adj[x]) {
        if(!vis[y]) {
            prod = (prod * dfs(y)) % M;
            num++;
        }
    }
    return (prod * fact[num - (x == 1)]) % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = (i * fact[i - 1]) % M;
    }
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << ((n * dfs(1)) % M) << '\n';
}
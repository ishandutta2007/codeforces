#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N,M;
vector<vector<int>> E;
string S;
vector<int> Enter, Exit;
vector<vector<pair<int, int>>> G;

void dfs(int u, int &T, int d) {
    if (d == G.size()) G.push_back({{0,0}});
    int m = G[d].rbegin()->second ^ (1<<(S[u]-'a'));
    G[d].emplace_back(T, m);

    Enter[u] = T++;
    for (int v:E[u]) dfs(v,T,d+1);
    Exit[u] = T;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> N >> M;
    E.resize(N);
    Enter.resize(N); 
    Exit.resize(N);
    for (int i = 1; i < N; ++i) {
        int p; cin >> p;
        E[p-1].push_back(i);
    }
    cin >> S;
    int t = 1;
    dfs(0, t, 0);

    for (int i = 0; i < M; ++i) {
        int v,h; cin >> v >> h; --v; --h;
        if (h >= G.size()) { cout << "Yes\n"; continue; }
        int l = Enter[v], r = Exit[v];
        auto it = lower_bound(G[h].begin(),G[h].end(),pair<int,int>{l, -1});
        auto ir = lower_bound(G[h].begin(),G[h].end(),pair<int,int>{r, -1});
        --it; --ir;
        int mask = it->second ^ ir->second;
        cout << (__builtin_popcount(mask) <= 1 ? "Yes" : "No") << '\n';
    }
    

}
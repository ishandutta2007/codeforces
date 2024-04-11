#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<vector<int> > g;
vector<bool> u;
int res;

void dfs(int v, int k) {
     res = max(res, k);
     u[v] = true;
     for(int i = 0; i < g[v].size(); ++i) {
             int to = g[v][i];
             if(!u[to])
                       dfs(to, k + 1);
     }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, ans = 0;
    
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            res = 0;
            g.resize(k);
            for(int i = 0; i < k; ++i)
                    g[i].resize(0);
            for(int j = 0; j < k - 1; ++j) {
                    int a, b;
                    cin >> a >> b;
                    --a, --b;
                    g[a].push_back(b);
                    g[b].push_back(a);
            }
            for(int j = 0; j < k; ++j) {
                    u.assign(k, false);
                    dfs(j, 0);
                    cout << endl;
            }
            ans += res;
    }
    
    cout << ans;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
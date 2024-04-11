#include <iostream>
#include <string>
#include <vector>
using namespace std;

int p[10000];
vector<vector<int> > g(10000);
vector<int> u(10000, -1);
int ans = 0;

void dfs(int v, int k, int s) {
     ans = max(ans, k);
     u[v] = s;
     for(int i = 0; i < g[v].size(); ++i) {
             int to = g[v][i];
             if(u[to] != s)
                       dfs(to, k + 1, s);
     }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if(a > 0) 
                g[i].push_back(--a);
    }
    for(int i = 0; i < n; ++i)
                     dfs(i, 1, i);
    cout << ans;
    cin >> n;
    return 0;
}
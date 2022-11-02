#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > g(100);
vector<int> u(100, 0);
bool ok = true;

void dfs(int v, int c) {
     u[v] = c;
     for(int i = 0; i < g[v].size(); ++i) {
             int to = g[v][i];
             if(u[to] == 0)
                      dfs(to, (c == 2 ? 1 : 2));
             else
                 if(u[to] == u[v])
                          ok = false;
     }
}

int main() {
    int n, m;
    
    cin >> n >> m;
    
    int s[m], f[m];
    
    for(int i = 0; i < m; ++i) {
            cin >> s[i] >> f[i];
            --s[i], --f[i];
            if(s[i] > f[i])
                    swap(s[i], f[i]);
    } 
    
    for(int i = 0; i < m; ++i) 
            for(int j = i + 1; j < m; ++j) 
                    if((s[i] < s[j] && f[i] < f[j] && s[j] < f[i]) || (s[i] > s[j] && f[j] < f[i] && s[i] < f[j])) {
                             g[i].push_back(j);
                             g[j].push_back(i);
                    }
    for(int i = 0; i < m; ++i)
            if(u[i] == 0)
                    dfs(i, 1);
    
    
    if(!ok) 
            cout << "Impossible";
    else
        for(int i = 0; i < m; ++i)
                cout << (u[i] == 1 ? 'i' : 'o');
                
    cin >> m;
    
    return 0;
}
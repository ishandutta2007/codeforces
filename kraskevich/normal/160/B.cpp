#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > g(1000);
vector<bool> u(1000);
vector<int> mt(1000);
             
bool dfs(int v) {
     if(u[v])
             return false;
     u[v] = true;
     for(int i = 0; i < g[v].size(); ++i) {
             int to = g[v][i];
             if(mt[to] == -1 || dfs(mt[to])) {
                       mt[to] = v;
                       return true;
             }
     }
     return false;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; ++i)
            for(int j = n; j < n + n; ++j)
                    if(s[i] < s[j])
                            g[i].push_back(j - n);
    mt.assign(n, -1);
    for(int i = 0; i < n; ++i) {
            u.assign(n, false);
            dfs(i);
    }
    bool ok = true;
    for(int i = 0; i < n; ++i) 
            if(mt[i] < 0) 
                     ok = false;
    if(ok) {
           cout << "YES" << endl;
           cin >> n;
           return 0;
    }
    for(int i = 0; i < n; ++i)
            g[i].clear();
    for(int i = 0; i < n; ++i)
            for(int j = n; j < n + n; ++j)
                    if(s[i] > s[j])
                            g[i].push_back(j - n);
    mt.assign(n, -1);
    for(int i = 0; i < n; ++i) {
            u.assign(n, false);
            dfs(i);
    }
    ok = true;
    for(int i = 0; i < n; ++i)
            if(mt[i] < 0) 
                     ok = false;
                     
    if(ok) {
           cout << "YES" << endl;
           cin >> n;
           return 0;
    }
    cout << "NO";
    cin >> n;
    return 0;
}
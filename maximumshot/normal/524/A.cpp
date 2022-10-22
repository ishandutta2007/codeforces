#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector
 
typedef long long LL;
typedef long double LD;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = 1ll << 32;
const LD eps = 1e-8;
 
bool solve()
{
    map<int, vec<int>> g;
    map<int, map<int, int>> G;
    map<int, set<int>> ans;

    int m, k;
    set<int> s;

    cin >> m >> k;

    for(int i(0);i < m;i++)
    {
        int u, v;
        cin >> u >> v;
        s.insert(u);
        s.insert(v);
        g[u].push_back(v);
        g[v].push_back(u);
        G[u][v] = G[v][u] = 1;
    }

    set<int> tmp;
    
    for(auto i : s)
    {
        for(auto j : s)
        {
            if(i == j) continue;
            if(G[i][j]) continue;
            tmp.clear();
            for(auto z : g[i]) 
            {
                if(G[z][j]) tmp.insert(z);
            }

            if((int)g[i].size() * k <= 100 * (int)tmp.size()) ans[i].insert(j);
        }
    }

    for(auto i : s)
    {
        cout << i << ": " << (int)ans[i].size() << ' ';
        for(auto j : ans[i]) cout << j << ' ';
        cout << '\n';
    }

    return true; 
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}
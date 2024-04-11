#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

#define ll long long

vector<vector<ll> > g;
vector<bool> u;
ll res = 0;
int k;

vector<ll> dfs(int v) {
     vector<ll> d(k + 1, 0);
     u[v] = true;
     d[0] = 1;
     for(int i = 0; i < g[v].size(); ++i) {
             int to = g[v][i];
             if(u[to] == true)
                      continue;
             vector<ll> c = dfs(to);
             for(int j = 1; j <= k - 1; ++j)
                     res += (ll)d[j] * c[k - j - 1];
             for(int j = 1; j <= k; ++j) 
                     d[j] += c[j - 1];
     }
    res += d[k]; 
    return d;
}

int main() {
    int n;
    cin >> n >> k;
    g.resize(n);
    u.assign(n, false);
    for(int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            g[--a].push_back(--b);
            g[b].push_back(a);
    }
    if(k >= n) {
         cout << 0;
         return 0;
    }
    dfs(0);
    cout << res;
    cin >> n;
    return 0;
}
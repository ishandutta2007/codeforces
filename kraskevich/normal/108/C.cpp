#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int g[1000][1000];
vector<bool> u(1000, false);
int n;

struct ans {
       int from, to, d;
       ans(int a, int b, int c): from(a), to(b), d(c) {}
};

vector<ans> a;

void dfs(int v, int minD, int start) {
     u[v] = true;
     bool done = false;
     for(int i = 0; i < n; ++i) 
             if(g[v][i] > 0 && !u[i]) {
                        done = true;
                        dfs(i, min(minD, g[v][i]), start);
             } 
     if(!done) 
               a.push_back(ans(start + 1, v + 1, minD));
}

int main() {
   int m;
   
   cin >> n >> m;
   
   for(int i = 0; i < n; ++i)
           for(int j = 0; j < n; ++j)
                   g[i][j] = -1;
   
   vector<bool> s(n, false);
   vector<bool> is(n, false);
   
   for(int i = 0; i < m; ++i) {
           int t, b, d;
           cin >> t >> b >> d;
           --t;
           --b;
           s[b] = true;
           is[t] = true;
           g[t][b] = d;
   }
   
   for(int i = 0; i < n; ++i)
           if(!u[i] && is[i] && !s[i])
                    dfs(i, 1000 * 1000 + 1, i);
   
   cout << a.size() << endl;
   for(int i = 0; i < a.size(); ++i)
           cout << a[i].from << " " << a[i].to << " " << a[i].d << endl;
   
   cin >> n;
   
   return 0; 
}
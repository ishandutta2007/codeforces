#include <bits/stdc++.h>
using namespace std;

int n,m;

vector < pair < int, int > > g[100500];

int x,y,w,u;

long long d[100500];

int p[100500];

priority_queue < pair < long long, int > > nee;

int main() {
 //freopen("input.txt", "r", stdin);
 //freopen("output.txt","w",stdout);
   cin>>n>>m;
   for ( int i = 1; i <= m; i++) {
        cin>>x>>y>>w;
        auto t = make_pair(y,w);
        g[x].push_back(t);
        t = make_pair(x,w);
        g[y].push_back(t);
   }
   for ( int i = 2; i <= n; i++){
        d[i] = 1e12;
   }
   for ( int i = 1; i<=n ; i++){
        auto t = make_pair(-d[i],i);
        nee.push(t);
   }
   for ( int i = 1; i<=n; i++) {
        auto t = nee.top();
        nee.pop();
        int v = t.second;
        for ( int j = 0; j < g[v].size(); j++) {
            int to = g[v][j].first;
            int we = g[v][j].second;
            if ( d[to] > d[v] + we ) {
                d[to] = we + d[v];
                nee.push(make_pair(-d[to],to));
                p[to] = v;
            }
        }
   }
   vector <int> ans;
   int to = n;
   if ( d[n] == 1e12 ) {
    cout<<-1<<endl;
    return 0;
   }
   while ( to != 1 ) {
    ans.push_back(to);
    to = p[to];
   }
   ans.push_back(1);
   for ( int i = 0; i < ans.size(); i++) {
        cout<<ans[ans.size() - 1 - i]<<" ";
   }
   return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int a[N];
vector<int> G[N];
vector<int> dp[N];
map<int,int> rev[N];
int sum[N];
bool visit[N];
 
int dfs(int root, int par) {
    for(auto it: G[root]) dp[root].push_back(0);
    int cur = 0;
    for(int i=0;i<G[root].size();i++) {
        if(G[root][i] == par) continue;
        dp[root][i] = dfs(G[root][i],root);
        cur += dp[root][i];
    }
    if(a[root] == 1) cur++;
    sum[root] = cur;
    return cur;
}
 
void seconddfs(int root, int par, int cur) {
    sum[root] += cur;
    for(int i=0;i<G[root].size();i++) {
        if(G[root][i] == par) {
            dp[root][i] = cur;
            continue;
        }
        seconddfs(G[root][i],root,sum[root]-dp[root][i]);
    }
}
 
int main() {
    int n; cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n-1;i++) {
        int a,b; cin>>a>>b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
 
    //Now root a tree at 0 and make the dp for each child
    dfs(0,0);
    seconddfs(0,0,0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<G[i].size();j++) {
            rev[i][G[i][j]] = dp[i][j];
        }
    }
 
    //Finally, just bfs from all black node
    queue<int> qu;
    for(int i=0;i<n;i++) {
        bool pass = (a[i] == 1);
        for(auto it: G[i])
            pass |= (a[it] == 1);
        if(pass) qu.push(i);
    }
    while(!qu.empty()) {
        int node = qu.front();
        qu.pop();
        if(visit[node]) continue;
        visit[node] = true;
        for(auto it: G[node]) {
            if(rev[it][node] >= 2 && !visit[it]) {
                qu.push(it);
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout<<visit[i]<<' ';
    }
    return 0;
}
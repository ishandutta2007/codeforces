#include "bits/stdc++.h"
using namespace std;
#define REP(a,b) for(int a = 0;a < b;++a)
vector<int> vertexs[200];
pair<int,int> dist[200];
void dfs(int now,int back){
  for(auto x:vertexs[now]){
    if(x == back) continue;
    dist[x] = make_pair(dist[now].first + 1,now);
    dfs(x,now);
  }
}
int n,k;
vector<int> ans;
int visited[200] = {};
int del_dfs(int now,int back){
  if(k == 0) return 1;
  for(auto x:vertexs[now]){
    if(x == back) continue;
    if(visited[x] == 1) continue;
    ans.push_back(x);
    k--;
    int gogo = del_dfs(x,now);
    ans.push_back(now);
    if(gogo == 1){
      return 1;
    }
  }
  return 0;
}
void solve(){
  cin >> n >> k;
  k--;
  REP(i,n){
    vertexs[i].clear();
    visited[i] = 0;
  }
  REP(i,n-1){
    int a;
    cin >> a;
    a--;
    vertexs[i+1].push_back(a);
    vertexs[a].push_back(i+1);
  }
  dfs(0,-1);
  int now = 0;
  for(int i = 0;i < n;++i){
    if(dist[i].first > dist[now].first){
      now = i;
    }
  }
  vector<int> traverse;
  while(now != 0){
    traverse.push_back(now);
    now = dist[now].second;
  }
  traverse.push_back(now);
  reverse(traverse.begin(),traverse.end());
  while(traverse.size() > k+1) traverse.pop_back();
  k -= (int)traverse.size()-1;
  ans.push_back(0);
  REP(i,traverse.size()){
    visited[traverse[i]] = 1;
  }
  for(int i = 0;i < traverse.size()-1;++i){
    del_dfs(traverse[i],traverse[i+1]);
    ans.push_back(traverse[i+1]);
  }
  cout << ans.size()-1 << endl;
  int ok = 1;
  for(auto x:ans){
    if(ok == 1){
      ok = 0;
    }else{
      cout << " ";
    }
    cout << x+1;
  }
  cout << endl;
  ans.clear();
}
int main(){
  int t;
  cin >> t;
  REP(tea,t){
    solve();
  }
}
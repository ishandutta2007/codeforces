#include<bits/stdc++.h>
using namespace std;
long long int n,u,v;
vector<long long int>tree[500001];
void pre(){}
int curr = 1;
map<int,pair<int,int>>ans;
set<int>avail;
void dfs(int to,int from,int start){
    int uu = start;
    priority_queue<int>pq;
    for(auto i:tree[to]){
        if(i!=from){
            pq.push(*avail.begin());
            avail.erase(*avail.begin());
        }
    }
    int pp = *avail.begin();
    avail.erase(pp);
    for(auto i:tree[to]){
        if(i!=from){
            dfs(i,to,pq.top());
            pq.pop();
        }
    }
    ans[to]={uu,pp};
}
void solve(){
    cin>>n;
    map<int,pair<int,int>>m;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        m[i]={min(u,v),max(u,v)};
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=2;i<=2*n;i++) avail.insert(i);
    dfs(1,0,curr);
    for(auto i:ans){
        cout<<i.second.first<<" "<<i.second.second<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
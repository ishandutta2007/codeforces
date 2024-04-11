#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int n,k,u,v;
vector<long long int>arr[200001];
long long int oo[200001]{0};
int dfs(int to,int from){
    int val = 0;
    for(auto i:arr[to]){
        if(i!=from){
            val+=dfs(i,to);
        }
    }
    oo[to]=val;
    return val+1;
}
void solve(){
   cin>>n>>k;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[v].push_back(u);
        arr[u].push_back(v);
    }
    bool fla[n+1];
    bool vis[n+1];
    dfs(1,0);
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<=n;i++){
        vis[i]=0;
    }
    queue<pair<int,int>>q;
    q.push({0,1});
    vis[1]=1;
    while(q.size()!=0){
        auto i = q.front();
        q.pop();pq.push({i.first-oo[i.second],i.second});
        for(auto j:arr[i.second]){
            if(!vis[j]){
                q.push({i.first+1,j});    
                vis[j]=1;
            }
        }
    }
    long long int ans = 0;
    for(int i=0;i<k;i++){
        auto j = pq.top();
        pq.pop();
        ans+=j.first;
    }
    cout<<ans<<"\n";
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
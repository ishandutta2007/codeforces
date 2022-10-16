#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int mi=0,ma=0;
long long int k,u,v,t;
map<pair<int,int>,int>m;
bool visited[2000001]{0};
vector<long long int> g[2*100001];
long long int dfs(int a,int par){
    long long int ret = 1;
    visited[a]=1;
    for(auto i:g[a]){
        if(!visited[i]){
            ret+=dfs(i,a);
        }
    }
    if(par!=-1){
        ma+=min(ret,2*k-ret)*m[{a,par}];
        mi+=ret%2*m[{a,par}];
    }
    return ret;
}   
void solve(){
    m.clear();
    cin>>k;
    mi=0;ma=0;
    for(int i=0;i<2*k;i++){
        g[i].clear();
        visited[i]=0;
    }
    for(int i=1;i<2*k;i++){
        cin>>u>>v>>t;u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
        m[{u,v}]=t;
        m[{v,u}]=t;
    }
    dfs(0,-1);
    cout<<mi<<" "<<ma<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int n,u,v;
bool flag = 0;
bool par = 0;
int mi = 1;
vector<long long int>g[100001];
void dfs(int to,int from,bool p){
    p=!p;
    int val = 0;
    for(auto i:g[to]){
        if(i!=from){
            dfs(i,to,p);
            val++;
        }
    }
    if(val==0){
        if(!flag){
            flag=1;
            par=p;
        }else if(p!=par){
            mi=3;
        }
    }
}
void solve(){
    cin>>n;
    for(long long int i=0;i<n-1;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int root;
    set<long long int>leaf;
    for(int i=1;i<=n;i++){
        if(g[i].size()!=1){
            root=i;
        }else{
            leaf.insert(i);
        }
    }
    dfs(root,0,0);
    int ma = n-1;
    for(int i=1;i<=n;i++){
        int val = 0;
        for(auto j:g[i]){
            if(leaf.find(j)!=leaf.end()){
                val++;
            }
        }
        ma-=max(0,val-1);
    }
    cout<<mi<<" "<<ma<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
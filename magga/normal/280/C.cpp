#include<bits/stdc++.h>
using namespace std;
long long int n,u,v;
vector<int>arr[100001];
long double ans=0.0;
long long int siz[100001]{0};
void dfs(int to,int from,int val){
    int ret = 1;
    ans+=1.0/val;
    for(auto i:arr[to]){
        if(i!=from){
            dfs(i,to,val+1);
            siz[to]+=siz[i];
        }
    }
}

void pre(){}
void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1,0,1);
    cout<<setprecision(26)<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}
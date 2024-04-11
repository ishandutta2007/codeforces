#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,x,y,z;
vector<int>arr[200001];
int a[3][200001];
int b[200001];
int c[200001];
bool vis[200001]{0};
void reset(){
    for(int i = 0;i<=n;i++){
        arr[i].clear();
    }
}
void ff(){
    for(int i=0;i<=n;i++)vis[i]=0;
}
void bfs(int to,int vo){
    queue<pair<int,int>>q;
    q.push({to,0});
    ff();
    vis[to]=1;
    int ret = 0;
    while(q.size()>0){
        auto i = q.front();
        q.pop();
        a[vo][i.first]=i.second;
        for(auto j:arr[i.first]){
            if(!vis[j]){
                q.push({j,i.second+1});
                vis[j]=1;
            }
        }
    }
}
void pre(){}
void solve(){
    cin>>n>>m>>x>>y>>z;
    reset();
    long long int val[m];
    for(int i=0;i<m;i++){cin>>val[i];}
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    long long int pre[m+1];
    pre[0]=0;
    sort(val,val+m);
    for(int i=0;i<m;i++)pre[i+1]=pre[i]+val[i];
    bfs(x,0);
    bfs(y,1);
    bfs(z,2);
    long long int ans = 1e18,oo=0;
    for(int i=1;i<=n;i++){
        if(a[0][i]+a[1][i]+a[2][i]>m){
            continue;
        }
        oo = pre[min(a[0][i]+a[1][i]+a[2][i],m)];
        oo+=pre[a[1][i]];
        ans=min(oo,ans);
    }
    cout<<ans<<"\n";
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
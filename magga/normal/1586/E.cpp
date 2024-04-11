#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}
vector<int>arr[300005];
vector<int>G[300005];
bool vis[300005]{0};
void dfs(int i,int from){
    if(vis[i]) return;
    vis[i]=1;
    if(from!=-1){
        arr[i].push_back(from);
        arr[from].push_back(i);
    }
    for(auto j:G[i]) dfs(j,i);
}
vector<vector<int>>ans;

bool dfs2(int i,int from,int to,int val){
    if(to==i) {
        ans[val].push_back(to);
        return true;
    }
    bool ret = false;
    for(auto j:arr[i]){
        if(j!=from){
            auto oo = dfs2(j,i,to,val);
            ret|=oo;
            if(oo){
                ans[val].push_back(i);
            }
        }
    }
    return ret;
}

void solve(){
    int n,m,u,v,a,b;cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1);
    int q;cin>>q;
    ans.resize(q);
    int cont[n+1];
    for(int i=0;i<=n;i++) cont[i]=0;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        dfs2(a,-1,b,i);
        cont[a]^=1;
        cont[b]^=1;
    }
    int answer = 0;
    for(auto i:cont) if(i) answer++;
    if(answer>0){
        cout<<"NO"<<"\n";
        cout<<answer/2<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    for(auto i:ans){
        reverse(i.begin(),i.end());
        cout<<i.size()<<"\n";
        for(auto j:i) cout<<j<<" ";
        cout<<"\n";
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
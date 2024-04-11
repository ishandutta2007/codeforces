#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
ll visited = 0;
bool vis[300001]{0};
int flag[300001]{0};
vector<int>arr[300001];
ll n,m,u,v,w;
vector<int>ans;
void dfs(int, int);
void dfs2(int i,int from){
    if(!vis[i]){
        visited++;
        vis[i]=1;
        for(auto to:arr[i]){
            if(!vis[to] && flag[to]!=-1){
                dfs(to,i);
            }
        }
    }
}
void dfs(int i,int from){
    if(!vis[i]){
        vis[i]=1;
        visited++;
        ans.push_back(i);
        flag[i]=1;
        for(auto to:arr[i]){
            flag[to]=-1;
        }
        for(auto to:arr[i]){
            dfs2(to,i);
        }
    }
}
void pre(){}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        arr[i].clear();
        vis[i]=0;
        flag[i]=0;
    }
    visited = 0;
    ans.clear();
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    dfs(1,0);
    if(visited!=n){
        cout<<"NO"<<"\n";
    }else{
        cout<<"YES"<<"\n";
        cout<<ans.size()<<"\n";
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
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
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define ff first
#define ss second
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define rofl exit(1);
#define debug(x) cerr<<(#x)<<"::"<<(x)<<"\n";
template<typename T> using OST=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1e9+7,mod2=998244353,inf=1e18;
void yes(){cout<<"YES\n";}
void no(){cout<<"NO\n";}
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
const int mxN=2e5+5;
vector<int> adj[mxN];
int dfn[mxN],pp[mxN],sz[mxN],timer=0;
void dfs(int u){
    dfn[++timer]=u;
    pp[u]=timer;
    sz[u]=1;
    for(auto i:adj[u]){
        dfs(i);
        sz[u]+=sz[i];
    }
}
void eat(){
    int n,q;
    cin>>n>>q;
    for(int i=2,x;i<=n;i++){
        cin>>x;
        adj[x].push_back(i);
    }
    for(int i=1;i<=n;i++)sort(adj[i].begin(),adj[i].end());
    dfs(1);
    while(q--){
        int u,v;
        cin>>u>>v;
        if(sz[u]<v)cout<<"-1\n";
        else cout<<dfn[pp[u]+v-1]<<"\n";
    }
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}
#include<bits/stdc++.h>
#pragma GCC target ("avx2")
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
ll n,u,v,w;
vector<int>arr[1001];
ll val[1001]{0};
void dfs(int to,int from){
    val[to]=1;
    for(auto i:arr[to]){
        if(i!=from){
            dfs(i,to);
            val[to]+=val[i];
        }
    }
}
bool dp[2001][2001]{0};
bool vis[2001][2001]{0};
void rec(int i,int j){
    vis[i][j]=1;
    if(i>0 && !vis[i-1][j]){
        rec(i-1,j);
    }
    if (j > 0 && !vis[i + 1][j-1]){
        rec(i + 1,j-1);
    }
    if((j==0 || dp[i+1][j-1]) && (i==0 || dp[i-1][j])){
        dp[i][j]=0;
    }else{
        dp[i][j]=1;
    }
}
void pre(){
    dp[0][0]=1;
    dp[1][0]=1;
    dp[0][1]=1;
    vis[0][0]=1;
    vis[0][1]=1;
    vis[1][0]=1;
}
void solve(){
    ll d;cin>>n>>d;
    for(int i=0;i<=n;i++){
        arr[i].clear();
    }
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    dfs(d,0);
    int o = 0,e = 0;
    for(auto i:arr[d]){
        if(val[i]%2==0){
            e++;
        }else{
            o++;
        }
    }
    if(!vis[o][e]){
        rec(o,e);
    }
    //cout<<dp[o-1][e]<<"\n";
    if(dp[o][e]){
        cout << "Ayush"<<"\n";
    }else{
        cout << "Ashish"<< "\n";
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
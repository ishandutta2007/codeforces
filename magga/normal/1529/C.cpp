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
vector<int>arr[100001];
ll limits[2][100001];
ll dp[2][100001];
ll n,u,v,w;
void dfs(int to,int from){
    dp[0][to]=0;
    dp[1][to]=0;
    for(auto i:arr[to]){
        if(i!=from){
            dfs(i,to);
        }
    }
    for(int j=0;j<2;j++){
        for(auto i:arr[to]){
            if(i!=from){
                dp[j][to] += max(dp[0][i]+abs(limits[0][i]-limits[j][to]),dp[1][i]+abs(limits[1][i]-limits[j][to]));
            }
        }
    }
}

// Please write the recurances once :(
void pre(){}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        arr[i].clear();
        cin>>limits[0][i]>>limits[1][i];
    }
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    } 
    dfs(1,0);
    cout<<max(dp[1][1],dp[0][1])<<"\n";
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
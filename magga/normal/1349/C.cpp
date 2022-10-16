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
void pre(){}
ll dp[1002][1002]{9223372036854775807};
bool vis[1002][1002]{0};
bool arr[1002][1002];
ll n,m,q;
bool check(int i,int j){
    if( arr[i][j]!=arr[i][j+1] && arr[i][j]!=arr[i][j-1] && arr[i][j]!=arr[i+1][j] && arr[i][j]!=arr[i-1][j] ){
        return true;
    }
    return false;
}
void bfs(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i][j]=1;
            dp[i][j]=9223372036854775807;
        }
    }
    queue<pair<pair<int,int>,int>>q;
    //cout<<check(1,1)<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!check(i,j)){
                vis[i][j]=0;
                q.push({{i,j},0});
                dp[i][j]=0;
            }
        }
    }
    while(q.size()!=0){
        auto i = q.front();
        q.pop();
        if(vis[i.F.F+1][i.F.S]){
            q.push({{i.F.F+1,i.F.S},i.S+1});
            vis[i.F.F+1][i.F.S]=0;
            dp[i.F.F+1][i.F.S]=i.S+1;
        }
        if(vis[i.F.F-1][i.F.S]){
            q.push({{i.F.F-1,i.F.S},i.S+1});
            vis[i.F.F-1][i.F.S]=0;
            dp[i.F.F-1][i.F.S]=i.S+1;
        }
        if(vis[i.F.F][i.F.S+1]){
            q.push({{i.F.F,i.F.S+1},i.S+1});
            vis[i.F.F][i.F.S+1]=0;
            dp[i.F.F][i.F.S+1]=i.S+1;
        }
        if(vis[i.F.F][i.F.S-1]){
            q.push({{i.F.F,i.F.S-1},i.S+1});
            vis[i.F.F][i.F.S-1]=0;
            dp[i.F.F][i.F.S-1]=i.S+1;
        }
    }
}
void solve(){
    cin>>n>>m>>q;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='1')
                arr[i][j+1]=1;
            else
                arr[i][j+1]=0;    
        }
        arr[i][0]=!arr[i][1];
        arr[i][m+1]=!arr[i][m];
    }
    for(int i=1;i<=m;i++){
        arr[0][i]=!arr[1][i];
        arr[n+1][i]=!arr[n][i];
    }
    bfs();
    ll a,b,c;
    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        //cout<<dp[a][b]<<"\n";
        if(c<dp[a][b]){
            cout<<arr[a][b]<<"\n";
        }else if( (c-dp[a][b])%2==1){
            cout<<!arr[a][b]<<"\n";
        }else{
            cout<<arr[a][b]<<"\n";
        }
    }
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
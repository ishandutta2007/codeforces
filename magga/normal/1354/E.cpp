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
int n,m,u,v,x,y,z;
vector<int>arr[5001];
bool a[5001];
bool vis[5001]{0};
void reset(){
    for(int i = 0;i<=n;i++){
        arr[i].clear();
    }
}
void ff(){
    for(int i=0;i<=n;i++)vis[i]=0;
}
set<int> val[2];
bool bfs(int to){
    val[1].clear();val[0].clear();
    queue<pair<int,int>>q;
    q.push({to,0});
    ff();
    vis[to]=1;
    int ret = 0;
    while(q.size()>0){
        auto i = q.front();
        q.pop();
        a[i.first]=i.second%2;
        val[i.second%2].insert(i.first);
        for(auto j:arr[i.first]){
            if(!vis[j]){
                q.push({j,i.second+1});
                vis[j]=1;
            }else{
                if((i.second+1)%2!=a[j]){
                    return 0;
                }
            }
        }
    }
    return 1;
}
bool dp[5001][5001]{0};
bool inv[5001][5001]{0};
void pre(){}
void solve(){
    ll n,m,n1,n2,n3;cin>>n>>m>>n1>>n2>>n3;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    vector<pair<set<int>,set<int>>>v;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(!bfs(i)){
                cout<<"NO"<<"\n";
                return;
            }
            v.push_back({val[0],val[1]});
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=v.size();i++){
        for(int j=0;j<=n;j++){
            if(dp[i-1][j]){
                dp[i][j+v[i-1].F.size()]=1;
                inv[i][j+v[i-1].F.size()]=0;
                dp[i][j+v[i-1].S.size()]=1;
                inv[i][j+v[i-1].S.size()]=1;
            }
        }
    }
    if(!dp[v.size()][n2]){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    pair<set<int>,set<int>>p;
    ll curr = n2;
    for(int i=v.size();i>=1;i--){
        if(inv[i][curr]){
            p = v[i-1];
            v[i-1].F=p.S;
            v[i-1].S=p.F;
        }
        curr-=v[i-1].F.size();  
    }
    int ans[n+1];
    for(int i=0;i<v.size();i++){
        for(int j:v[i].F){
            ans[j]=2;
        }
        for(int j:v[i].S){
            if(n1>0){
                ans[j]=1;
                n1--;
            }else{
                ans[j]=3;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i+1];
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
	//cout<<"Case #"<<i+1<<" :";
       	solve();
    }   
}
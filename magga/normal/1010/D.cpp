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
int dp[2][1000001];
vector<int>arr[1000001];
string func[1000001];
int val[1000001];
ll n,u,v,w;
int dfs(int i){
    if(func[i]=="IN"){
    }else if(func[i]=="NOT"){
        val[i] = 1-dfs(arr[i][0]);
    }else if(func[i]=="AND"){
        val[i] = dfs(arr[i][0]) & dfs(arr[i][1]);
    }else if(func[i]=="OR"){
        val[i] = dfs(arr[i][0]) | dfs(arr[i][1]);
    }else{
        val[i] = dfs(arr[i][0]) ^ dfs(arr[i][1]);
    }
    return val[i];
}
void dfs2(int i){
    int u,v;
    if(func[i]=="IN"){
    }else if(func[i]=="NOT"){
        u = arr[i][0];
        dp[1-val[u]][u] = dp[val[u]][i];
        dfs2(u);
    }else if(func[i]=="AND"){
        u = arr[i][0];
        v = arr[i][1];
        dp[1-val[u]][u] = dp[  (1-val[u]) & val[v] ][i];
        swap(u,v);
        dp[1-val[u]][u] = dp[  (1-val[u]) & val[v] ][i];
        dfs2(u);
        dfs2(v);
    }else if(func[i]=="OR"){
        u = arr[i][0];
        v = arr[i][1];
        dp[1-val[u]][u] = dp[ (1-val[u]) | val[v]  ][i];
        swap(u,v);
        dp[1-val[u]][u] = dp[ (1-val[u]) | val[v]  ][i];
        dfs2(v);
        dfs2(u);
    }else{
        u = arr[i][0];
        v = arr[i][1];
        dp[1-val[u]][u] = dp[ (1-val[u]) ^ val[v]  ][i];
        swap(u,v);
        dp[1-val[u]][u] = dp[ (1-val[u]) ^ val[v]  ][i];
        dfs2(u);
        dfs2(v);
    }
}
void pre(){}
void solve(){
    cin>>n;
    vector<int>ans;
    for(int i=1;i<=n;i++){
        cin>>func[i];
        if(func[i]=="IN"){
            ans.push_back(i);
            cin>>val[i];
        }else if(func[i]=="AND" || func[i]=="XOR" || func[i]=="OR"){
            cin>>u;
            arr[i].push_back(u);
            cin>>u;
            arr[i].push_back(u);
        }else{
            cin>>u;
            arr[i].push_back(u);
        }
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        dp[ val[i] ][ i ] = val[1] ;
    }
    dp[0][1] = 0;
    dp[1][1] = 1;
    dfs2(1);
    for(auto i : ans){
        cout<<dp[1-val[i]][i];
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}
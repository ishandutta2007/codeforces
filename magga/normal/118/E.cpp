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
long long int idx[100001];
bool visited[100001]{0};
ll dp[100001]{0};
vector<int>arr[100001];
ll n,u,v,w,m;
vector<pii>ans;
int counter = 0;
void dfs(int to,int from){
    idx[to]=counter;
    counter++;
    visited[to]=1;
    for(auto i:arr[to]){
        if(i!=from){
            if(!visited[i]){
                dfs(i,to);
                ans.push_back({to,i});
            }else if(idx[i]<idx[to]){
                ans.push_back({to,i});
                dp[i]++;
                dp[to]--;
            }
        }
    }
}
bool flag = 1;
void dfs2(int to,int from){
    visited[to]=1;
    for(auto i:arr[to]){
        if(i!=from && !visited[i]){
            dfs2(i,to);
        }
    }
    dp[from]+=dp[to];
    if(to!=1 && dp[to]==0){
        //cout<<to<<"\n";
        flag=0;
    }
}
void pre(){}
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1,0);
    for(int i=0;i<=n;i++){
        visited[i]=0;
    }
    dfs2(1,0);
    if(!flag){
        cout<<0<<"\n";
        return;
    }
    for(auto i:ans){
        cout<<i.F<<" "<<i.S<<"\n";
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
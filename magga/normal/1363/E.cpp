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
vector<int>arr[200001];
ll n,u,v,w;
ll val[200001];
bool curr[200001];
bool want[200001];
ll ans = 0;
void dfs(int to,int from){
    if(to!=1){
        val[to]=min(val[to],val[from]);
    }
    for(auto i:arr[to]){
        if(i!=from){
            dfs(i,to);

        }
    }
}
pii dfs2(int to,int from){
    pii a = {0,0};
    if(curr[to]!=want[to]){
        if(want[to]){
            a.second++;
        }else{
            a.first++;
        }
    }
    for(auto i:arr[to]){
        if(i!=from){
            auto p = dfs2(i,to);
            a.first+=p.first;
            a.second+=p.second;
        }
    }
    if(a.first>a.second){
        ans+=2*val[to]*a.second;
        a.first-=a.second;
        a.second=0;
    }else{
        ans+=2*val[to]*a.first;
        a.second-=a.F;
        a.F=0;
    }
    //cout<<to<<" "<<a.first<<" "<<a.second<<"\n";
    return a;
}   
void pre(){}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>val[i]>>curr[i]>>want[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[v].pb(u);
        arr[u].pb(v);
    }
    dfs(1,0);
    auto i = dfs2(1,0);
    if(i.F!=0 || i.S!=0){
        cout<<-1<<"\n";
    }else{
        cout<<ans<<"\n";
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
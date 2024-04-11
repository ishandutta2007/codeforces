
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
vector<int>arr[300001];
ll n,u,v,w;
ll ans = 0;
pair<int,int> dfs(int to,int from){
    int children = 0;
    int height = 0;
    for(auto i:arr[to]){
        if(i!=from){
            auto p = dfs(i,to);
            children += p.first;
            if(p.first){
                height = max(height,p.second+1);
            }
        }
    }
    //cout<<to<<" "<<height<<" "<<children<<"\n";
    if(height==0){
        return {1,0};
    }else{
        ans+=children-1;
        return {0,0};
    }
}
// Please write the recurances once :(
void pre(){}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        arr[i].clear();
    }
    ans = 1;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    auto i = dfs(1,0);
    cout<<ans<<"\n";
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
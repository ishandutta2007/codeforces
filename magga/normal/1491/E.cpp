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
set<int>arr[500001];
vector<ll>f{1,1};
map<ll,ll>m;
ll n,u,v,w;
pair<ll,pii> dfs(int to,int from,pii targets){
    pair<ll,pii> a = {1,{-1,-1}};
    for(auto i:arr[to]){
        if(i!=from){
            auto c = dfs(i,to,targets);
            a.F+=c.F;
            if(c.S.F!=-1){
                a.S=c.S;
            }
        }
    }
    if(a.F==targets.F){
        a.S={to,from};
    }else if(a.F==targets.S){
        a.S={from,to};
    }
    return a;
}
bool dnc(int i,int k){
    if(k==1 || k==0){
        auto c = dfs(i,0,{1,1});
        if(c.F==1){
            return true;
        }else{
            return false;
        }
    }
    auto j = dfs(i,0,{f[k-2],f[k-1]});
    if(j.S.F==-1){
        return false;
    }
    arr[j.S.F].erase(j.S.S);
    arr[j.S.S].erase(j.S.F);
    if( dnc(j.S.F,k-2) && dnc(j.S.S,k-1) ){
        return true;
    }
    return false;
}
void pre(){
    m[1]=1;
    while(f.back()<=1e6){
        f.push_back(f.back()+f[f.size()-2]);
        m[f.back()]=m[f[f.size()-2]]+1;
    }
    m[0]=1;
}
void solve(){
    ll n;cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].insert(v);
        arr[v].insert(u);
    }
    if(m.find(n)==m.end()){
        cout<<"NO"<<"\n";
        return;
    }
    if(dnc(1,m[n])){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}
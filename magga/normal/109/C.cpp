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
vector<int>arr[100001];
map<pii,bool>m;
ll n;
ll val[100001]{0};
void dfs(int to,int from){
    for(auto i:arr[to]){
        if(i!=from){
            dfs(i,to);
            if(!m[{i,to}]){
                val[to]+=val[i]+1;
            }
        }
    }
}
ll ans = 0;
void dfs2(int to,int from){
    //cout<<to<<" "<<val[to]<<"\n";
    ans+= (n-val[to]-1)*(n-val[to]-2);
    for(auto i:arr[to]){
        if(i!=from){
            ll oo = val[i]; 
            if(!m[{i,to}]){
                val[i]+=val[to]-val[i];
            }
            dfs2(i,to);
            val[i]=oo;
        }
    }
}
bool foo(string s){
    for(char c:s){
        if(c!='7' && c!='4'){
            return false;
        }
    }
    return true;
}
void pre(){}
void solve(){
    string w;
    cin>>n;
    ll u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v>>w;
        arr[u].pb(v);
        arr[v].pb(u);
        if(foo(w)){
            m[{u,v}]=1;
            m[{v,u}]=1;
        }else{
            m[{u,v}]=0;
            m[{v,u}]=0;
        }
    }   
    dfs(1,0);
    dfs2(1,0);
    cout<<ans<<"\n";
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
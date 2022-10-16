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
ll colour[100001];
ll ans[100001];
ll ma[100001];
map<int,int>m[100001];
ll n,u,v,w;
void dfs(int to,int from){
    ma[to] = 1;
    ans[to] = colour[to];
    m[to][colour[to]]=1;
    for(auto i:arr[to]){
        if(i!=from){
            dfs(i,to);
            if(m[to].size()<m[i].size()){
                swap(m[to],m[i]);
                ma[to]=ma[i];
                ans[to]=ans[i];
            }
            for(auto &i:m[i]){
                m[to][i.F]+=i.S;
                if(m[to][i.F]>ma[to]){
                    ma[to]=m[to][i.F];
                    ans[to]=i.F;
                }else if(m[to][i.F]==ma[to]){
                    ans[to]+=i.F;
                }
            }
        }
    }
}
void pre(){}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>colour[i];
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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
       	solve();
    }   
}
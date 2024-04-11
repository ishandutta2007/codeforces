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

const long long int mod = 1e9+7;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
long long int divi(long long int a,long long int b){return (a*inv(b))%mod;}
vector<ll>reo;
pair<int,bool> parent[500001];
int siz[500001];
int val[500001];
bool bipartite[500001];
void make_set(int v) {
    parent[v] = make_pair(v, 0);
    siz[v] = 0;
    bipartite[v] = true;
}
pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}
void union_sets(int a, int b) {
    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            bipartite[a] = false;
    } else {
        if (siz[a] < siz[b])
            swap (a, b);
        parent[b] = make_pair(a, x^y^1);
        bipartite[a] &= bipartite[b];
        if (siz[a] == siz[b])
            ++siz[a];
    }
}
bool check_lafda(int a,int b){
    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            return true;
    } 
    return false; 
}
bool is_bipartite(int v) {
    return bipartite[find_set(v).first];
}
void pre(){}
void solve(){
    ll n,m,k,u,v;cin>>n>>m;
    for(int i=0;i<=m;i++){
        make_set(i);
    }
    ll ans = 1;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k==1){
            cin>>u;
            if(find_set(u).F==find_set(0).F){
                continue;
            }else{
                union_sets(0,u);
                reo.push_back(i);
                ans = (ans*2)%mod;
            }
        }else{
            cin>>u>>v;
            if(find_set(u).F==find_set(0).F && find_set(v).F==find_set(0).F){
                continue;
            }else if( find_set(u).F==find_set(0).F || find_set(v).F==find_set(0).F ){
                union_sets(u,v);
                reo.push_back(i);
                ans = (ans*2)%mod;
            }else if(find_set(u).F!=find_set(v).F){
                union_sets(v,u);
                reo.push_back(i);
                ans = (ans*2)%mod;
            }
        }
    }
    cout<<ans<<" "<<reo.size()<<"\n";
    for(auto i:reo){
        cout<<i+1<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}
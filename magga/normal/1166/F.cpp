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
int parent[100001];
map<int,int>colours[100001];
int siz[100001];
set<int> val[100001];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    siz[v] = 1;
    val[v].clear();
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
        if(val[a].size()<val[b].size()){
            swap(val[a],val[b]);
        }
        for(auto &i:val[b]){
            val[a].insert(i);
        }
    }
}
void merge(int u,int v,int w){
    if(colours[u].find(w)==colours[u].end()){
        colours[u][w] = v;
    }else{
        union_sets(v,colours[u][w]);
    }
    if(colours[v].find(w)==colours[v].end()){
        colours[v][w] = u;
    }else{
        union_sets(u,colours[v][w]);
    }
    auto a = find_set(u);
    val[a].insert(v);
    a = find_set(v);
    val[a].insert(u);
}
void pre(){}
void solve(){
    ll n,m,u,v,w,q,c1;cin>>n>>m>>c1>>q;
    for(int i=0;i<=n;i++)   make_set(i);
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        merge(u,v,w);
    }
    char c;
    for(int i=0;i<q;i++){
        cin>>c;
        if(c=='+'){
            cin>>u>>v>>w;
            merge(u,v,w);
        }else{
            cin>>u>>v;
            if ( (find_set(u) == find_set(v))  || val[find_set(u)].find(v)!=val[find_set(u)].end() ){
                cout<<"Yes"<<"\n";
            }else{
                cout<<"No"<<"\n";
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
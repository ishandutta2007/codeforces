#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
struct DSU{
    int n;
    vector<int>parent;
    vector<int>size_of_component;
    vector<long long>to_compute;
    void make_set(int i){
        parent[i] = i;
        size_of_component[i] = 1;
    }
    void reset(int _n){
        n = _n;
        parent.resize(n+1);
        size_of_component.resize(n+1);
        to_compute.resize(n+1);
        for(int i=0;i<=n;i++) make_set(i);
    }
    DSU(){}
    DSU(int _n){
        reset(_n);
    }
    int find_component(int i){
        if(parent[i]==i) return i;
        parent[i] = find_component(parent[i]);
        return parent[i]; 
    }
    bool is_same_component(int u,int v){
        return find_component(u) == find_component(v);
    }
    void merge(int u,int v){
        if(is_same_component(u,v)) return;
        u = find_component(u);
        v = find_component(v);
        if(size_of_component[u]<size_of_component[v]) swap(u,v);
        parent[v] = u;
        size_of_component[u]+=size_of_component[v];
    }
};
// WRITE DOWN THE RECCURANCES FFS 
// Please write the recurances once :(
DSU d;
void pre(){}
void solve(){
    int n;cin>>n;
    d.reset(n);
    int arr[2][n];
    for(int i=0;i<n;i++)
        cin>>arr[0][i];
    for(int i=0;i<n;i++){
        cin>>arr[1][i];
        d.merge(arr[1][i]-1,arr[0][i]-1);
    }
    ll ans = 0;
    vector<int>cycles;
    vector<bool>f(n);
    for(int i=0;i<n;i++){
        if(!f[d.find_component(i)]){
            f[d.find_component(i)] = 1;
            cycles.push_back(d.size_of_component[d.find_component(i)]/2);
        }
    }
    sort(cycles.begin(),cycles.end());
    ll ender = n;
    ll start = 1;
    for(auto i:cycles){
        ll nender = ender;
        ll nstart = start;
        for(int j=0;j<(2*i-1);j++){
            ans+=(nender - nstart);
            if(j%2==0){
                nstart++;
            }else{
                nender--;
            }
        }
        if(i>0) ans+=(nender - start);
        if(i>0) nender--;
        ender = nender;
        start = nstart;
    }
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
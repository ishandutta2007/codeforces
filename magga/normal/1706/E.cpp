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

struct SegmentTree{
    vector<long long int>t;
    long long int n;
    SegmentTree(vector<long long int>&arr){
        n = arr.size();
        t.resize(2*n+10);
        for(int i=0;i<n;i++) t[n+i] = arr[i];
        build(); 
    }
    SegmentTree(int _n,long long int k = 0){
        n = _n;
        t.assign(2*n + 10,k);
        build();
    }
    long long int combine(long long int a,long long int b){
        return max(a,b);
    }
    void build(){
        for(long long int i=n-1;i>0;i--){
            t[i]=combine(t[i<<1],t[i<<1|1]);
        }
    }
    void modify(long long int p,long long int value){
        for(t[p+=n]=value;p>1;p>>=1){
            t[p>>1]=combine(t[p],t[p^1]);
        } 
    }
    long long int query(long long int l,long long int r){
        long long int ret = 0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) ret=combine(ret,t[l++]);
            if(r&1) ret=combine(t[--r],ret);
        }
        return ret;
    }
};

struct DSU{
    int n;
    vector<int>parent;
    vector<long long int>compute;
    vector<int>size_of_component;
    vector<map<int,int>>front,back;
    void make_set(int i){
        parent[i] = i;
        size_of_component[i] = 1;
        front[i][i]=i;
        back[i][i]=i;
    }
    void reset(int _n){
        n = _n;
        parent.resize(n+1);
        front.resize(n+1);
        back.resize(n+1);
        compute.resize(n+1);
        size_of_component.resize(n+1);
        for(int i=0;i<=n;i++) make_set(i);
    }
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
    void merge(int u,int v,int timer){
        if(is_same_component(u,v)) return;
        u = find_component(u);
        v = find_component(v);
        if(front[u].size()<front[v].size()) swap(u,v);
        parent[v] = u;
        for(auto pi:front[v]){
            if(back[u].find(pi.F-1)!=back[u].end() && front[u].find(pi.S+1)!=front[u].end()){
                int t = back[u][pi.F-1];
                int p = front[u][pi.S+1];
                compute[pi.F] = timer;
                compute[pi.S+1] = timer;
                front[u].erase(pi.S+1);
                back[u].erase(pi.F-1);
                front[u][t] = p;
                back[u][p] = t;
            }else if(back[u].find(pi.F-1)!=back[u].end()){
                int t = back[u][pi.F-1];
                compute[pi.F] = timer;
                back[u].erase(pi.F-1);
                back[u][pi.S] = t;
                front[u][t] = pi.S;
            }else if(front[u].find(pi.S+1)!=front[u].end()){
                int t = front[u][pi.S+1];
                compute[pi.S+1] = timer;
                front[u].erase(pi.S+1);
                front[u][pi.F] = t;
                back[u][t]    = pi.F;
            }else{
                front[u][pi.F] = pi.S;
                back[u][pi.S]  = pi.F;
            }
        }
        size_of_component[u]+=size_of_component[v];
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// WRITE DOWN THE RECCURANCES FFS 
void pre(){}
void solve(){
    int n,m,q;cin>>n>>m>>q;
    DSU d(n);
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        d.merge(u,v,i);
    }
    SegmentTree segs(d.compute);
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        cout<<segs.query(l+1,r+1)<<" ";
    }
    cout<<"\n";
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
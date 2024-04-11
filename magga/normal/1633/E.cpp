#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
set<int>edges;
int n,m;
ll ans = 0;
vector<pair<ll,pii>>e(m);
int parent[51];
int siz[51];
int val[51];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    siz[v] = 1;
}
void reset(){
    for(int i=0;i<=50;i++) make_set(i);
}
bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
        return true;
    }else{
        return false;
    }
}
bool add_edge(int i){
    if(union_sets(e[i].S.F,e[i].S.S)){
        edges.insert(i);
        return true;
    } 
    return false;
}
bool replace_edge(int i,int j){
    auto c = edges;
    edges.clear();
    reset();
    add_edge(j);
    for(auto k:c){
        if(k!=i) add_edge(k);
    }
    if(edges.size()==n-1) return true;
    edges.clear();
    reset();
    for(auto i:c) add_edge(i);
    return false;
}
pair<int,int> q[10000000];
// Please write the recurances once :(
void pre(){}
void solve(){
    cin>>n>>m;
    e.resize(m);
    for(int i=0;i<m;i++) cin>>e[i].S.F>>e[i].S.S>>e[i].F;
    sort(e.begin(),e.end());
    vector<pair<ll,pair<int,int>>>events;
    for(int i=0;i<m;i++){
        events.push_back({2*e[i].F,{i,i}});
        for(int j=i+1;j<m;j++){
            events.push_back({e[i].F+e[j].F,{i,j}});
        }
    }
    sort(events.begin(),events.end());
    vector<pair<ll,pii>>next;
    reset();
    ll ans = 0;
    int count = 1-n;
    for(int i=0;i<m;i++){
        if(add_edge(i)) ans+=2*e[i].F;
    }
    next.push_back({0,{ans,count}});
    for(auto i:events){
        if(edges.find(i.S.F)==edges.end()) continue;
        ans = next.back().S.F + count * (i.F -  next.back().F); 
        if(i.S.F==i.S.S){
            count+=2;
            next.push_back({i.F,{ans,count}});
        }else{
            if(replace_edge(i.S.F,i.S.S)){
                count-=2;
                next.push_back({i.F,{ans,count}});
            }
        }
    }
    next.push_back({1e18,{1e18,1e18}});
    ll p,k,a,b,c;
    cin>>p>>k>>a>>b>>c;
    for(int i=0;i<p;i++){
        cin>>q[i].F;
        q[i].S = i;
    }
    for(int i=p;i<k;i++){
        q[i].F = (q[i-1].F*a + b)%c;
        q[i].S = i;
    }
    for(int i=0;i<k;i++) q[i].F*=2;
    sort(q,q+k);
    int j = 0;
    ll pasd = 0;
    for(int i=0;i<k;i++){
        while(next[j+1].F<=q[i].F) j++;
        pasd ^=  (next[j].S.F + next[j].S.S * (q[i].F - next[j].F))/2; 
    }
    cout<<pasd<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}
/*
50 nodes 300 edges
1E7 QUERIES 
O(1) solution to MST needed or something of that order
an edhe changes at arthematic mean of 2 weights hence only 90000 swwitches 
thus O(m^3) mst plasuible
for each i j 2[wi] and w[i] + w[j] and 2[wj] are important
reoport ans / 2 for 2 x 
sort all queries (maibi tle less see)
*/
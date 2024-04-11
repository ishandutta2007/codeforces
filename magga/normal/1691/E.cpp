#include<bits/stdc++.h>
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
    int merge(int u,int v){
        if(is_same_component(u,v)) return 0;
        u = find_component(u);
        v = find_component(v);
        if(size_of_component[u]<size_of_component[v]) swap(u,v);
        parent[v] = u;
        size_of_component[u]+=size_of_component[v];
        return 1;
    }
};

void solve(){
    int n;cin>>n;
    vector<pair<pii,int>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].S>>v[i].F.F>>v[i].F.S;
    }
    DSU d(n);
    int components = n;
    sort(v.begin(),v.end());
    set<pii>red;
    set<pii>blue;
    for(int i=0;i<n;i++){
        int curr = v[i].F.F;
        while(red.size()>0 && (*red.begin()).F < curr){
            red.erase(*red.begin());
        }
        while(blue.size()>0 && (*blue.begin()).F < curr){
            blue.erase(*blue.begin());
        }
        if(v[i].S==1){
            red.insert({v[i].F.S,i});
        }else{
            blue.insert({v[i].F.S,i});
        }
        if(red.size()>0 && blue.size()>0){
            while(red.size()>1){
                components -= d.merge((*red.begin()).S,(*blue.begin()).S);
                red.erase(*red.begin());
            }
            while(blue.size()>1){
                components -= d.merge((*red.begin()).S,(*blue.begin()).S);
                blue.erase(*blue.begin());
            }
            components -= d.merge((*red.begin()).S,(*blue.begin()).S);
        }
    }
    cout<<components<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T;
    for(long long int i=0;i<T;i++){
        solve();
    }   
}
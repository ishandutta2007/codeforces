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
    int parent[3000]{0};
    int size_of_component[3000]{0};
    void make_set(int i){
        parent[i] = i;
        size_of_component[i] = 1;
    }
    void reset(int _n){
        n = _n;
        for(int i=0;i<=n;i++) make_set(i);
        for(int i=n-30;i<=n;i++){
            size_of_component[i] = 0;
        }
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
    void merge(int u,int v){
        if(is_same_component(u,v)) return;
        u = find_component(u);
        v = find_component(v);
        if(size_of_component[u]<size_of_component[v]) swap(u,v);
        parent[v] = u;
        size_of_component[u]+=size_of_component[v];
    }
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
DSU d(1);
bool check(int n,vector<ll> &arr){
    d.reset(n+30);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<30;j++){
            if(arr[i]&(1<<j)) d.merge(i,n+j);
        }
    }  
    return d.size_of_component[d.find_component(0)] == n;
}
void printArr(vector<ll> &arr){
    for(auto i:arr) cout<<i<<" ";
    cout<<"\n";
}
void pre(){}
void solve(){
    int n;cin>>n;
    vector<ll>arr(n);
    ll ans = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==0){
            ans++;
            arr[i]++;
        }
    }
    if(check(n,arr)){
        cout<<ans+0<<"\n";
        printArr(arr);
        return;
    }
    for(int i=0;i<n;i++){
        arr[i]++;
        if(check(n,arr)){
            cout<<ans+1<<"\n";
            printArr(arr);
            return;
        }
        arr[i]--;
        if(arr[i]>1){
            arr[i]--;
            if(check(n,arr)){
                cout<<ans+1<<"\n";
                printArr(arr);
                return;
            }
            arr[i]++;
        }
    }
    d.reset(n+30);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<30;j++){
            if(arr[i]&(1<<j)) d.merge(i,n+j);
        }
    }  
    int t = __builtin_ctz(arr[0]);
    int index = 0;
    for(int i=1;i<n;i++){
        if(__builtin_ctz(arr[i])>t){
            t = __builtin_ctz(arr[i]);
            index  = i;
        }
    }
    arr[index]--;
    for(int i=0;i<n;i++){
        if(i==index) continue;
        if(d.is_same_component(i,index)){
            arr[i]++;
            break;
        }
    }
    cout<<ans+2<<"\n";
    printArr(arr);
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
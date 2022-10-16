#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
vector<pair<long long int,int>>arr[200001];
int visited[200001]{0};
int parent[200001];
vector<pair<int,pii>>backedge;
void dfs(int i,int from){
    visited[i] = 1;
    parent[i] = from; 
    for(auto to:arr[i]){
        if(to.F==from) continue;
        if(visited[to.F]){
            if(visited[to.F]!=2)
                backedge.push_back({to.S,{to.F,i}});
        }else{
            dfs(to.F,i);
        }
    }
    visited[i] = 2;
}
vector<pair<int,int>>rep;
int formsCycle(){
    if(backedge.size()<3) return false;
    set<int>s;
    map<int,int>m;
    for(auto &i:backedge){
        s.insert(i.S.F);
        s.insert(i.S.S);
        //cout<<i.S.F<<" "<<i.S.S<<"\n";
        m[i.S.F]++;
    }
    if(s.size()>3) return 0;
    int a1,a2,a3;
    for(auto i:m){
        if(i.S==1) a2 = i.F;
        if(i.S==2) a1 = i.F;
    }
    s.erase(a1);
    s.erase(a2);
    a3 = *s.begin();
    int curr = a2;
    int ans = a2;
    // cout<<a1<<" "<<a2<<" "<<a3<<"\n";
    // cout.flush();
    while(curr!=a1){
        ans = curr;
        curr = parent[curr];
    }
    rep = {{a1,a3},{a1,ans}};
    //cout<<a1<<" "<<a3<<" "<<a1<<" "<<ans<<"\n";
    return true;
}
void solve(){
    long long int n,m,u,v;cin>>n>>m;
    for(int i=1;i<=n;i++){
        arr[i].clear();
        visited[i] = 0;
    }
    backedge.clear();
    map<pair<int,int>,int>e;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        e[{u,v}] = i;
        e[{v,u}] = i;
        arr[u].push_back({v,i});
        arr[v].push_back({u,i});
    }
    dfs(1,0);
    vector<int>answer(m);
    for(auto i:backedge){
        answer[i.F] = 1;
    }
    if(formsCycle()){
        answer[e[rep[0]]] = 0;
        answer[e[rep[1]]] = 1;
        //cout<<e[{rep[0].F,rep[0].S}]<<" "<<e[rep[1]]<<"---\n";
    }
    for(auto i:answer) cout<<i;
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
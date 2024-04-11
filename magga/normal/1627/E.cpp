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
// Please write the recurances once :(
map<pii,ll>dp;
map<pii,vector<pair<pii,ll>>>arr;
ll cost[100001];
set<int>poi[100001];
void pre(){}
void resolve(int i){
    map<ll,ll>m;
    for(auto j:poi[i]){
        m[j]=1e18;
        for(auto k:arr[{i,j}]){
            m[j] = min(m[j],dp[k.F]-k.S);
        }
    }
    set<pii>pq;
    for(auto i:m){
        pq.insert({i.S,i.F});
    }
    while(pq.size()>0){
        auto t = *pq.begin();
        pq.erase(t);
        dp[{i,t.S}] = t.F;
        if((*poi[i].begin()) != t.S){
            auto c = poi[i].find(t.S);
            c--;
            auto d= (*c);
            pq.erase({m[d],d});
            m[d] = min(m[d],m[t.S] + abs(t.S-d)*cost[i]);
            pq.insert({m[d],d});
        }
        if((*poi[i].rbegin()) != t.S){
            auto c = poi[i].find(t.S);
            c++;
            auto d= (*c);
            pq.erase({m[d],d});
            m[d] = min(m[d],m[t.S] + abs(t.S-d)*cost[i]);
            pq.insert({m[d],d});
        }
        poi[i].erase(t.S);
    }
}
void solve(){
    int n,m,k,a,b,c,d,h;cin>>n>>m>>k;
    dp.clear();
    arr.clear();
    for(int i=1;i<=n;i++){
        cin>>cost[i];
        poi[i].clear();
    }
    for(int i=0;i<k;i++){
        cin>>a>>b>>c>>d>>h;
        arr[{c,d}].push_back({{a,b},h});
        poi[c].insert(d);
        poi[a].insert(b);
    }
    arr[{1,1}].push_back({{0,0},0});
    poi[1].insert(1);
    poi[n].insert(m);
    dp[{0,0}]=0;
    dp[{n,m}]=1e18;
    for(int i=1;i<=n;i++) resolve(i);
    if(dp[{n,m}]>1e17){
        cout<<"NO ESCAPE"<<"\n";
    }else{
        cout<<dp[{n,m}]<<"\n";
    }
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
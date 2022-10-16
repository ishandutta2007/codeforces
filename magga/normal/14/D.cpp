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
void pre(){}
set<int>arr[201];
bool vis[201]{0};
ll n,u,v;
void ff(){
    for(int i=0;i<201;i++){
        vis[i]=0;
    }
}
pii dfs(int i){
    ff();
    stack<pair<int,int>>s;
    pii fa = {i,0};
    s.push({i,0});
    while(s.size()!=0){
        auto i = s.top();
        s.pop();
        vis[i.first]=1;
        if(i.second>fa.second){
            fa=i;
        }
        for(auto j:arr[i.first]){
            if(!vis[j])
                s.push({j,i.second+1});
        }
    }
    return fa;
}
ll max_dia(int i){
    auto j = dfs(i);
    return dfs(j.first).second; 
}
void solve(){
    cin>>n;
    vector<pair<int,int>>edges;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].insert(v);
        arr[v].insert(u);   
        edges.push_back({u,v});
    }
    ll ans = 0,d;
    for(int i=0;i<n-1;i++){
        arr[edges[i].first].erase(edges[i].second);
        arr[edges[i].second].erase(edges[i].first);
        d = max_dia(edges[i].first)*max_dia(edges[i].second);
        arr[edges[i].first].insert(edges[i].second);
        arr[edges[i].second].insert(edges[i].first);
        ans= max(ans,d);
    }
    cout<<ans<<"\n";
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
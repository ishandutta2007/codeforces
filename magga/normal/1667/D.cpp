#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
vector<vector<int>>g;
vector<pii>edges;
vector<pair<int,int>> dfs(int i,int from){
    int parity = g[i].size()&1;
    vector<vector<pair<int,int>>>evenChildren;
    vector<pii>oddChildren;
    for(auto to:g[i]){
        if(to!=from){
            vector<pair<int,int>> fromChild=dfs(to,i);
            if(fromChild.size() == 0){
                oddChildren.push_back({to,i});
            }else{
                fromChild.push_back({to,i});
                evenChildren.push_back(fromChild);
            }
        }
    }
    //cout<<i<<"\n";
    while( (parity&(oddChildren.size()>0)) || ((!parity)&(evenChildren.size()>0)) ){
        if(parity){
            edges.push_back(oddChildren.back());
            //cout<<edges.back().F<<" "<<edges.back().S<<"\n";
            oddChildren.pop_back();
        }else{
            for(int i=1;i<evenChildren.back().size();i+=2){
                edges.push_back(evenChildren.back()[i]);
                //cout<<edges.back().F<<" "<<edges.back().S<<"\n";
            }
            for(int i=0;i<evenChildren.back().size();i+=2){
                edges.push_back(evenChildren.back()[i]);
                //cout<<edges.back().F<<" "<<edges.back().S<<"\n";
            }
            
            evenChildren.pop_back();
        }
        parity = 1 - parity;
    }
    if(oddChildren.size()==1){
        return {oddChildren[0]};
    }else if(evenChildren.size()==1){
        return {evenChildren[0]};
    }else{
        return {};
    }
}
void solve(){
    int n,u,v;cin>>n;
    edges.clear();
    g.resize(n+1);
    for(int i=0;i<=n;i++) g[i].clear();
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    if(edges.size() != n-1){
        cout<<"NO"<<"\n";
    }else{
        cout<<"YES"<<"\n";
        for(auto i:edges){
            cout<<i.F<<" "<<i.S<<"\n";
        }
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
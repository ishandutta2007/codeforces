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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Graph{
    int n;
    vector<vector<pair<bool,pair<int,long long>>>>edges;
    vector<bool>visited;
    
    Graph(int _n){
        n = _n;
        edges.resize(n+1);
        visited.resize(n+1);
    }

    void add_edge(int u,int v,long long w = 1){
        edges[u].push_back({1,{v,w}});
    }

    void reset_vis(){
        for(int i=0;i<=n;i++) visited[i] = false;
    }

    void reset(int _n){
        n = _n;
        edges.resize(n+1);
        visited.resize(n+1);
        for(int i=0;i<=n;i++)
            edges[i].clear();
        reset_vis();
    }

    void resetEdges(pii flip){
        for(auto &i:edges[flip.F]){
            if(flip.S == i.S.F){
                i.F = !i.F;
            }
        }
        for(auto &i:edges[flip.S]){
            if(flip.F == i.S.F){
                i.F = !i.F;
            }
        }
    }

    vector<int>odd,even;

    vector<pii> bfs(int i){
        odd.clear();
        even.clear();
        queue<long long>q;
        vector<int>parent(n+1);
        vector<long long>a(n+1);
        q.push(i);
        parent[i]=0;
        reset_vis();
        visited[i]=1;
        while(q.size()>0){
            auto i = q.front();
            q.pop();
            if(a[i]&1){
                odd.push_back(i);
            }else{
                even.push_back(i);
            }
            for(auto p:edges[i]){
                if(p.F==false) continue;
                auto j = p.S;
                // cout<<i<<" "<<j.F<<"\n";
                if(!visited[j.F]){
                    q.push(j.F);
                    visited[j.F]=1;
                    parent[j.F]=i;
                    a[j.F] = a[i] + 1;
                }else if(a[j.F]==a[i]){
                    vector<long long>cycle1,cycle2;
                    while(j.F!=i){
                        cycle1.push_back(j.F);
                        cycle2.push_back(i);
                        j.F = parent[j.F];
                        i = parent[i];
                    }
                    reverse(cycle2.begin(),cycle2.end());
                    cycle1.push_back(i);
                    for(auto i:cycle2) cycle1.push_back(i);
                    vector<pii>ret;
                    for(int i=0;i<cycle1.size();i++){
                        ret.push_back({cycle1[i],cycle1[(i+1)%cycle1.size()]});
                    }
                    return ret;
                }
            }
        }
        return {};
    }
};
void pre(){}
void printArr(vector<int>a,int n){
    cout<<"YES"<<"\n";
    vector<int>f(n+1);
    for(auto i:a) f[i]=1;
    for(int i=1;i<=n;i++) cout<<f[i];
    cout<<"\n";
}
vector<pii>smallerCycle(vector<pii>a,vector<pii>b){
    set<pii>s;
    for(auto i:b) s.insert(i);
    vector<pii>ret;
    for(auto i:a){
        if(s.find({i.F,i.S})!=s.end() || s.find({i.S,i.F})!=s.end()){
            ret.push_back(i);
        }
    }
    return ret;
}
void solve(){
    int n,m,u,v;cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g.add_edge(u,v);
        g.add_edge(v,u);
    }
    pii badEdge = {-1,-1};
    auto a = g.bfs(rng()%n + 1);
    while(a.size()!=0){
        badEdge = a[rng()%a.size()];
        g.resetEdges(badEdge);
        auto b = g.bfs(rng()%n + 1);
        if(b.size()==0){
            g.resetEdges(badEdge);
            break;
        }
        a = smallerCycle(a,b);
        g.resetEdges(badEdge);
    }
    if(badEdge.F!=-1) g.resetEdges(badEdge);
    if(g.bfs(rng()%n + 1).size()!=0){
        cout<<"NO"<<"\n";
        return;
    }
    bool isOdd = false;
    for(auto i:g.odd){
        if(i==badEdge.F){
            isOdd=true;
        }
    }
    if(isOdd){
        printArr(g.odd,n);
    }else{
        printArr(g.even,n);
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
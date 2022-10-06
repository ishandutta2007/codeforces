#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
#define  MP make_pair
#define  PB push_back

#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define int long long

map<int,int> zipx;
int unzipx[2000];
ll inf = 1LL<<50;
int compressx(vector<int> &x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    for(int i = 0; i < x.size(); i++){
        zipx[x[i]] = i;
        unzipx[i] = x[i];
    }
    return x.size();
}
map<int,int> zipy;
int unzipy[2000];
int compressy(vector<int> &x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    for(int i = 0; i < x.size(); i++){
        zipy[x[i]] = i;
        unzipy[i] = x[i];
    }
    return x.size();
}

template<typename T> class Dinic {
private:
    struct edge{
        int to;
        T cap;
        int rev;
    };
    int V;
    vector<vector<edge> > G;
    vector<int> level,iter;
    void bfs(int s) {
        fill(level.begin(),level.end(),-1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(auto& e : G[v]){
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    T dfs(int v,int t,T f) {
        if(v==t){
            return f;
        }
        for(int& i = iter[v]; i < (int)G[v].size(); i++){
            edge& e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                T d = dfs(e.to,t,min(f,e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
 
public:
    Dinic(int node_size) : V(node_size), G(V), level(V), iter(V){}
    //
    void add_edge(int from,int to,T cap) {
        G[from].push_back((edge){to,cap,(int)G[to].size()});
        G[to].push_back((edge){from,(T)0,(int)G[from].size()-1});
    }
    //
    T solve(int s,int t) {
        T flow = 0;
        for(;;){
            bfs(s);
            if(level[t] < 0) return flow;
            fill(iter.begin(),iter.end(),0);
            T f;
            while((f=dfs(s,t,numeric_limits<T>::max())) > 0){
                flow += f;
            }
        }
    }
};
signed main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int> > a;
    vector<pair<int,int> > b;
    vector<int>x;
    vector<int>y;
    rep(i,m){
        int p,q,r,s;
        cin >> p >> q >> r >> s;
        a.push_back(MP(p,q));
        b.push_back(MP(r+1,s+1));
        x.push_back(p);
        y.push_back(q);
        x.push_back(r+1);
        y.push_back(s+1);
    }
    int s = compressx(x);
    int t = compressy(y);
    vector<vector<bool> > f(s+10,vector<bool>(t+10));
    rep(i,m){
        for(int j=zipx[a[i].first];j<zipx[b[i].first];j++){
            
            for(int k=zipy[a[i].second];k<zipy[b[i].second];k++){
                f[j][k] = 1;
            }
        }
    }
    Dinic<ll> dn(s+t+2);
    int S = s+t;
    int T = s+t+1;
    rep(i,s-1){
        // cerr << unzipx[i] << endl;
        // cerr << i << " " << unzipx[i+1]-unzipx[i] << endl;
        dn.add_edge(S,i,unzipx[i+1]-unzipx[i]);
    }
    rep(j,t-1){
        dn.add_edge(s+j,T,unzipy[j+1]-unzipy[j]);
    }
    rep(i,s){
        rep(j,t){
            if(f[i][j]){
                //cerr << i << " " << j << " " << unzipx[i+1]-unzipx[i] << " " <<unzipy[j+1]-unzipy[j] << endl;
                dn.add_edge(i,s+j,inf);
            }
        }
    }
    cout << dn.solve(S,T) << endl;
    return 0;
}
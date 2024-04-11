#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}

template<typename T> class Dinic {
private:
    int V;
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
    struct edge{
        int to;
        T cap;
        int rev;
    };
    vector<vector<edge> > G;
 
    Dinic(int node_size) : V(node_size), level(V), iter(V), G(V){}
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
int main(){
    int n,m,x;
    cin >> n >> m >> x;
    vector<pair<pair<int,int>,double> > g;
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        g.push_back(MP(MP(a,b),c));
    }
    double ok = 0.0;
    double ng = 1e12;
    rep(i,100){
        double mid = (ok+ng)/2;
        Dinic<double> dc(n);
        for(auto x:g){
            int from = x.first.first;
            int to = x.first.second;
            double cap = floor(x.second/mid);
            dc.add_edge(from,to,cap);
        }
        double res = dc.solve(0,n-1);
        if(res>=x){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << fixed << setprecision(30) <<  ok*x << endl;
    return 0;
}
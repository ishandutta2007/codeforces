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
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define int long long
class BM {
private:
    struct edge {
        int to,cap,rev;
    };
    int U,V;
    vector<vector<edge> > G;
    vector<int> level;
    vector<int> iter;

public:
    BM(int u,int v) : U(u), V(v), G(U+V+2){
        for(int i = 0; i < U; i++){
            init_edge(0,i+1);
        }
        for(int i = 0; i < V; i++){
            init_edge(U+i+1,U+V+1);
        }
    }
    void init_edge(int from,int to) {
        G[from].push_back((edge){to,1,(int)G[to].size()});
    	G[to].push_back((edge){from,0,(int)G[from].size()-1});
    }
    void add_edge(int from,int to) {
        from += 1,to += U+1;
    	G[from].push_back((edge){to,1,(int)G[to].size()});
    	G[to].push_back((edge){from,0,(int)G[from].size()-1});
    }
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
    int dfs(int v,int t,int f) {
        if(v==t){
            return f;
        }
        for(int &i = iter[v];i<(int)G[v].size();i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                int d = dfs(e.to,t,min(f,e.cap));
                if(d>0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    int solve() {
        level.resize(U+V+2), iter.resize(U+V+2);
        int flow = 0;
        int s=0,t=U+V+1;
        for(;;){
            bfs(s);
            if(level[t] < 0) return flow;
            fill(iter.begin(),iter.end(),0);
            int f;
            while((f=dfs(s,t,numeric_limits<int>::max())) > 0){
                flow += f;
            }
        }
    }
    vector<int> allocate() {
        vector<int> res(U, -1);
        for(int i = 0; i < U; i++){
            for(auto& e : G[i+1]){
                if(e.cap == 0 && e.to != 0){
                    res[i] = e.to-U-1;
                    break;
                }
            }
        }
        return res;
    }
};


struct A{
    int x;
    int a;
    int f;
};
struct B{
    int x;
    int d;  
};

signed main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > dst(n+1,vector<int>(n+1,inf));
    rep(i,n+1){
        dst[i][i] = 0;
    }
    rep(i,m){
        int a,b;
        cin >> a >> b;
        dst[a][b] =min(dst[a][b],1LL);
        dst[b][a] =dst[a][b];
    }
    rep(k,n+1){
        rep(i,n+1){
            rep(j,n+1){
                dst[i][j] = min(dst[i][j],dst[i][k]+dst[k][j]);
            }
        }
    }
    int s,b,k,h;
    cin >> s >> b >> k >> h;
    vector<A> p(s);
    vector<B> q(b);
    rep(i,s){
        int x,a,f; 
        cin >> x >> a >> f;
        p[i].x = x;
        p[i].a = a;
        p[i].f = f;
    }
    rep(i,b){
        int x,d;
        cin >> x >> d;
        q[i].x = x;
        q[i].d = d;
    }
    BM bm(s,b);
    rep(i,s){
        rep(j,b){
            if(p[i].a>=q[j].d&&p[i].f>=dst[p[i].x][q[j].x]){
                bm.add_edge(i,j);
            }
        }
    }
    int sm =  bm.solve();
    cout << min((ll)h*(ll)s,(ll)sm*(ll)k) << endl;
    return 0;
}
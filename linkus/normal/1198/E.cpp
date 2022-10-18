#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define whatis(x) cerr << #x << " is " << (x) << endl;
#define e1 first
#define e2 second
#define INF 0x7f7f7f7f
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000001

template <typename T>
class flow_graph {
 public:
  static constexpr T eps = (T) 1e-9;
 
  struct edge {
    int from;
    int to;
    T c;
    T f;
  };
 
  vector<vector<int>> g;
  vector<edge> edges;
  int n;
  int st;
  int fin;
  T flow;
 
  flow_graph(int _n, int _st, int _fin) : n(_n), st(_st), fin(_fin) {
    assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);
    g.resize(n);
    flow = 0;
  }
 
  void clear_flow() {
    for (const edge &e : edges) {
      e.f = 0;
    }
    flow = 0;
  }
   
  int add(int from, int to, T forward_cap, T backward_cap) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, forward_cap, 0});
    g[to].push_back(id + 1);
    edges.push_back({to, from, backward_cap, 0});
    return id;
  }
};
 
template <typename T>
class dinic {
 public:
  flow_graph<T> &g;
 
  vector<int> ptr;
  vector<int> d;
  vector<int> q;
 
  dinic(flow_graph<T> &_g) : g(_g) {
    ptr.resize(g.n);
    d.resize(g.n);
    q.resize(g.n);
  }
 
  bool expath() {
    fill(d.begin(), d.end(), -1);
    q[0] = g.fin;
    d[g.fin] = 0;
    int beg = 0, end = 1;
    while (beg < end) {
      int i = q[beg++];
      for (int id : g.g[i]) {
        const auto &e = g.edges[id];
        const auto &back = g.edges[id ^ 1];
        if (back.c - back.f > g.eps && d[e.to] == -1) {
          d[e.to] = d[i] + 1;
          if (e.to == g.st) {
            return true;
          }
          q[end++] = e.to;
        }
      }
    }
    return false;
  }
   
  T dfs(int v, T w) {
    if (v == g.fin) {
      return w;
    }
    int &j = ptr[v];
    while (j >= 0) {
      int id = g.g[v][j];
      const auto &e = g.edges[id];
      if (e.c - e.f > g.eps && d[e.to] == d[v] - 1) {
        T t = dfs(e.to, min(e.c - e.f, w));
        if (t > g.eps) {
          g.edges[id].f += t;
          g.edges[id ^ 1].f -= t;
          return t;
        }
      }
      j--;
    }
    return 0;
  }
 
  T max_flow() {
    while (expath()) {
      for (int i = 0; i < g.n; i++) {
        ptr[i] = (int) g.g[i].size() - 1;
      }
      T big_add = 0;
      while (true) {
        T add = dfs(g.st, numeric_limits<T>::max());
        if (add <= g.eps) {
          break;
        }
        big_add += add;
      }
      if (big_add <= g.eps) {
        break;
      }
      g.flow += big_add;
    }
    return g.flow;
  }
 
  vector<bool> min_cut() {
    max_flow();
    vector<bool> ret(g.n);
    for (int i = 0; i < g.n; i++) {
      ret[i] = (d[i] != -1);
    }
    return ret;
  }
};

#define MAX 1000

int res[MAX][MAX];
int p[MAX]; //prev node
int s,t; //source, sink
int f;

void augment(int cur, int mnedge){
    if(cur == s){
        f = mnedge;
        return;
    }
    if(p[cur] != -1){
        augment(p[cur], min(mnedge, res[p[cur]][cur]));
        res[p[cur]][cur] -= f;
        res[cur][p[cur]] += f;
    }
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int nn,mm;
    sc(nn,mm);
    int in[mm][4];
    vi xs = {0,nn},ys = {0,nn};
    FORR(i,in){
        FORR(x,i){
            sc(x);
        }
        --i[0];
        --i[1];
        xs.pb(i[0]);
        xs.pb(i[2]);
        ys.pb(i[1]);
        ys.pb(i[3]);
    }
    sort(all(xs));
    sort(all(ys));
    xs.erase(unique(all(xs)),xs.end());
    ys.erase(unique(all(ys)),ys.end());
    int xsz = xs.size()-1;
    int ysz = ys.size()-1;
    flow_graph<ll> g(xsz+ysz+2,xsz+ysz,xsz+ysz+1);
    int nd = xsz+ysz;
    s = nd;
    t = nd+1;
    vector<int> adj[nd+2]; //res list for quicker bfs
    FOR(i,0,xsz){
        res[s][i] = xs[i+1]-xs[i];
        adj[s].pb(i);
        adj[i].pb(s);
        /* g.add(s,i,xs[i+1]-xs[i],0); */
    }
    FOR(i,0,ysz){
        res[xsz+i][t] = ys[i+1]-ys[i];
        adj[t].pb(xsz+i);
        adj[xsz+i].pb(t);
        /* g.add(xsz+i,t,ys[i+1]-ys[i],0); */
    }
    /* whatis(xs) */
    /* whatis(ys) */
    FOR(i,0,xsz){
        FOR(x,0,ysz){
            FOR(k,0,mm){
                /* whatis(in[k][0]) */
                /* whatis(xs[i]) */
                /* whatis(xs[i]) */
                /* whatis(in[k][0]) */
                if(in[k][0] <= xs[i] && xs[i+1] <= in[k][2] && in[k][1] <= ys[x] && ys[x+1] <= in[k][3]){
                    res[i][xsz+x] = INF;
                    adj[i].pb(xsz+x);
                    adj[xsz+x].pb(i);
                    /* whatis(i) */
                    /* whatis(x) */
                    /* g.add(i,xsz+x,INF,0); */
                    break;
                }
            }
        }
    }
    /* s = */
    /* sc(n,m); */
    /* int fir,sec,val; */
    /* while(m--){ */
    /*     sc(fir,sec,val); //first -> second (weight) */
    /*     res[fir][sec] = res[sec][fir] = val; //undirected */
    /*     //res[fir][sec] = val; //if directed */
    /*     adj[fir].push_back(sec); // most be both irregardles, because */
    /*     adj[sec].push_back(fir); // of back edges */
    /* } */
    /* sc(s,t); //source,sink */
    int mf = 0; //max flow
    int sz = nd+2;
    bool vis[sz]; //visited;
    LOOP:
        f = 0; //next flow candidate
        memset(p,-1,nd << 2);
        memset(vis,0,sizeof vis);
        vis[s] = 1;
        queue<int> qu({s});
        while(!qu.empty()){
            int cur = qu.front(); qu.pop();
            if(cur == t)
                break;
            for(auto const &i: adj[cur]){
                if(res[cur][i] > 0 && !vis[i]){
                    vis[i] = 1; qu.push(i); p[i] = cur;
                }
            }
        }
        augment(t, 0x7f7f7f7f);
        if(f){ //after f == 0, no more possible flow, terminate
            mf += f;
            goto LOOP;
        }
    cout << mf << '\n';
    /* dinic<ll> d(g); */
    /* cout << d.max_flow() << '\n'; */
}
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
template <typename CT, typename T> inline void reset_container(CT &c, int sz, T v){c.resize(sz); for(auto &x: c) x=v;}
#define taskname "B3"
int n, m;
int c[101][101];
int s, b, k;
vector <int> ship_at[101];
vector <int> base_at[101];
class ship{
public:
    int x, a, f, p;
    void input(int id){
        read(x);
        read(a);
        read(f);
        read(p);
        ship_at[x].pb(id);
    }
} S[100001];
class base{
public:
    int x, d, g;
    void input(int id){
        read(x);
        read(d);
        read(g);
        base_at[x].pb(id);
    }
} B[100001];
int r[100001];
vector <int> g[100001];
vector <int> cc[100001];
int root(int u){
    if(r[u]<0) return u;
    return r[u]=root(r[u]);
}
void unite(int u, int v){
    u=root(u);
    v=root(v);
    if(u==v) return;
    if(r[u]>r[v]) swap(u, v);
    r[u]+=r[v];
    r[v]=u;
}
ll p[100001];
class maxflow{
public:
    class edge{
    public:
        using pointer=edge*;
        int v;
        ll c;
        pointer rev;
        edge(int v, ll c){
            this->v=v;
            this->c=c;
        }
    };
    vector <edge::pointer> g[100002];
    void reset(){
//        for(int u: vertices) g[u].clear();
        g[0].clear();
        g[100001].clear();
        flow=0;
    }
//    void reset(vector <int> &vertices){
//        for(int u: vertices) g[u].clear();
//        g[0].clear();
//        g[100001].clear();
//        flow=0;
//    }
    void add_edge(int u, int v, ll c){
        g[u].pb(new edge(v, c));
        g[v].pb(new edge(u, 0));
        g[u].back()->rev=g[v].back();
        g[v].back()->rev=g[u].back();
    }
    edge::pointer trace[100002];
    int done[100002];
    int t;
    bool bfs(){
        t++;
        queue <int> q;
        q.push(0);
        done[0]=t;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto e: g[u]) if(e->c) if(done[e->v]!=t){
                done[e->v]=t;
                q.push(e->v);
                trace[e->v]=e;
                if(e->v==100001) return 1;
            }
        }
        return 0;
    }
    ll flow;
    void increase_flow(){
        int u=100001;
        ll f=1e18;
        while(u){
            f=min(f, trace[u]->c);
            u=trace[u]->rev->v;
        }
        flow+=f;
        u=100001;
        while(u){
            trace[u]->c-=f;
            trace[u]->rev->c+=f;
            u=trace[u]->rev->v;
        }
    }
    ll get_flow(){
        while(bfs()) increase_flow();
        return flow;
    }
} MF;
ll get_profit(int i){
    MF.reset();
    ll prof=0;
    for(int u: cc[i]){
        if(p[u]>=0){
            prof+=p[u];
            MF.add_edge(0, u, p[u]);
        }
        else{
//            prof-=p[u];
            MF.add_edge(u, 100001, -p[u]);
        }
        for(int v: g[u]) MF.add_edge(u, v, 1e15);
    }
    ll flow=MF.get_flow();
    prof-=flow;
    return max(0LL, prof);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    FOR(i, 1, n) FOR(j, 1, n) if(i!=j) c[i][j]=(1e9)+420;
    FOR(i, 1, m){
        int u, v;
        read(u);
        read(v);
        if(u!=v) c[u][v]=c[v][u]=1;
    }
    FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) c[i][j]=min(c[i][j], c[i][k]+c[k][j]);
    read(s);
    read(b);
    read(k);
    FOR(i, 1, s) S[i].input(i);
    FOR(i, 1, b) B[i].input(i);
    FOR(i, 1, s) r[i]=-1;
    FOR(i, 1, k){
        int u, v;
        read(u);
        read(v);
        g[u].pb(v);
        unite(u, v);
    }
    FOR(i, 1, n){
        sort(base_at[i].begin(), base_at[i].end(), [](int X, int Y){
            return B[X].d<B[Y].d;
        });
        FFOR(j, 1, base_at[i].size()) B[base_at[i][j]].g=max(B[base_at[i][j]].g, B[base_at[i][j-1]].g);
    }
    FOR(i, 1, s){
        ll prof=-1e15;
        FOR(v, 1, n) if(c[v][S[i].x]<=S[i].f){
            int low=0, high=((int)base_at[v].size())-1, mid, res=-1;
            while(low<=high){
                mid=(low+high)/2;
                if(B[base_at[v][mid]].d<=S[i].a){
                    res=mid;
                    low=mid+1;
                }
                else high=mid-1;
            }
            if(res!=-1) prof=max(prof, (ll)(B[base_at[v][res]].g-S[i].p));
        }
        p[i]=prof;
    }
    ll res=0;
//    FOR(i, 1, s) cerr<<p[i]<<" \n"[i==s];
    FOR(i, 1, s) cc[root(i)].pb(i);
    FOR(i, 1, s) if(i==root(i)) res+=get_profit(i);
    writeln(res);
}
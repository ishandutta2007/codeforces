#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define sar(a,n) {cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl;}

using namespace std;

template<typename S,typename T>auto&operator<<(ostream&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(ostream&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(ostream&o,map<K,T>&m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(ostream&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}
template<typename S,typename T,typename U>
struct TRI{S fi;T se;U th;TRI(){}TRI(S f,T s,U t):fi(f),se(s),th(t){}
bool operator<(const TRI&_)const{return(fi==_.fi)?((se==_.se)?(th<_.th):(se<_.se)):(fi<_.fi);}};
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,TRI<S,T,U>&t){return o<<"{"<<t.fi<<","<<t.se<<","<<t.th<<"}";}

typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef TRI<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<string> vs;

const int MAX_N = 200005;

class FunctionalGraph {
public:
    int V;
    vector<int> nx,visit;
    vector<vector<int> > loop;
    vector<vector<int> > G;
    vector<int> st;
    FunctionalGraph(int node_size)  : V(node_size), nx(V, 0), visit(V, 0){}
    void add_edge(int u,int v){
        nx[u] = v;
        if(nx[u] == u) visit[u] = -1, loop.push_back({u});
    }
    void make_loop(const int st,int nw,int ch,vector<int>& vec){
        while(nx[nw] != st){
            vec.push_back(nx[nw]);
            visit[nx[nw]] = ch;
            nw = nx[nw];
        }
    }
    void dfs(int u,int kind,vector<int>& vec){
        visit[u] = kind;
        int v = nx[u];
        if(visit[v] == kind){
            vec.push_back(u),vec.push_back(v);
            int ch = (int)(loop.size()) + 1;
            visit[u] = visit[v] = -ch;
            make_loop(u,v,-ch,vec);
        }else if(visit[v] == 0){
            dfs(v,kind,vec);
        }
    }
    void solve(){
        int id = 1;
        for(int i = 0; i < V; i++){
            if(visit[i] == 0){
                vector<int> vec;
                dfs(i,id++,vec);
                if((int)vec.size()){
                    loop.push_back(vec);
                }
            }
        }
        make_graph();
    }
    void make_graph(){
        G.resize(V);
        vector<bool> flag(V,false);
        for(int i = 0; i < V; i++){
            if(visit[i] >= 0){
                G[nx[i]].push_back(i);
                flag[nx[i]] = (visit[nx[i]] < 0);
            }
        }
        for(int i = 0; i < V; i++){
            if(flag[i]){
                st.push_back(i);
            }
        }
    }
};

void memo_dfs(int u, int d, vector<int>& wa, auto& G){
    wa.push_back(d);
    for(int v : G[u]){
        memo_dfs(v, d+1, wa, G);
    }
}

// (, )
vector<P> query[MAX_N];
deque<int> dp[MAX_N];

void solve_dfs(int u, vector<int>& ans, auto& G)
{
    for(int v : G[u]){
        solve_dfs(v, ans, G);
        if(len(dp[u]) < len(dp[v])){
            rep(i, len(dp[u])){
                dp[v][i] += dp[u][i];
            }
            swap(dp[u], dp[v]);
        }else{
            rep(i, len(dp[v])){
                dp[u][i] += dp[v][i];
            }
        }
    }
    dp[u].push_front(1);
    for(P p : query[u]){
        if(len(dp[u]) > p.se){
            ans[p.fi] = dp[u][p.se];
        }
    }
}

// (, )
P pos[MAX_N];
// (, id)
vector<vector<vector<P> > > memo;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    FunctionalGraph fg(n);
    rep(i,n){
        int a;
        cin >> a;
        fg.add_edge(i, a-1);
    }
    fg.solve();
    auto& G = fg.G;
    auto& loop = fg.loop;
    auto& visit = fg.visit;
    // show(visit);
    // show(loop);
    // rep(i,n){
        // show(G[i]);
    // }
    rep(i,len(loop)){
        rep(j, len(loop[i])){
            pos[loop[i][j]] = {i, j};
        }
        memo.push_back(vector<vector<P> >(len(loop[i])));
    }
    rep(i,n){
        vector<int> vec;
        if(visit[i] < 0){
            memo_dfs(i, 0, vec, G);
            // show(i);
            // show(vec);
            const int loop_num = pos[i].fi;
            for(int v : vec){
                const int val = v + len(loop[loop_num]) - pos[i].se;
                memo[loop_num][val % len(loop[loop_num])].emplace_back(val, pos[i].se);
            }
        }
    }
    rep(i,len(loop)){
        // show(i);
        rep(j,len(loop[i])){
            sort(all(memo[i][j]));
            // show(memo[i][j]);
        }
    }
    int q;
    cin >> q;
    vector<int> ans(q, 0);
    rep(i, q){
        ll m;
        int y;
        cin >> m >> y;
        --y;
        if(visit[y] >= 0){
            if(m >= n){
                ans[i] = 0;
            }else{
                query[y].emplace_back(i, m);
            }
            continue;
        }
        const int loop_num = pos[y].fi;
        ll val = m + len(loop[loop_num]) - pos[y].se;
        auto& tar = memo[loop_num][val % len(loop[loop_num])];
        cmn(val, (ll)2*n);
        // show(val % len(loop[loop_num]));
        // show(val);
        ans[i] = upper_bound(all(tar), P(val, pos[y].se)) - tar.begin();
    }
    rep(i, n){
        if(visit[i] < 0){
            solve_dfs(i, ans, G);
        }
    }
    rep(i, q){
        cout << ans[i] << "\n";
    }
    return 0;
}
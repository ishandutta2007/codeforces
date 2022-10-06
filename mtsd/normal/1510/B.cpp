#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

template<typename CapType, typename CostType> class MinCostFlowDAG {
public:
    using Cat = CapType;
    using Cot = CostType;
    using pti = pair<Cot, int>;
    struct edge {
        int to, rev;
        Cat cap;
        Cot cost;
        bool flag;
    };
    const int V;
    const Cot inf;
    vector<vector<int> > ans;
    vector<vector<edge> > G;
    vector<Cot> h, dist;
    vector<int> deg, ord, prevv, preve;
    MinCostFlowDAG(const int node_size) : V(node_size), inf(numeric_limits<Cot>::max()),
        G(V), h(V, inf), dist(V), deg(V, 0), prevv(V), preve(V){}
    void add_edge(const int from, const int to, const Cat cap, const Cot cost){
        // cerr << from << " " << to << " " << cap << " " << cost << endl;
        if(cap == 0) return;
        G[from].push_back((edge){to, (int)G[to].size(), cap, cost,0});
        G[to].push_back((edge){from, (int)G[from].size() - 1, 0, -cost,1});
        ++deg[to];
    }
    bool tsort(){
        queue<int> que;
        for(int i = 0; i < V; ++i){
            if(deg[i] == 0) que.push(i);
        }
        while(!que.empty()){
            const int p = que.front();
            que.pop();
            ord.push_back(p);
            for(auto& e : G[p]){
                if(e.cap > 0 && --deg[e.to] == 0) que.push(e.to);
            }
        }
        return (*max_element(deg.begin(), deg.end()) == 0);
    }
    void calc_potential(const int s){
        h[s] = 0;
        for(const int v : ord){
            if(h[v] == inf) continue;
            for(const edge& e : G[v]){
                if(e.cap > 0) h[e.to] = min(h[e.to], h[v] + e.cost);
            }
        }
    }
    void Dijkstra(const int s){
        priority_queue<pti,vector<pti>,greater<pti> > que;
        fill(dist.begin(), dist.end(), inf);
        dist[s] = 0;
        que.push(pti(0, s));
        while(!que.empty()){
            pti p = que.top();
            que.pop();
            const int v = p.second;
            if(dist[v] < p.first) continue;
            for(int i = 0; i < (int)G[v].size(); ++i){
                edge& e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v, preve[e.to] = i;
                    que.push(pti(dist[e.to], e.to));
                }
            }
        }
    }
    bool update(const int s, const int t, Cat& f, Cot& res){
        for(int i = 0; i < V; i++){
            if(dist[i] != inf) h[i] += dist[i];
        }
        Cat d = f;
        for(int v = t; v != s; v = prevv[v]){
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        if(h[t]*d >= 0 )return false;
        res += h[t] * d;
        vector<int> tmp;
        for(int v = t; v != s; v = prevv[v]){
            edge& e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
        return true;
    }
    void build(int id){
        int t = id;
        vector<int> tmp;
        while(1){
            id = t;
            bool ff = 0;
            for(auto& e:G[id]){
                if(e.flag && e.cap > 0){
                    ff = 1;
                }
            }
            if(!ff)break;
            while(id!=0){
                // cerr << id << endl;
                for(auto& e:G[id]){
                    if(e.flag && e.cap > 0){
                        e.cap--;
                        id = e.to;
                        break;
                    }
                }   
                tmp.push_back(id);
            }
            reverse(tmp.begin(),tmp.end());
            ans.push_back(tmp);
            tmp.clear();
        }
    }
    Cot solve(const int s, const int t, Cat f){
        if(!tsort()) assert(false); // not DAG
        calc_potential(s);
        Cot res = 0;
        while(f > 0){
            Dijkstra(s);
            if(dist[t] == inf)break;
            if(!update(s, t, f, res))break;
        }
        build(t);
        return res;
    }
};

int main(){
    int d,n;
    cin >> d >> n;
    vector<string> s(n);
    vector<int> a(n);
    rep(i,n)cin >> s[i];
    rep(i,n){
        int k = 0;
        rep(j,d){
            if(s[i][j]=='1'){
                k ^= (1<<j);
            }
        }
        a[i] = k;
    }
    int N = (1<<d) + n + 1;
    int D = (1<<d);
    int S = 0;
    int T = N-1;
    MinCostFlowDAG<ll,ll> mcf(N);
    rep(i,1<<d){
        int id = -1;
        rep(k,n){
            if(i==a[k]){
                id = D+k;
                mcf.add_edge(i,D+k,1,-(1LL<<50));
                mcf.add_edge(D+k,T,1,0);
            }
        }
        rep(j,d){
            if((i>>j)&1){

            }else{
                mcf.add_edge(i,i^(1<<j),100000,1);
                if(id!=-1){
                    mcf.add_edge(id,i^(1<<j),100000,1);
                }
            }
        }
    }   
    mcf.solve(S,T,1000000);
    auto ans = mcf.ans;
    vector<char> res;
    for(auto v:ans){
        // rep(i,v.size()){
        //     cerr << v[i] << " ";
        // }
        // cerr << endl;
        rep(i,v.size()-1){
            if(v[i] >= D){
                v[i] = a[v[i]-D];
            }
            rep(j,d){

                if(v[i+1] == (v[i]^(1<<j)) ){
                    res.push_back('0'+j);
                }
            }
        }
        // rep(i,v.size()){
        //     cerr << v[i] << " ";
        // }
        // cerr << endl;
        res.push_back('R');
    }
    res.pop_back();
    cout << res.size() << endl;
    rep(i,res.size()){
        cout << res[i];
        if(i!=res.size()-1)cout << " ";
    }
    cout << endl;
    return 0;
}
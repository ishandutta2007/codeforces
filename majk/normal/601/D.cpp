#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned int ui;
ui logceil(int x) { return 8*sizeof(int)-__builtin_clz(x); }

template<typename T> struct Fenwick {
    explicit Fenwick(ui N=0, T t=T()):N(1u<<logceil(N)),F(this->N,t),t(t){}
    explicit Fenwick(const vector<T>&A, T t=T()):N(1u<<logceil(A.size())),F(A),t(t){
        F.resize(N); fill(F.begin()+A.size(),F.end(),t);
        for(int i=0;i<N;i++){int j=i+lsb(i+1);if(j<N)F[j]+=F[i];}}
    void add(int i, T v){while(i<=N){F[i]+=v;i+=lsb(i+1);}}
    T sum(int i)const{T sum(t);while(i){sum+=F[i-1];i-=lsb(i);}return sum;}
    T range(int i,int j)const{j++; T s(t);while(j>i){s+=F[j-1];j-=lsb(j);}while(i>j){s-=F[i-1];i-=lsb(i);}return s;}
    T get(int i)const{return range(i,i);}
    void set(int i, T v) {add(i, v-get(i)); }
    constexpr int lsb(int i)const{return i&-i;}
    ui N;vector<T> F;T t;
};

int N, T;
vector<vector<int>> E;
string S;
vector<int> Enter, Exit, P;

void dfs(int u, int p) {
    P[u] = p;
    Enter[u] = T++;
    for (int v:E[u]) if (v!=p) dfs(v, u);
    Exit[Enter[u]] = T;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    vector<int> C(N); for (int&c:C) cin >> c;
    cin >> S;
    P.resize(N);
    E.resize(N); Enter.resize(N); Exit.resize(N);
    for (int i = 0; i < N-1; ++i) {
        int u,v; cin >> u >> v;
        --u; --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    T = 0;
    dfs(0, -1);
    vector<int> CC(N);
    for (int i = 0; i < N; ++i) CC[Enter[i]] = C[i];
    vector<vector<int>> G{{0}};
    for (int g = 0; g < G.size(); ++g) {
        vector<vector<int>> W(26);
        for (int u : G[g]) {
            for (int v : E[u]) {
                if (v != P[u]) W[S[v]-'a'].push_back(v);
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (!W[i].empty()) G.push_back(W[i]);
        }
    }

    vector<int> Prev(N,-1), Next(N,N);
    Fenwick<int> T(N+1, 0);
    for (auto&g:G) {
        for (auto&r:g) r = Enter[r]; 
        sort(g.begin(),g.end());
        for (int i = 0; i < g.size()-1; ++i) {
            Prev[g[i+1]] = g[i];
            Next[g[i]] = g[i+1];
        }
        T.add(g[0], 1);
    }


    int mx = -1, cnt = 0;
    for (int i = 0; i < N; ++i) {
        int cur = T.range(i, Exit[i]-1) + CC[i];
        if (cur > mx) { mx = cur; cnt = 1; }
        else if (cur == mx) { ++cnt; }
        T.add(Next[i], 1);
    }

    cout << mx << endl;
    cout << cnt << endl;
}
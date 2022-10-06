#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define inf 1000000007
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define rrep(i,n) for(int i = (int)n-1; i >= 0; --i)
#define srep(i,a,b) for(int i = (int)a; i < (int)(b); ++i)
#define all(x) (x).begin(),(x).end()
#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
#define SZ(c) (int)(c).size()
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
    os << "{";
    for (int i = 0; i<(int)vec.size(); i++) {
        os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// pair
template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U> pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// map
template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
    os << "{";
    for(auto itr = map_var.begin(); itr != map_var.end(); itr++){
        os << "(" << itr->first << ", " << itr->second << ")";
        itr++;
        if(itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set 
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
    os << "{";
    for(auto itr = set_var.begin(); itr != set_var.end(); itr++){
        os << (*itr);
        ++itr;
        if(itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// tuple 
template<int N,class Tuple>
void out(ostream &os,const Tuple &t){}
template<int N,class Tuple,class H,class ...Ts>
void out(ostream &os,const Tuple &t){
    if(N)os<<", ";
    os<<get<N>(t);
    out<N+1,Tuple,Ts...>(os,t);
}
template<class ...Ts>
ostream& operator<<(ostream &os, const tuple<Ts...> &t){
    os<<"(";
    out<0,tuple<Ts...>,Ts...>(os,t);
    os<<")";
    return os;
}
#define overload2(_1, _2, name, ...) name
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define INT(...)                                                                                                                                               \
    int __VA_ARGS__;                                                                                                                                           \
    IN(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
    ll __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
#define STR(...)                                                                                                                                               \
    string __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define CHR(...)                                                                                                                                               \
    char __VA_ARGS__;                                                                                                                                          \
    IN(__VA_ARGS__)
#define DBL(...)                                                                                                                                               \
    double __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
    scan(head);
    IN(tail...);
}
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define dbg(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define dbg(...) (void(0))
#define dump(x) (void(0))
#endif
template<typename A, typename T>
std::enable_if_t<std::is_convertible<T, A>::value> fill(A& array, const T& val)
{
    array = val;
}
template<typename A, typename T>
std::enable_if_t<!std::is_convertible<T, A>::value> fill(A& array, const T& val)
{
    for (auto& a : array) {
        fill(a, val);
    }
}
template <typename T, typename S> T ceil(T x, S y) {
    assert(y);
    return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y));
}
template <typename T, typename S> T floor(T x, S y) {
    assert(y);
    return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0 : 1)));
}
vector<int> iota(int n) {vector<int> a(n);iota(all(a), 0);return a;}
template <class T> T POW(T x, int n) {T res = 1;for(; n; n >>= 1, x *= x){if(n & 1) res *= x;}return res;}
ll pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
// int allbit(int n) { return (1 << n) - 1; }
ll allbit(ll n) { return (1LL << n) - 1; }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }


template <class S> void fold_in(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void fold_in(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto e : a) v.emplace_back(e);
    fold_in(v, tail...);
}
template <class S> void renumber(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void renumber(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto &&e : a) e = lb(v, e);
    renumber(v, tail...);
}
template <class S, class... Args> void zip(vector<S> &head, Args &&...args) {
    vector<S> v;
    fold_in(v, head, args...);
    sort(all(v)), v.erase(unique(all(v)), v.end());
    renumber(v, head, args...);
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
class EulerPath
{
private:
    struct edge {
        int to;
        list<edge>::const_iterator rev;
        edge(int to_) : to(to_){}
    };
public:
    int V;
    list<edge>* G;
    vector<int> ans;
    EulerPath(int node_size) : V(node_size){ G = new list<edge>[V]; }
    void add_edge(int u, int v){
        G[u].push_back((edge){v}); list<edge>::const_iterator revu = (--G[u].end());
        G[v].push_back((edge){u}); list<edge>::const_iterator revv = (--G[v].end());
        G[u].back().rev = revv, G[v].back().rev = revu;
    }
    int judge(){
        int s = -1, odd = 0;
        for(int i = 0; i < V; i++){
            if((int)G[i].size() % 2){
                if(++odd >= 3) return -1;
                s = i;
            }
        }
        return max(s, 0);
    }
    bool solve(){
        int cur = judge();
        if(V == 0 || cur < 0) return false;
        stack<int> cur_path;
        cur_path.push(cur);
        while(!cur_path.empty()){
            if(!G[cur].empty()){
                cur_path.push(cur);
                auto nx = G[cur].back();
                G[cur].pop_back(), G[nx.to].erase(nx.rev);
                cur = nx.to;
            }else{
                ans.push_back(cur);
                cur = cur_path.top(), cur_path.pop();
            }
        }
        return true;
    }
};
class UnionFind {
private:
    int sz;
    vector<int> par, size_;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), size_(sz, 1){
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(size_[x] < size_[y]) swap(x,y);
        par[y] = x;
        size_[x] += size_[y];
    }
    int size(int x){
        x = find(x);
        return size_[x];
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};
int ans[2][400000];
char res1[2][400000];
char res2[2][400000];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    INT(n);
    UnionFind uf(2*n+2);
    vector<int> d(2*n+2);
    vector<pair<int,int> > p;
    rep(i,n){
        INT(a,b);
        uf.unite(a,b);
        d[a]++;
        d[b]++;
        p.push_back({a,b});
    }
    map<int,vector<int> > mp;
    for(int i=1;i<=2*n;i++){
        if(d[i]==0)continue;
        mp[uf.find(i)].push_back(i);
    }
    map<int,vector<pair<int,int> > >edge;
    for(auto [x,y]:p){
        edge[uf.find(x)].push_back({x,y});
    }
    int T = 0;
    for(auto& [cc,v]:mp){
        map<int,int> inv;
        rep(i,v.size()){
            inv[v[i]] = i;
        }
        if(edge[cc].size()==1){
            cout << -1 << endl;
            return 0;
        }
        int m = v.size();
        vv(int,g,m);
        for(auto [x,y]:edge[cc]){
            int ix = inv[x];
            int iy = inv[y];
            g[ix].push_back(iy);
            g[iy].push_back(ix);
        }
        vector<int> res;
        vector<bool> flag(m);
        auto dfs = [&](auto&&f,int id)->void{
            res.push_back(id);
            flag[id] = true;
            for(auto x:g[id]){
                if(!flag[x]){
                    f(f,x);
                    res.push_back(id);
                }
            }
        };
        dfs(dfs,0);
        map<pair<int,int>,int> ee;
        for(auto [x,y]:edge[cc]){
            int ix = inv[x];
            int iy = inv[y];
            ee[{min(ix,iy),max(ix,iy)}]++;
        }
        set<pair<int,int> > st;
        rep(i,res.size()-1){
            int x = res[i];
            int y = res[i+1];
            if(st.count({min(x,y),max(x,y)}))continue;
            st.insert({min(x,y),max(x,y)});
            ee[{min(x,y),max(x,y)}]--;
        }
        using pii = pair<int,int>;
        vv(int,elist,m);
        for(auto [x,c]:ee){
            rep(zz,c)elist[x.first].push_back(x.second);
        }
        vector<int> ss;
        rep(i,res.size()-1){
            int x = res[i];
            int y = res[i+1];
            dbg(x,y);
            dbg(elist[x]);
            ss.push_back(x);
            for(auto yy:elist[x]){
                ss.push_back(yy);
                ss.push_back(x);
            }
            elist[x].clear();
        }
        for(auto yy:elist[res.back()]){
            ss.push_back(yy);
            ss.push_back(res.back());
        }
        
        for(int i=0;i+1<ss.size()/2;i+=2){
            res1[0][T+i] = 'L';
            res1[0][T+i+1] = 'R';
            res1[1][T+i] = 'L';
            res1[1][T+i+1] = 'R';
        }
        if(ss.size()/2 %2==1){
            res1[0][T+ss.size()/2-1] = 'U';
            res1[1][T+ss.size()/2-1] = 'D';
        }
        res2[0][T] = 'U';
        res2[1][T] = 'D';
        for(int i=1;i+1<ss.size()/2;i+=2){
            res2[0][T+i] = 'L';
            res2[0][T+i+1] = 'R';
            res2[1][T+i] = 'L';
            res2[1][T+i+1] = 'R';
        }
        if(ss.size()/2 %2==0){
            res2[0][T+ss.size()/2-1] = 'U';
            res2[1][T+ss.size()/2-1] = 'D';
        }
        rep(i,ss.size()/2){
            ans[0][T] = v[ss[i]];
            T++;
        }
        srep(i,ss.size()/2,ss.size()){
            ans[1][T-1-i+ss.size()/2] = v[ss[i]];
        }
    }
    cout << 2 << " " << T << "\n";
    cout << "\n";
    rep(i,T){
        cout << ans[0][i] << " \n"[i==T-1];
    }
    rep(i,T){
        cout << ans[1][i] << " \n"[i==T-1];
    }
    cout << "\n";
    rep(i,T){
        cout << res1[0][i];
    }
    cout << "\n";
    rep(i,T){
        cout << res1[1][i];
    }
    cout << "\n";
    rep(i,T){
        cout << res2[0][i];
    }
    cout << "\n";
    rep(i,T){
        cout << res2[1][i];
    }
    cout << "\n";
    return 0;
}
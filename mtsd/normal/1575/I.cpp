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
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
template <class T> T ceil(T x, T y) {assert(y >= 1);return (x > 0 ? (x + y - 1) / y : x / y);}
template <class T> T floor(T x, T y) {assert(y >= 1);return (x > 0 ? x / y : (x + y - 1) / y);}
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

template<typename T> class segtree {
private:
    int n,sz,h;
    vector<T> node, lazy;
    vector<bool> lazyFlag;
    void eval(int k) {
        if(lazyFlag[k]){
            node[k] = lazy[k];
            if(k < n) {
                lazy[k*2] = lazy[k*2+1] = lazy[k] / 2;
                lazyFlag[k*2] = lazyFlag[k*2+1] = true;
            }
            lazyFlag[k] = false;
        }
    }

public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()), h(0) {
        while(n < sz) n *= 2, h++;
        node.resize(2*n, 0), lazy.resize(2*n, 0), lazyFlag.resize(2*n, false);
        for(int i = 0; i < sz; i++) node[i+n] = v[i];
        for(int i = n-1; i >= 1; i--) node[i] = node[2*i] + node[2*i+1];
    }
    void range(int a, int b, T x, int k=1, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            lazy[k] = (r-l)*x; lazyFlag[k] = true, eval(k);
        }else{
            range(a, b, x, 2*k, l, (l+r)/2);
            range(a, b, x, 2*k+1, (l+r)/2, r);
            node[k] = node[2*k] + node[2*k+1];
        }
    }
    T query(int a, int b) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        T res1 = 0, res2 = 0;
        while(a < b) {
            if(a & 1) eval(a), res1 += node[a++];
            if(b & 1) eval(--b), res2 += node[b];
            a >>= 1, b >>= 1;
        }
        return res1 + res2;
    }
    void print(){for(int i = 0; i < sz; i++) cout<<query(i,i+1)<< " ";cout<<endl;}
};

class HLdecomposition{
private:
    int V;
    vector<vector<int> > G;
    vector<int> stsize, parent, pathtop, in, out;
    int root;
    void BuildStsize(int u, int p){
        stsize[u] = 1, parent[u] = p;
        for(int& v : G[u]){
            if(v == p){
                if(v == G[u].back()) break;
                else swap(v, G[u].back());
            }
            BuildStsize(v, u);
            stsize[u] += stsize[v];
            if(stsize[v] > stsize[G[u][0]]){
                swap(v, G[u][0]);
            }
        }
    }
    void BuildPath(int u, int p, int& tm){
        in[u] = tm++;
        for(int v : G[u]){
            if(v == p) continue;
            pathtop[v] = (v == G[u][0] ? pathtop[u] : v);
            BuildPath(v, u, tm);
        }
        out[u] = tm;
    }
 
public:
    void add_edge(int u, int v){
        G[u].push_back(v), G[v].push_back(u);
    }
    void build(int _root=0){
        root = _root;
        int tm = 0;
        BuildStsize(root, -1);
        pathtop[root] = root;
        BuildPath(root, -1, tm);
    }
    //id
    inline int get(int a){
        return in[a];
    }
    int lca(int a, int b){
        int pa = pathtop[a], pb = pathtop[b];
        while(pathtop[a] != pathtop[b]){
            if(in[pa] > in[pb]){
                a = parent[pa], pa = pathtop[a];
            }else{
                b = parent[pb], pb = pathtop[b];
            }
        }
        if(in[a] > in[b]) swap(a, b);
        return a;
    }
    void subtree_query(int a, const function< void(int, int) > &func){
        func(in[a], out[a]);
    }
    // : hl.path_query(q, r, [&](int l, int r){ seg.range(l, r, s); })
    // : hl.query(q, r, [&](int l, int r){ ans += seg.query(l, r); })
    void path_query(int a, int b, const function< void(int, int) > &func){
        int pa = pathtop[a], pb = pathtop[b];
        while(pathtop[a] != pathtop[b]){
            if(in[pa] > in[pb]){
                func(in[pa], in[a] + 1);
                a = parent[pa], pa = pathtop[a];
            }else{
                func(in[pb], in[b] + 1);
                b = parent[pb], pb = pathtop[b];
            }
        }
        if(in[a] > in[b]) swap(a, b);
        func(in[a], in[b] + 1);
    }
    HLdecomposition(int node_size) : V(node_size), G(V), stsize(V, 0), parent(V, -1),
        pathtop(V, -1), in(V, -1), out(V, -1){}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    INT(n,q);
    VEC(ll,a,n);
    rep(i,n)a[i] = abs(a[i]);
    vector<ll>ppp(n);
    segtree<ll>seg(ppp);
    HLdecomposition hld(n);
    rep(i,n-1){
        INT(a,b);
        a--;b--;
        hld.add_edge(a,b);
    }
    hld.build();
    rep(i,n){
        seg.range(hld.get(i),hld.get(i)+1,a[i]);
    }
    rep(zz,q){
        INT(c,u,v);
        if(c==1){
            u--;
            hld.path_query(u, u, [&](int l, int r){ seg.range(l, r, abs(v)); });
        }else{
            u--;v--;
            ll res = 0;
            hld.path_query(u, v, [&](int l, int r){ res += seg.query(l, r); });
            cout << res * 2 - seg.query(hld.get(u),hld.get(u)+1) - seg.query(hld.get(v),hld.get(v)+1) << "\n";
        }
    }
    return 0;
}
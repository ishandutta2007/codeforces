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
class BM {
private:
    const int U, V;
    vector<vector<int> > G;
    vector<int> level, que, prv, rasg;
    int bfs(){
        int last = -1;
        fill(level.begin(), level.end(), -1);
        int qh = 0, qt = 0;
        for(int i = 0; i < U; ++i){
            if(asg[i] < 0) level[i] = 0, que[qt++] = i, prv[i] = -1;
        }
        while(qh < qt){
            const int u = que[qh++];
            if(u >= U){
                const int v = rasg[u - U];
                if(v >= 0) level[v] = level[u] + 1, que[qt++] = v, prv[v] = u;
                else last = u;
            }else{
                for(const int v : G[u]){
                    if(level[v] < 0) level[v] = level[u] + 1, que[qt++] = v, prv[v] = u;
                }
            }
        }
        return last;
    }
    bool dfs(const int u){
        const int tmp = level[u];
        level[u] = -1;
        if(u >= U){
            if(rasg[u - U] < 0) return true;
            else return dfs(rasg[u - U]);
        }else{
            for(const int v : G[u]){
                if(tmp < level[v]){
                    if(dfs(v)){
                        asg[u] = v - U, rasg[v - U] = u;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    void hint_search(int cur, int& flow){
        ++flow;
        while(cur >= 0){
            level[cur] = -1;
            if(cur >= U) asg[prv[cur]] = cur - U, rasg[cur - U] = prv[cur];
            cur = prv[cur];
        }
    }
public:
    BM(const int u, const int v)
         : U(u), V(v), G(U + V), level(U + V), que(U + V), prv(U + V), rasg(V, -1), asg(U, -1){}
    void add_edge(const int from, const int to){
        G[from].push_back(U + to);
    }
    // asg 
    vector<int> asg;
    int solve(){
        int flow = 0;
        for(;;){
            const int cur = bfs();
            if(cur < 0) break;
            hint_search(cur, flow);
            for(int i = 0; i < U; ++i){
                if(asg[i] < 0) flow += dfs(i);
            }
        }
        return flow;
    }
    // solve() ( i  U() + i )
    vector<int> minimum_vertex_cover(){
        vector<int> mvc;
        for(int i = 0; i < U; ++i){
            if(level[i] < 0) mvc.push_back(i);
        }
        for(int i = U; i < U + V; ++i){
            if(level[i] >= 0) mvc.push_back(i);
        }
        return mvc;
    }
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL(n,m);
    VEC(ll,a,n);
    vector<ll> p,q;
    rep(i,n){
        if(a[i]*3<=m){
            p.push_back(a[i]);
        }else{
            q.push_back(a[i]);
        }
    }
    sort(all(p));
    sort(all(q));
    int P = p.size();
    int Q = q.size();
    BM bm(P,Q);
    rep(i,p.size()){
        rep(j,q.size()){
            ll X = q[j]*2 + p[i];
            ll Y = q[j] + p[i];
            if(X>m)continue;
            ll Z = X%Y;
            ll W = Y%Z;
            if(Z%W!=0)continue;
            bm.add_edge(i,j);
        }
    }
    int S = bm.solve();
    dbg(S);
    if(S!=Q){
        cout << -1 << "\n";
        return 0;
    }
    auto asg = bm.asg;
    vector<pair<ll,ll> > res;
    rep(i,P){
        if(asg[i]==-1){
            res.push_back({p[i]*3,p[i]*2});
        }else{
            int j = asg[i];
            res.push_back({q[j]*2+p[i],q[j]+p[i]});
        }
    }
    cout << res.size() << "\n";
    for(auto [x,y]:res){
        cout << x << " " << y << "\n";
    }
    return 0;
}
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

template<typename T> class Dijkstra {
public:
	struct edge{
		int to; T cost;
	};
	int V;
	vector<vector<edge> > G;
	vector<T> d;
	using pti = pair<T,int>;
	Dijkstra(int node_size) : V(node_size), G(V), d(V, numeric_limits<T>::max()){}
	//
	void add_edge(int u,int v,T cost){
		G[u].push_back((edge){v,cost}),G[v].push_back((edge){u,cost});
	}
	void solve(int s){
		priority_queue<pti,vector<pti>,greater<pti> > que;
		d[s] = 0;
		que.push(pti(0,s));
		while(!que.empty()){
			pti p = que.top();
			que.pop();
			int v = p.second;
			if(d[v] < p.first) continue;
			for(auto& w : G[v]){
				if(d[w.to] > d[v] + w.cost){
					d[w.to] = d[v] + w.cost;
					que.push(pti(d[w.to],w.to));
				}
			}
		}
	}
};

const int MAX_V=500000;

int par[MAX_V];				//unionfind 
int m[MAX_V];				//unionfind  blog
							//,semi()

int I;			//dfsid
int parent[MAX_V];			//parent[v] = dfsTv
int vertex[MAX_V];			//vertex[i] = dfsi
int semi[MAX_V];			//semi[v] = v			if vstep2
							//			sdom(v)number		otherwise
int U[MAX_V];				//U[w] = w,step3Cor1u
int idom[MAX_V];			//idom[v] = idom(v) 
vector<int> bucket[MAX_V];		//bucket[v] = sdom(x)=vx(step3)
vector<int> G[MAX_V],rG[MAX_V];		//,

//unionfind
void init(int N){
	rep(i,N) par[i]=i,m[i]=i;
}
int find(int v){
	if(par[v]==v) return v;
	int r=find(par[v]);
	if(semi[m[v]]>semi[m[par[v]]]) m[v]=m[par[v]];
	return par[v]=r;
}
int EVAL(int v){					//sdom .sdom!
	find(v);
	return m[v];
}
void LINK(int x,int y){
	par[y]=x;
}
//unionfind

void dfs(int v){			//dfs
	semi[v]=I;
	vertex[I++]=v;
	for(int u:G[v]) if(semi[u]<0){
		parent[u]=v;
		dfs(u);
	}
}
void makedomtree(int N,int r){
	init(N);
	rep(i,N) semi[i]=-1;
	dfs(r);									//step1
	for(int i=N-1;i>0;i--){
		//step2
		int w=vertex[i];
		for(int v:rG[w]){
			int u=EVAL(v);
			chmin(semi[w],semi[u]);
		}
		bucket[vertex[semi[w]]].push_back(w);		//bucket
		//step3
		for(int v:bucket[parent[w]]) U[v]=EVAL(v);
		bucket[parent[w]].clear();			//step3bucket
		LINK(parent[w],w);					//
	}
	//step4
	for(int i=1;i<N;i++){
		int w=vertex[i];
		int u=U[w];
		if(semi[w]==semi[u]) idom[w]=semi[w];
		else idom[w]=idom[u];
	}

	for(int i=1;i<N;i++){				//idom[w]vertex id
		int w=vertex[i];
		idom[w]=vertex[idom[w]];
	}
	idom[r]=-1;
}
//https://sigma425.hatenablog.com/entry/2015/12/25/224053

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    INT(n,m,s);
    s--;
    Dijkstra<ll> dk(n);
    rep(i,m){
        INT(a,b,c);
        a--;b--;
        dk.add_edge(a,b,c);
    }
    dk.solve(s);
    vector<int> inv(n,-1);
    vector<int> p;
    auto d = dk.d;
    for(int i=0;i<n;i++){
        if(d[i]!=numeric_limits<ll>::max()){
            inv[i] = p.size();
            p.push_back(i);
        }   
    }
    int sz = p.size();

    
    rep(i,n){
        if(d[i]==numeric_limits<ll>::max())continue;
        for(auto e:dk.G[i]){
            if(d[i] + e.cost == d[e.to]){
                G[inv[i]].push_back(inv[e.to]);
                rG[inv[e.to]].push_back(inv[i]);
            }
        }
    }
    makedomtree(sz,inv[s]);
    // idom[w] -> w
    vector<vector<int> > tree(sz);
    rep(i,sz){
        if(idom[i]!=-1){
            tree[idom[i]].push_back(i);
        }
    }
    dbg(tree,inv[s]);
    vector<int> ss(sz);
    auto dfs2 = [&](auto&&f,int id)->void{
        for(auto x:tree[id]){
            f(f,x);
            ss[id] += ss[x];
        }
        ss[id]++;
        return;
    };
    dfs2(dfs2,inv[s]);
    
    dbg(ss);
    int ans = 0;
    int mx = 0;
    rep(i,sz){
        chmax(mx,ss[i]);
    }
    rep(i,sz){
        if(ss[i]!=mx){
            chmax(ans,ss[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
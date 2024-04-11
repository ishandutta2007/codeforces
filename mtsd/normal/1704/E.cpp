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


// template <unsigned int mod>
// class ModInt {
// private:
//     unsigned int v;
//     static unsigned int norm(const unsigned int& x){ return x < mod ? x : x - mod; }
//     static ModInt make(const unsigned int& x){ ModInt m; return m.v = x, m; }
//     static ModInt inv(const ModInt& x){ return make(inverse(x.v, mod)); }
//     static unsigned int inverse(int a, int m){
//         int u[] = {a, 1, 0}, v[] = {m, 0, 1}, t;
//         while(*v){
//             t = *u / *v;
//             swap(u[0] -= t * v[0], v[0]), swap(u[1] -= t * v[1], v[1]), swap(u[2] -= t * v[2], v[2]);
//         }
//         return (u[1] % m + m) % m;
//     }

// public:
//     ModInt() : v{0}{}
//     ModInt(const long long val) : v{norm(val % mod + mod)} {}
//     ModInt(const ModInt<mod>& n) : v{n()} {}
//     explicit operator bool() const noexcept { return v != 0; }
//     bool operator!() const noexcept { return !static_cast<bool>(*this); }
//     ModInt& operator=(const ModInt& n){ return v = n(), (*this); }
//     ModInt& operator=(const long long val){ return v = norm(val % mod + mod), (*this); }
//     ModInt operator+() const { return *this; }
//     ModInt operator-() const { return v == 0 ? make(0) : make(mod - v); }
//     ModInt operator+(const ModInt& val) const { return make(norm(v + val())); }
//     ModInt operator-(const ModInt& val) const { return make(norm(v + mod - val())); }
//     ModInt operator*(const ModInt& val) const { return make((long long)v * val() % mod); }
//     ModInt operator/(const ModInt& val) const { return *this * inv(val); }
//     ModInt& operator+=(const ModInt& val){ return *this = *this + val; }
//     ModInt& operator-=(const ModInt& val){ return *this = *this - val; }
//     ModInt& operator*=(const ModInt& val){ return *this = *this * val; }
//     ModInt& operator/=(const ModInt& val){ return *this = *this / val; }
//     ModInt operator+(const long long val) const { return ModInt{v + val}; }
//     ModInt operator-(const long long val) const { return ModInt{v - val}; }
//     ModInt operator*(const long long val) const { return ModInt{(long long)v * (val % mod)}; }
//     ModInt operator/(const long long val) const { return ModInt{(long long)v * inv(val)}; }
//     ModInt& operator+=(const long long val){ return *this = *this + val; }
//     ModInt& operator-=(const long long val){ return *this = *this - val; }
//     ModInt& operator*=(const long long val){ return *this = *this * val; }
//     ModInt& operator/=(const long long val){ return *this = *this / val; }
//     bool operator==(const ModInt& val) const { return v == val.v; }
//     bool operator!=(const ModInt& val) const { return !(*this == val); }
//     bool operator==(const long long val) const { return v == norm(val % mod + mod); }
//     bool operator!=(const long long val) const { return !(*this == val); }
//     unsigned int operator()() const { return v; }
//     friend ModInt operator+(const long long val, const ModInt& n) { return n + val; }
//     friend ModInt operator-(const long long val, const ModInt& n) { return ModInt{val - n()}; }
//     friend ModInt operator*(const long long val, const ModInt& n) { return n * val; }
//     friend ModInt operator/(const long long val, const ModInt& n) { return ModInt{val} / n; }
//     friend bool operator==(const long long val, const ModInt& n) { return n == val; }
//     friend bool operator!=(const long long val, const ModInt& n) { return !(val == n); }
//     friend istream& operator>>(istream& is, ModInt& n){
//         unsigned int v;
//         return is >> v, n = v, is;
//     }
//     friend ostream& operator<<(ostream& os, const ModInt& n){ return (os << n()); }
//     friend ModInt mod_pow(ModInt x, long long n){
//         ModInt ans = 1;
//         while(n){
//             if(n & 1) ans *= x;
//             x *= x, n >>= 1;
//         }
//         return ans;
//     }
// };

// #define MOD 998244353
// using mod = ModInt<MOD>;

// #define MAX_N 200000
// mod inv[MAX_N],fac[MAX_N],finv[MAX_N];

// void make()
// {
//     fac[0] = fac[1] = 1;
//     finv[0] = finv[1] = 1;
//     inv[1] = 1;
//     for(int i=2;i<MAX_N;i++){
//         inv[i] = MOD - inv[MOD % i] * (MOD / i);
//         fac[i] = fac[i-1] * i;
//         finv[i] = finv[i-1] * inv[i];
//     }
// }

// mod comb(int a, int b)
// {
//     if(a<b) return 0;
//     return fac[a] * finv[b] * finv[a-b];
// }


class tsort {
public:
	int V;
	vector<vector<int> > G;
	vector<int> deg,res;
	tsort(int node_size) : V(node_size), G(V), deg(V, 0){}
	void add_edge(int from,int to){
		G[from].push_back(to);
		deg[to]++;
	}
	bool solve() {
		queue<int> que;
		for(int i = 0; i < V; i++){
			if(deg[i] == 0){
				que.push(i);
			}
		}
		while(!que.empty()){
			int p = que.front();
			que.pop();
			res.push_back(p);
			for(int v : G[p]){
				if(--deg[v] == 0){
					que.push(v);
				}
			}
		}
		return (*max_element(deg.begin(),deg.end()) == 0);
	}
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    INT(T);
    rep(zz,T){
        INT(n,m);
        VEC(ll,a,n);
        vector<vector<pair<ll,ll>> >P(n);
        rep(i,n){
            if(a[i]!=0){
                P[i].push_back({0ll,a[i]});
            }
        }
        tsort ts(n);
        rep(i,m){
            INT(pp,qq);
            pp--;qq--;
            ts.add_edge(pp,qq);
        }
        ts.solve();
        if(SUM(a)==0){
            cout << 0 << "\n";
            continue;
        }
        vector<int> ord = ts.res;
        int X = ord.back();
        dbg(ord);
        const int MOD = 998244353;
        for(auto id:ord){
            if(P[id].empty())continue;
            sort(all(P[id]));
            dbg(id,P[id]);
            vector<pair<ll,ll> > Q;
            ll L = P[id][0].first;
            ll R = P[id][0].second;
            rep(i,(int)P[id].size()-1){
                auto [L1,R1] = P[id][i+1];
                if(L1 <= R){
                    R += (R1-L1);
                    if(R>=MOD){
                        R = MOD + (R%MOD);
                    }
                }else{
                    Q.push_back({L,R});
                    L = L1;
                    R = R1;
                }
            }
            Q.push_back({L,R});
            dbg(Q);
            if(id==X){
                cout << Q.back().second % MOD << "\n";
                break;
            }
            for(auto x:ts.G[id]){
                for(auto [L,R]:Q){
                    P[x].push_back({L+1,R+1});
                }
            }
        }
    }
    
    return 0;
}
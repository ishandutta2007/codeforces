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

template <unsigned int mod>
class ModInt {
private:
    unsigned int v;
    static unsigned int norm(const unsigned int& x){ return x < mod ? x : x - mod; }
    static ModInt make(const unsigned int& x){ ModInt m; return m.v = x, m; }
    static ModInt inv(const ModInt& x){ return make(inverse(x.v, mod)); }
    static unsigned int inverse(int a, int m){
        int u[] = {a, 1, 0}, v[] = {m, 0, 1}, t;
        while(*v){
            t = *u / *v;
            swap(u[0] -= t * v[0], v[0]), swap(u[1] -= t * v[1], v[1]), swap(u[2] -= t * v[2], v[2]);
        }
        return (u[1] % m + m) % m;
    }

public:
    ModInt() : v{0}{}
    ModInt(const long long val) : v{norm(val % mod + mod)} {}
    ModInt(const ModInt<mod>& n) : v{n()} {}
    explicit operator bool() const noexcept { return v != 0; }
    bool operator!() const noexcept { return !static_cast<bool>(*this); }
    ModInt& operator=(const ModInt& n){ return v = n(), (*this); }
    ModInt& operator=(const long long val){ return v = norm(val % mod + mod), (*this); }
    ModInt operator+() const { return *this; }
    ModInt operator-() const { return v == 0 ? make(0) : make(mod - v); }
    ModInt operator+(const ModInt& val) const { return make(norm(v + val())); }
    ModInt operator-(const ModInt& val) const { return make(norm(v + mod - val())); }
    ModInt operator*(const ModInt& val) const { return make((long long)v * val() % mod); }
    ModInt operator/(const ModInt& val) const { return *this * inv(val); }
    ModInt& operator+=(const ModInt& val){ return *this = *this + val; }
    ModInt& operator-=(const ModInt& val){ return *this = *this - val; }
    ModInt& operator*=(const ModInt& val){ return *this = *this * val; }
    ModInt& operator/=(const ModInt& val){ return *this = *this / val; }
    ModInt operator+(const long long val) const { return ModInt{v + val}; }
    ModInt operator-(const long long val) const { return ModInt{v - val}; }
    ModInt operator*(const long long val) const { return ModInt{(long long)v * (val % mod)}; }
    ModInt operator/(const long long val) const { return ModInt{(long long)v * inv(val)}; }
    ModInt& operator+=(const long long val){ return *this = *this + val; }
    ModInt& operator-=(const long long val){ return *this = *this - val; }
    ModInt& operator*=(const long long val){ return *this = *this * val; }
    ModInt& operator/=(const long long val){ return *this = *this / val; }
    bool operator==(const ModInt& val) const { return v == val.v; }
    bool operator!=(const ModInt& val) const { return !(*this == val); }
    bool operator==(const long long val) const { return v == norm(val % mod + mod); }
    bool operator!=(const long long val) const { return !(*this == val); }
    unsigned int operator()() const { return v; }
    friend ModInt operator+(const long long val, const ModInt& n) { return n + val; }
    friend ModInt operator-(const long long val, const ModInt& n) { return ModInt{val - n()}; }
    friend ModInt operator*(const long long val, const ModInt& n) { return n * val; }
    friend ModInt operator/(const long long val, const ModInt& n) { return ModInt{val} / n; }
    friend bool operator==(const long long val, const ModInt& n) { return n == val; }
    friend bool operator!=(const long long val, const ModInt& n) { return !(val == n); }
    friend istream& operator>>(istream& is, ModInt& n){
        unsigned int v;
        return is >> v, n = v, is;
    }
    friend ostream& operator<<(ostream& os, const ModInt& n){ return (os << n()); }
    friend ModInt mod_pow(ModInt x, long long n){
        ModInt ans = 1;
        while(n){
            if(n & 1) ans *= x;
            x *= x, n >>= 1;
        }
        return ans;
    }
};

#define MOD 1000000007
using mod = ModInt<MOD>;

#define MAX_N 200000
mod inv[MAX_N],fac[MAX_N],finv[MAX_N];

void make()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i=2;i<MAX_N;i++){
        inv[i] = MOD - inv[MOD % i] * (MOD / i);
        fac[i] = fac[i-1] * i;
        finv[i] = finv[i-1] * inv[i];
    }
}

mod comb(int a, int b)
{
    if(a<b) return 0;
    return fac[a] * finv[b] * finv[a-b];
}
ll a[2];
ll b[2];
ll c[2];
ll p[2];
int main(){
    LL(n,m,k);
    cin >> c[0] >> c[1];
    cin >> a[0]>> a[1] >> b[0] >> b[1];
    // [ax,ax+r)*[ay,ay+c),[bx,bx+r)*[by,by+c) 
    auto intersect = [&](pair<int,int>a,pair<int,int>b)->bool{
        if(max(a.first,b.first) < min(a.second,b.second)){
            return true;
        }else{
            return false;
        }
    };
    auto check = [&]()->bool{
        bool ok = 1;
        rep(i,2){
            if(intersect(MP(a[i],a[i]+c[i]),MP(b[i],b[i]+c[i]))){
                
            }else{
                ok = 0;
            }
        }
        return ok;
    };
    if(check()){
        rep(i,2){
            p[i] =  min(a[i]+c[i],b[i]+c[i]) - max(a[i],b[i]);
        }
        a[0] = 0;
        a[1] = 0;
        b[0] = a[0]+c[0]-p[0];
        b[1] = a[1]+c[1]-p[1];
        ll S = n*m;
        dbg(S);
        dbg(a[0],a[1],b[0],b[1]);
        S -= (max(a[0]+c[0],b[0]+c[0]) - min(a[0],b[0]))*(max(a[1]+c[1],b[1]+c[1]) - min(a[1],b[1]));
        auto calc = [&](auto&&f)->void{
            dbg(S);
            dbg(a[0],a[1],b[0],b[1],c[0],c[1]);
            if(check()){
                if(a[0]==b[0]&&a[1]==b[1]){
                    S += c[0]*c[1];
                    return;
                }
                // 
                S += 2 * (b[0]-a[0]) * (b[1]-a[1]);
                
                rep(i,2){
                    c[i] = min(a[i]+c[i],b[i]+c[i]) - max(a[i],b[i]);
                }
                
                f(f);
            }else{
                S += (max(a[0]+c[0],b[0]+c[0]) - min(a[0],b[0]))*(max(a[1]+c[1],b[1]+c[1]) - min(a[1],b[1]));
                S -= c[0]*c[1];
            }
        };
        calc(calc);
        dbg(S);
        cout << mod_pow((mod)k,S) << "\n";
    }else{
        ll S = n*m - c[0]*c[1];
        dbg(S);
        cout << mod_pow((mod)k,S) << "\n";
    }
    return 0;
}
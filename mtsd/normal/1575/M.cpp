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
template<typename T> class CHT
{
private:
    using ptt = pair<T, T>;
    bool check(ptt l1, ptt l2, ptt l3){
        return (l2.first-l1.first)*(l3.second-l2.second)>=(l2.second-l1.second)*(l3.first-l2.first);
    }
    T f(int i, T x){
        return lines[i].first * x + lines[i].second;
    }
public:
    vector<ptt> lines;
    int head;
    CHT(): head(0){};
    void add(T a, T b){
        ptt line(a, b);
        while((int)lines.size() - head >= 2 && check(*(lines.end()-2), lines.back(), line)){
            lines.pop_back();
        }
        lines.emplace_back(line);
    }
    T get(T x){
        while((int)lines.size() - head >= 2 && f(head, x) >= f(head + 1, x)){
            head++;
        }
        return f(head, x);
        // int low = -1, high = lines.size() - 1;
        // while (high - low > 1) {
        // 	int mid = (high + low) / 2;
        //     if(f(mid, x) >= f(mid+1, x)){
        //         low = mid;
        //     }else{
        //         high = mid;
        //     }
        // }
        // return f(high, x);
    }
};
ll d[2020][2020];
ll sd[2020][2020];
ll u[2020][2020];
ll su[2020][2020];
int main(){
    INT(n,m);
    n++;
    m++;
    VEC(string,s,n);
    rep(i,n){
        rep(j,m){
            d[i][j] = -10000;
            u[i][j] = 10000;
        }
    }
    // Fill(d,MP(-10000,-10000));
    // Fill(u,MP(10000,10000));
    auto dist = [&](pair<ll,ll>a,ll x,ll y)->ll{
        dbg(a,x,y);
        return (x-a.first)*(x-a.first) + (y-a.second)*(y-a.second);
    };
    rep(i,n){
        rep(j,m){
            if(s[i][j]=='1'){
                d[i][j] = i;

            }else{
                if(i!=0){
                    d[i][j] = d[i-1][j];
                }
            }
        }
        CHT<ll> cht;
        rep(j,m){
            cht.add(-2*j,j*j+(i-d[i][j])*(i-d[i][j]));
        }
        rep(j,m){
            sd[i][j] = cht.get(j) + j*j;
        }
    }
    rrep(i,n){
        rep(j,m){
            if(s[i][j]=='1'){
                u[i][j] = i;
            }else{
                if(i!=n-1){
                    u[i][j] = u[i+1][j];
                }
            }
        }
        CHT<ll> cht;
        rep(j,m){
            cht.add(-2*j,j*j+(i-u[i][j])*(i-u[i][j]));
        }
        rep(j,m){
            su[i][j] = cht.get(j) + j*j;
        }
    }
    ll res = 0;
    rep(i,n){
        rep(j,m){
            
            res += min(sd[i][j],su[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}
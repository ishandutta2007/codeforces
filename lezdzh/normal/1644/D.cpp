    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
     
     
    using namespace std;
    using namespace chrono;
    using namespace __gnu_pbds;
     
    using ll = long long;
    using ld = long double;
    // #define int long long
    typedef unsigned long long ull;
    typedef long double lld;
    // ----------------------------------------------MACROS--------------------------------------------------------------------------------------------------------
    #define mp   make_pair
    #define pb   push_back
    #define pbb  pop_back
    #define eb   emplace_back
    #define nline "\n"
    #define pii pair<int,int>
    #define sz(x) (int)x.size()
    #define FF first
    #define SS second
    #define set_bits __builtin_popcountll
     
     
    #define google cout << "Case #" << i << ": "
    #define rep(i,a,b) for(ll i=a;i<b;++i) 
    #define all(a)     a.begin(),a.end()
    #define rall(a)    a.rbegin(),a.rend()
    #define ps(x, y)    fixed << setprecision(y) << x
    #define sum(a)      (accumulate ((a).begin(), (a).end(), 0ll))
    #define mine(a)    (*min_element((a).begin(), (a).end()))
    #define maxe(a)    (*max_element((a).begin(), (a).end()))
    #define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
    #define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
    #define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
    #define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
     
    // ---------------------------------------------TEMPLATE-------------------------------------------------------------------------------------------------------------- 
    typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
    template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
    template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
    template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
    template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
    template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
    template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
    template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
    template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
    template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
    template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
    template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
    template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}
    template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
    template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
    vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
    ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
    ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
    void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
    ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
    ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
    ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
    ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
     
     
    // ------------------------------------------------------DEBUGGER-----------------------------------------------------------------------------------------------
    string to_string(char c) { return string(1, c);}
    string to_string(bool b) { return b?"true":"false";}
    string to_string(const char* s) { return string(s);}
    string to_string(string s) { return s;}
    #define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
    #define F_OR1(e) F_OR(i, 0, e, 1)
    #define F_OR2(i, e) F_OR(i, 0, e, 1)
    #define F_OR3(i, b, e) F_OR(i, b, e, 1)
    #define F_OR4(i, b, e, s) F_OR(i, b, e, s)
    #define GET5(a, b, c, d, e, ...) e
    #define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
    #define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
    #define EACH(x, a) for (auto& x: a)
    string to_string(vector<bool> v) { string res; FOR(sz(v)) {res+=char('0'+v[i]);} return res;}
    template<size_t S> string to_string(bitset<S> b) {string res;FOR(S){res+=char('0'+b[i]);}return res;}
    template<class T> string to_string(T v) { bool f=1;string res;EACH(x, v){if(!f){res+=' ';}f=0; res+=to_string(x);}return res;}
    void DBG() { cerr << "]" << endl;}
    template<class H, class... T> void DBG(H h, T... t) {cerr <<to_string(h);if(sizeof...(t)) cerr << ", ";DBG(t...);}
    #ifndef ONLINE_JUDGE
    #define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
    #else
    #define dbg(...) 0
    #endif
     
    //--------------------------------------PREDEFINED----------------------------------------------------------------------------------------------------------------
    #define PI 3.14159265
    #define INF 1e18
    const ll mod = 1e9+7;
    // const ll mod = 998244353;
    template <const int32_t MOD>
    struct modint {
        int32_t value;
        modint() = default;
        modint(int32_t value_) : value(value_) {}
        inline modint<MOD> operator + (modint<MOD> other) const { int32_t c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
        inline modint<MOD> operator - (modint<MOD> other) const { int32_t c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
        inline modint<MOD> operator * (modint<MOD> other) const { int32_t c = (int64_t)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
        inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
        inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
        inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
        inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
        modint<MOD> pow(uint64_t k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
        modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
        inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
        inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
        inline bool operator == (modint<MOD> other) const { return value == other.value; }
        inline bool operator != (modint<MOD> other) const { return value != other.value; }
        inline bool operator < (modint<MOD> other) const { return value < other.value; }
        inline bool operator > (modint<MOD> other) const { return value > other.value; }
    };
    template <int32_t MOD> modint<MOD> operator * (int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }
    template <int32_t MOD> modint<MOD> operator * (int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
    template <int32_t MOD> istream & operator >> (istream & in, modint<MOD> &n) { return in >> n.value; }
    template <int32_t MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }
     using mint = modint<mod>;
     
    // ---------------------------------------------------FUNCTION----------------------------------------------------------------------------------------------------------
     
     
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------
    void tc(){
        int n,m,k,q;
        cin>> n >> m >> k >> q;
        
        int ans=q;
        map<int,int> mapx,mapy;
        vector<int> x(q+1),y(q+1);
        for(int i=1;i<=q;i++)
            cin >> x[i]>> y[i];
        
     
         for(int i=q; i>0;i--){
           int xi=x[i], yi=y[i];
            
            if(mapx.count(xi) and mapy.count(yi) or (int)mapx.size()==n or (int)mapy.size()==m){
                ans--;
            }
                mapx[xi]=mapy[yi]=1;
     
        }
        int xx=pow(1ll*k,1ll*ans,998244353);
        cout << xx << nline;
        
        
    } 
    int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        auto start = chrono::high_resolution_clock::now();
     
        
        int t=1;
        cin >>t;
        while( t-- ){
            tc();
        }
     
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-6;
        cerr << ps(time_taken, 6) << " ms" << endl;
         
        return 0LL;
    }
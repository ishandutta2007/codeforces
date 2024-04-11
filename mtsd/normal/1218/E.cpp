#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 998244353
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define sar(a,n) {cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl;}
#define int long long

using namespace std;

template<typename S,typename T>auto&operator<<(ostream&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(ostream&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(ostream&o,map<K,T>&m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(ostream&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}
template<typename S,typename T,typename U>
struct TRI{S fi;T se;U th;TRI(){}TRI(S f,T s,U t):fi(f),se(s),th(t){}
bool operator<(const TRI&_)const{return(fi==_.fi)?((se==_.se)?(th<_.th):(se<_.se)):(fi<_.fi);}};
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,TRI<S,T,U>&t){return o<<"{"<<t.fi<<","<<t.se<<","<<t.th<<"}";}

typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef TRI<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<string> vs;

const int MAX_N = 100005;

#define MOD 998244353
#define root 3

int add(const int x, const int y) { return (x + y < MOD) ? x + y : x + y - MOD; }
int mul(const int x, const int y) { return (ll)x * y % MOD; }
int power(int x, int n)
{
    int res = 1;
    while(n > 0) {
        if (n & 1) { res = mul(res, x); }
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}
int inverse(const int x) { return power(x, MOD - 2); }

void ntt(vector<int>& a, const bool rev = false)
{
    int i,j,k,s,t,v,w,wn;
    const int size = (int)a.size();
    const int height = (int)log2(2 * size - 1);
    for(i = 0; i < size; i++) {
        j = 0;
        for(k = 0; k < height; k++) { j |= (i >> k & 1) << (height - 1 - k); }
        if(i < j) swap(a[i], a[j]);
    }
    for(i = 1; i < size; i *= 2) {
        w = power(root, (MOD - 1) / (i * 2));
        if(rev) w = inverse(w);
        for(j = 0; j < size; j += i * 2) {
            wn = 1;
            for(k = 0; k < i; k++) {
                s = a[j + k + 0], t = mul(a[j + k + i], wn);
                a[j + k + 0] = add(s, t);
                a[j + k + i] = add(s, MOD - t);
                wn = mul(wn, w);
            }
        }
    }
    if(rev){
        v = inverse(size);
        for (i = 0; i < size; i++) { a[i] = mul(a[i], v); }
    }
}

vector<int> convolute(const vector<int>& a, const vector<int>& b)
{
    const int size = (int)a.size() + (int)b.size() - 1;
    int t = 1;
    while (t < size) { t <<= 1; }
    vector<int> A(t, 0), B(t, 0);
    for (int i = 0; i < (int)a.size(); i++) { A[i] = a[i]; }
    for (int i = 0; i < (int)b.size(); i++) { B[i] = b[i]; }
    ntt(A), ntt(B);
    for (int i = 0; i < t; i++) { A[i] = mul(A[i], B[i]); }
    ntt(A, true);
    A.resize(size);
    return A;
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

long long bue = 998244353LL;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, K;
    cin >> n >> K;
    vector<long long> A(n);
    rep(i,n){
        cin >> A[i];
    }
    int Q;
    cin >> Q;
    rep(i,Q){
        int q;
        cin >> q;
        priority_queue<P, vector<P>, greater<P> > que;
        vvi a(2*n);
        if(q == 1){
            long long t, I, d;
            cin >> t >> I >> d;
            --I;
            rep(j, n){
                if(j == I){
                    a[j] = {1, (int)((t - d + 4*bue) % bue)};
                }else{
                    a[j] = {1, (int)((t - A[j] + 4*bue) % bue)};
                }
            }
        }else{
            long long t, l, r, d;
            cin >> t >> l >> r >> d;
            --l, --r;
            rep(j, n){
                if(l <= j && j <= r){
                    a[j] = {1, (int)((t - (A[j] + d) + 4*bue) % bue)};
                }else{
                    a[j] = {1, (int)((t - A[j] + 4*bue) % bue)};
                }
            }
        }
        rep(j,n){
            que.push(P(2, j));
        }
        int nw = n;
        while(que.size() > 1){
            P p1 = que.top();
            que.pop();
            P p2 = que.top();
            que.pop();
            a[nw] = convolute(a[p1.se], a[p2.se]);
            que.push(P(len(a[nw]), nw));
            nw++;
        }
        P res = que.top();
        assert((int)a[res.se].size() > K);
        cout << a[res.se][K] << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
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

#define MOD 998244353
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
mod ans[401][401];
int dist[401][401];
vector<int> P[401][401];
vector<vector<int> > g;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    Fill(dist,inf);
    rep(i,n){
        vector<int> c(n,0);
        c[i] = 1;
        dist[i][i] = 0;
        mod res = 1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(auto y:g[x]){
                if(dist[i][y]==inf){
                    c[y]++;
                    dist[i][y] = dist[i][x]+1;
                    P[i][y].push_back(x);
                    q.push(y);
                }else{
                    if(dist[i][y] == dist[i][x]+1){
                        c[y]++;
                        P[i][y].push_back(x);
                    }
                }
            }
        }
        rep(j,n){
            res *= c[j];
            sort(all(P[i][j]));
            // cerr << c[j] << " ";
        }
        // cerr << endl;
        ans[i][i] = res;
    }
    rep(i,n){
        rep(j,i){
            int L = dist[i][j];
            bool f = 0;
            vector<int> c(n);
            vector<int> cc(n);
            rep(k,n){
                if(k==i||k==j){
                    c[k] = 1;
                }else{
                    if(dist[i][j]==dist[i][k]+dist[k][j]){
                        cc[dist[i][k]]++;
                        c[k] = 1;
                        continue;
                    }
                    int i1=0,i2=0;
                    int m1 = P[i][k].size();
                    int m2 = P[j][k].size();
                    
                    while(i1!=m1&&i2!=m2){
                        if(P[i][k][i1]==P[j][k][i2]){
                            c[k]++;
                            i1++;
                            i2++;
                        }else if(P[i][k][i1]>P[j][k][i2]){
                            i2++;
                        }else{
                            i1++;
                        }
                    }
                }
            }
            rep(i,n){
                if(cc[i]>=2)f = 1;
            }
            if(f)continue;
            mod res = 1;
            rep(k,n)res *= c[k];
            ans[i][j] = res;
            ans[j][i] = res;
        }
    }
    rep(i,n){
        rep(j,n){
            cout << ans[i][j];
            if(j!=n-1)cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
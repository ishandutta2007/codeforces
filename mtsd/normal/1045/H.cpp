#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define PB push_back
typedef long long ll;


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

#define MAX_N 200010
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
vector<int> ch(string s){
    vector<int> tmp;
    rep(i,s.size()){
        tmp.push_back(s[i]-'0');
    }
    return tmp;
}
mod calc(int a,int b,int c,int d){
    if(a<0||b<0||c<0||d<0)return 0;
    if(c==d){
        if(c==0&&b!=0){
            return 0;
        }
        if(c==0&&b==0){
            return comb(a+c,c);
        }
        return comb(b+c-1,c-1) * comb(a+c,c);
    }else if(d==c-1){
        return comb(b+c-1,c-1) * comb(a+c-1,c-1);
    }
    return 0;
}

mod solve(string s,vector<int>c){
    int n = s.size();
    vector<int> a = ch(s);
    mod res = 0;
    rep(i,n){
        if(a[i]==1){
            if(i==0){

            }else{
                {// 11 -> 10, 01->00
                    c[a[i-1]*2+0]--;
                    
                    res += calc(c[0],c[3],c[1],c[2]);
                    // cerr << c[0] << " " << c[3] << " " << c[1] << " " << c[2] << endl;
                    // cerr << calc(c[0],c[3],c[1],c[2]) << endl;
                    c[a[i-1]*2+0]++;
                }
                c[a[i-1]*2+a[i]]--; 
            }
        }else{
            c[a[i-1]*2+a[i]]--;
        }
    }
    if(c[0]==0&&c[1]==0&&c[2]==0&&c[3]==0){
        res += 1;
    }
    return res;
}
bool ok(string s,vector<int> c){
    int n = s.size();
    vector<int> a = ch(s);
    rep(i,n-1){
        c[2*a[i]+a[i+1]]--;
    }
    rep(i,4){
        if(c[i]!=0)return false;
    }
    return true;
}

int main(){
    make();
    string a,b;
    cin >> a >> b;
    vector<int> c(4);
    int k = 0;
    rep(i,4){
        cin >> c[i];
        k += c[i];
    }
    if(c[2]!=c[1]&&c[2]!=c[1]+1){
        cout << 0 << endl;
        return 0;
    }
    k++;
    if(a.size()>k||b.size()<k){
        cout << 0 << endl;
        return 0;
    }
    if(a.size()<k){
        string t;
        t.push_back('1');
        rep(i,k-1){
            t.push_back('0');
        }
        a = t;
    }
    if(b.size()>k){
        string t;
        t.push_back('1');
        rep(i,k-1){
            t.push_back('1');
        }
        b = t;    
    }
    mod res = solve(b,c) - solve(a,c);
    if(ok(a,c))res += 1;
    cout << res << endl;
    return 0;
}
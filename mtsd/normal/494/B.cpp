#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
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


//(lcp)(O(nlog^2(n)))
//SA_IS
//lcp()
class suffixarray{
public:
    int sz,index1,index2;
    vector<int> rnk,tmp,sa,lcp;
    string recs;
    suffixarray(string s){
        recs = s;
        sz = (int)s.size();
        rnk.resize(sz+1),tmp.resize(sz+1);
        make_sa();
        // make_lcp();
    }
    void make_sa(){
        index1 = sz;
        sa.resize(index1+1);
        for(int i = 0; i < index1+1; i++){
            sa[i] = i;
            rnk[i] = i<index1?recs[i]:-1;
        }
        auto comp = [&](int i,int j){
            if(rnk[i] != rnk[j]){
                return rnk[i] < rnk[j];
            }else{
                int ri = (i+index2<=index1)?rnk[i+index2]:-1;
                int rj = (j+index2<=index1)?rnk[j+index2]:-1;
                return ri < rj;
            }
        };
        for(index2=1;index2<=index1;index2*=2){
            sort(sa.begin(),sa.end(),comp);
            tmp[sa[0]] = 0;
            for(int i=1;i<=index1;i++){
                tmp[sa[i]] = tmp[sa[i-1]]+(comp(sa[i-1],sa[i])?1:0);
            }
            for(int i = 0; i < index1+1; i++){
                rnk[i] = tmp[i];
            }
        }
    }
    void make_lcp(){
        lcp.resize(sz+1);
        for(int i = 0; i < sz+1; i++){
            rnk[sa[i]] = i;
        }
        int h = 0;
        lcp[0] = 0;
        for(int i = 0; i < sz; i++){
            int j = sa[rnk[i]-1];
            if(h > 0){
                h--;
            }
            for(;j+h<sz&&i+h<sz;h++){
                if(recs[j+h] != recs[i+h]){
                    break;
                }
            }
            lcp[rnk[i]-1] = h;
        }
    }
};
//
// abracadabra
// 11 0 
// 10 1 a
//  7 4 abra
//  0 1 abracadabra
//  3 1 acadabra
//  5 0 adabra
//  8 3 bra
//  1 0 bracadabra
//  4 0 cadabra
//  6 0 dabra
//  9 2 ra
//  2 0 racadabra




//cri
int stsearch(suffixarray& ag,string& cri)
{
    int n = ag.sz;
    int l=0,r=n+1;
    vector<int>& sa = ag.sa;
    while(r-l>1){
        int mid = (l+r)/2;
        if(n-sa[mid] < (int)(cri.size())){
            string t = ag.recs.substr(sa[mid],n-sa[mid]);
            if(t <= cri){
                l = mid;
            }else{
                r = mid;
            }
        }else{
            string t = ag.recs.substr(sa[mid],(int)(cri.size()));
            if(t < cri){
                l = mid;
            }else{
                r = mid;
            }
        }
    }
    return r;
}




//cri+1()
int edsearch(suffixarray& ag,string& cri)
{
    int n = ag.sz;
    int l=0,r=n+1;
    vector<int>& sa = ag.sa;
    while(r-l>1){
        int mid = (l+r)/2;
        if(n-sa[mid] < (int)(cri.size())){
            string t = ag.recs.substr(sa[mid],n-sa[mid]);
            if(t < cri){
                l = mid;
            }else{
                r = mid;
            }
        }else{
            string t = ag.recs.substr(sa[mid],(int)(cri.size()));
            if(t <= cri){
                l = mid;
            }else{
                r = mid;
            }
        }
    }
    return r;
}


template<typename T> class segtree {
private:
    int n,sz,h;
    vector<T> node, lazy;
    void eval(int k) {
        if(lazy[k]){
            node[k] += lazy[k];
            if(k < n) {
                lazy[k*2] += lazy[k] / 2, lazy[k*2+1] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()), h(0) {
        while(n < sz) n *= 2, h++;
        node.resize(2*n, 0), lazy.resize(2*n, 0);
        for(int i = 0; i < sz; i++) node[i+n] = v[i];
        for(int i = n-1; i >= 1; i--) node[i] = node[2*i] + node[2*i+1];
    }
    void range(int a, int b, T x, int k=1, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k);
        if(b <= l || r <= a){
            return;
        }
        if(a <= l && r <= b){
            lazy[k] += (r-l)*x;
            eval(k);
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


int main(){
    string s,t;
    cin >> s >> t;
    suffixarray sa(s);
    int p = stsearch(sa,t);
    int q = edsearch(sa,t);
    set<int> st;
    for(int i=p;i<q;i++){
        st.insert(sa.sa[i]);
        // cerr << sa.sa[i] << endl;
    }
    if(st.size()==0){
        cout << 0 << endl;
        return 0;
    }
    int n = s.size();
    vector<mod> aaa(n+1);
    // auto x = st.end();
    // x--;
    // int ss = (*x);
    // for(int i=0;i<=ss;i++){
    //     aaa[i] = 1;
    // }
    aaa[0] = 1;
    segtree<mod> sg(aaa);
    rep(i,n){
        mod K = sg.query(0,i+1);
        auto X = st.lower_bound(i);
        if(X==st.end())continue;
        int id = *X;
        int nxt = id + (int)t.size() ;
        sg.range(nxt,n+1,K);
    }
    cout << sg.query(1,n+1) << endl;
    return 0;
}
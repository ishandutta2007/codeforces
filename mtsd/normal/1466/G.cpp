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


std::vector<int> sa_naive(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n);
    std::iota(sa.begin(), sa.end(), 0);
    std::sort(sa.begin(), sa.end(), [&](int l, int r) {
        if (l == r) return false;
        while (l < n && r < n) {
            if (s[l] != s[r]) return s[l] < s[r];
            l++;
            r++;
        }
        return l == n;
    });
    return sa;
}

std::vector<int> sa_doubling(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n), rnk = s, tmp(n);
    std::iota(sa.begin(), sa.end(), 0);
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int x, int y) {
            if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
            int rx = x + k < n ? rnk[x + k] : -1;
            int ry = y + k < n ? rnk[y + k] : -1;
            return rx < ry;
        };
        std::sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        std::swap(tmp, rnk);
    }
    return sa;
}

// SA-IS, linear-time suffix array construction
// Reference:
// G. Nong, S. Zhang, and W. H. Chan,
// Two Efficient Algorithms for Linear Time Suffix Array Construction
template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
std::vector<int> sa_is(const std::vector<int>& s, int upper) {
    int n = int(s.size());
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) {
        if (s[0] < s[1]) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    if (n < THRESHOLD_NAIVE) {
        return sa_naive(s);
    }
    if (n < THRESHOLD_DOUBLING) {
        return sa_doubling(s);
    }

    std::vector<int> sa(n);
    std::vector<bool> ls(n);
    for (int i = n - 2; i >= 0; i--) {
        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
    }
    std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
    for (int i = 0; i < n; i++) {
        if (!ls[i]) {
            sum_s[s[i]]++;
        } else {
            sum_l[s[i] + 1]++;
        }
    }
    for (int i = 0; i <= upper; i++) {
        sum_s[i] += sum_l[i];
        if (i < upper) sum_l[i + 1] += sum_s[i];
    }

    auto induce = [&](const std::vector<int>& lms) {
        std::fill(sa.begin(), sa.end(), -1);
        std::vector<int> buf(upper + 1);
        std::copy(sum_s.begin(), sum_s.end(), buf.begin());
        for (auto d : lms) {
            if (d == n) continue;
            sa[buf[s[d]]++] = d;
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        sa[buf[s[n - 1]]++] = n - 1;
        for (int i = 0; i < n; i++) {
            int v = sa[i];
            if (v >= 1 && !ls[v - 1]) {
                sa[buf[s[v - 1]]++] = v - 1;
            }
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        for (int i = n - 1; i >= 0; i--) {
            int v = sa[i];
            if (v >= 1 && ls[v - 1]) {
                sa[--buf[s[v - 1] + 1]] = v - 1;
            }
        }
    };

    std::vector<int> lms_map(n + 1, -1);
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms_map[i] = m++;
        }
    }
    std::vector<int> lms;
    lms.reserve(m);
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms.push_back(i);
        }
    }

    induce(lms);

    if (m) {
        std::vector<int> sorted_lms;
        sorted_lms.reserve(m);
        for (int v : sa) {
            if (lms_map[v] != -1) sorted_lms.push_back(v);
        }
        std::vector<int> rec_s(m);
        int rec_upper = 0;
        rec_s[lms_map[sorted_lms[0]]] = 0;
        for (int i = 1; i < m; i++) {
            int l = sorted_lms[i - 1], r = sorted_lms[i];
            int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
            int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
            bool same = true;
            if (end_l - l != end_r - r) {
                same = false;
            } else {
                while (l < end_l) {
                    if (s[l] != s[r]) {
                        break;
                    }
                    l++;
                    r++;
                }
                if (l == n || s[l] != s[r]) same = false;
            }
            if (!same) rec_upper++;
            rec_s[lms_map[sorted_lms[i]]] = rec_upper;
        }

        auto rec_sa =
            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

        for (int i = 0; i < m; i++) {
            sorted_lms[i] = lms[rec_sa[i]];
        }
        induce(sorted_lms);
    }
    return sa;
}

std::vector<int> suffix_array(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return sa_is(s2, 255);
}

int stsearch(vector<int>& sa,string& cri,string& s)
{
    int n = sa.size();
    int l=-1,r=n;
    while(r-l>1){
        int mid = (l+r)/2;
        if(n-sa[mid] < (int)(cri.size())){
            string t = s.substr(sa[mid],n-sa[mid]);
            if(t <= cri){
                l = mid;
            }else{
                r = mid;
            }
        }else{
            string t = s.substr(sa[mid],(int)(cri.size()));
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
int edsearch(vector<int>& sa,string& cri,string& s)
{
    int n = sa.size();
    int l=-1,r=n;
    while(r-l>1){
        int mid = (l+r)/2;
        if(n-sa[mid] < (int)(cri.size())){
            string t = s.substr(sa[mid],n-sa[mid]);
            if(t < cri){
                l = mid;
            }else{
                r = mid;
            }
        }else{
            string t = s.substr(sa[mid],(int)(cri.size()));
            if(t <= cri){
                l = mid;
            }else{
                r = mid;
            }
        }
    }
    return r;
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

struct RH {
	static int mod[2], mul[2];
    static vector<int> pm[2];
    int sz;
    vector<vector<int> > hs;
	RH(const string& s) : sz((int)s.size()), hs(2, vector<int>(sz + 1, 0)){
        for(int i = 0; i < 2; i++){
            if(pm[i].empty()) pm[i].push_back(1);
            for(int j = 0; j < sz; j++){
                hs[i][j+1] = ((long long)hs[i][j] * mul[i] + s[j]) % mod[i];
            }
        }
	}
    //  s  [l,r) 
	pair<int, int> hash(const int l, const int r){
		if(l >= r) return make_pair(0, 0);
        int res[2];
        for(int i = 0; i < 2; i++){
            while((int)pm[i].size() <= r){
                pm[i].push_back((long long)pm[i].back() * mul[i] % mod[i]);
            }
            res[i] = (hs[i][r] - (long long)hs[i][l] * pm[i][r-l]) % mod[i] + mod[i];
            res[i] = (res[i] >= mod[i]) ? (res[i] - mod[i]) : res[i];
        }
		return make_pair(res[0], res[1]);
	}
    //  s  pattern  pos 
    void contain(const string& pattern, vector<int>& pos){
        int length = (int)pattern.size();
        if(sz < length) return;
        RH rh(pattern);
        pair<int, int> _hash = rh.hash(0, length);
        for(int i = 0; i < sz - length + 1; i++){
    		if(hash(i, i + length) == _hash){
    			pos.push_back(i);
    		}
    	}
        return;
    }
};
vector<int> RH::pm[2];
int RH::mod[2] = {1000000007, 1000000009}, RH::mul[2] = {10009, 10007};

const int LIM = 1000010;
mod SS[27][200020];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    string s,t;
    cin >> s >> t;
    vector<vector<int>> sa;
    vector<string> cc;
    int lev = 0;
    rep(i,n){
        cc.push_back(s);
        sa.push_back(suffix_array(s));
        lev++;
        
        if((int)s.size()*2+1>=2*LIM)break;
        string p;
        p.push_back(t[i]);
        s = s + p + s;
        if(i==n-1){
            cc.push_back(s);
            sa.push_back(suffix_array(s));
            lev++;
        }
    }
    
    for(int i=lev;i<=n;i++){
        char c = t[i-1];
        SS[c-'a'][i] = 1;
    }
    for(int i=lev;i<=n;i++){
        rep(z,26){
            SS[z][i+1] += SS[z][i]*2;
        }
    }
    // cerr <<"lev: " <<  lev << endl;
    RH rh(s);
    int M = s.size();
    rep(zz,q){
        int k;
        string p;
        cin >> k >> p;
        if(k>=lev){
            mod res = 0;
            int S = stsearch(sa[lev-1],p,cc[lev-1]);
            int T = edsearch(sa[lev-1],p,cc[lev-1]);
            int C = T-S;
            res += (mod)(C) * mod_pow((mod)(2),k-lev+1);
            // cerr << res << endl;
            RH rh2(p);
            int m = p.size();
            for(int id=0;id<m;id++){
                int left = id;
                int right = m-1-id;
                if(rh.hash(M-left,M)==rh2.hash(0,id)&&rh.hash(0,right)==rh2.hash(id+1,m)){
                    res += SS[(int)(p[id]-'a')][k];
                    // cerr << id << endl;
                }
            }
            
            cout << res << "\n";
        }else{
            // cerr << p << " " << cc[k] << endl;
            int S = stsearch(sa[k],p,cc[k]);
            int T = edsearch(sa[k],p,cc[k]);
            cout << T-S << "\n";
            // cerr << S << " "<< T << endl;
        }
    }

    return 0;
}
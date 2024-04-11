
// Follows https://github.com/cuber2460/acmlib07/blob/master/code/finaly/code/FFT.cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;

// If [mod] needs to be variable, move it to the struct and initialize
// it in the beginning of the constructor.
template <int mod>
struct FFTIntMod {
private:
    int maxn;
    int root;

    static inline void add_mod(int &a, int b) {
        a += b;
        if (a >= mod) { a -= mod; }
    }
    static inline void sub_mod(int &a, int b) {
        a -= b;
        if (a < 0) { a += mod; }
    }
    static inline int mul_mod(int a, int b) {
        return (int)((ll)a * b % mod);
    }
    static inline int pow_mod(int a, int n) {
        int r = 1;
        while (n) {
            if (n & 1) { r = mul_mod(r, a); }
            n >>= 1;
            a = mul_mod(a, a);
        }
        return r;
    }
    static inline int inv_mod(int a) {
        return pow_mod(a, mod - 2);
    }
    static inline int div_mod(int a, int b) {
        return mul_mod(a, inv_mod(b));
    }

    vector<int> FindPrimeFactors(int num) {
        vector<int> ans;
        for (int p = 2; p * p <= num; ++p) {
            if (num % p == 0) {
                ans.push_back(p);
                while (num % p == 0) { num /= p; }
            }
        }
        if (num > 1) { ans.push_back(num); }
        return ans;
    }

    void FindGenerator() {
        vector<int> prime_factors = FindPrimeFactors(mod - 1);
        while (true) {
            const int g = rand() % (mod - 1) + 1;
            bool ok = true;
            for (int p : prime_factors) {
                if (pow_mod(g, mod / p) == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                root = pow_mod(g, mod / maxn);
                break;
            }
        }
    }

    void DFT(vi &a) {
        const int n = a.size();
        for (int i = 1, k = 0; i < n; ++i) {
            for (int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
            if (i < k) { swap(a[i], a[k]); }
        }
        for (int len = 1, who = 0; len < n; len *= 2, ++who) {
            static vi t[32];
            vi &om = t[who];
            if (om.empty()) {
                om.resize(len + 1);
                if (who == 0) {
                    om[0] = 1;
                    om[1] = mod - 1;
                } else {
                    const int stepg = pow_mod(root, maxn / (2 * len));
                    for (int i = 0; i < len; ++i) {
                        om[i] = t[who - 1][i / 2];
                        if (i & 1) {
                            om[i] = mul_mod(om[i], stepg);
                        }
                    }
                }
                om.back() = om[0];
            }
            for (int i = 0; i < n; i += 2 * len) {
                for (int k = 0; k < len; ++k) {
                    const int x = a[i + k];
                    const int y = mul_mod(a[i + k + len], om[k]);
                    add_mod(a[i + k], y);
                    a[i + k + len] = x;
                    sub_mod(a[i + k + len], y);
                }
            }
        }
    }

public:
    FFTIntMod(int max_out_terms) {  // (max_out_terms = max_out_degree + 1)
        maxn = 1;
        while (maxn < max_out_terms) { maxn *= 2; }
        assert((mod - 1) % maxn == 0 && "Not enough powers of 2 in mod-1");
        FindGenerator();
    }

    vi Multiply(const vi &a, const vi &b) {
        if (a.empty() || b.empty()) { return {}; }
        int n = a.size() + b.size();
        const int ans_size = n - 1;
        assert(n <= maxn);
        while (n & (n - 1)) { ++n; }

        vi X(n), Y(n);
        copy(a.begin(), a.end(), X.begin());
        copy(b.begin(), b.end(), Y.begin());
        DFT(X);
        DFT(Y);
        for (int i = 0; i < n; ++i) {
            X[i] = mul_mod(X[i], Y[i]);
        }
        reverse(X.begin() + 1, X.end());
        const int div = inv_mod(n);
        for (int &x : X) { x = mul_mod(x, div); }
        DFT(X);
        X.resize(ans_size);
        return X;
    }
};


#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int p = 998244353;

void add(int &a,int b){
  a += b;
  if(a >= p)
    a -= p;
}
void sub(int &a,int b){
  a -= b;
  if(a < 0)
    a += p;
}
int mul(int a,int b){
  return a * b % p;
}

int pot(int a,int w){
  int r = 1;
  while(w){
    if(w & 1){
      r = mul(a,r);
    }
    w/=2;
    a = mul(a,a);
  }
  return r;
}

FFTIntMod<p> fft(1 << 20);
vector<int> a,b,c;

void licz(int po,int ko){
  if(po + 1 == ko){
    return;
  }
  int m = (po + ko)/2;
  vector<int32_t> aa,bb;
  for(int i = po;i < m; i++){
    aa.PB(a[i]);
  }
  for(int i = m; i < ko; i++){
    bb.PB(b[i]);
  }
  vector<int32_t> cc = fft.Multiply(aa, bb);
  debug(aa,bb,cc);
  R(i,SZ(cc)){
    add(c[i + po + m], cc[i]);
  }
  licz(po,m);
  licz(m,ko);
}
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  
  int n,m;
  cin >> n >> m;
  vector<int> val(n);
  R(i,n){
    cin >> val[i];
  }
  
  vector<int> p2(n + 5);
  vector<int> odw2(n + 5);
  
  p2[0] = 1;
  R(i,n + 4){
    p2[i + 1] = mul(p2[i], 2);
  }
  R(i,n+5){
    odw2[i] = pot(p2[i],p-2);
  }
  
  assert(mul(odw2[4],p2[4]) == 1);
  a.resize(n);
  b.resize(n);
  int odl = 0;
  c.resize(2 * n);
  R(i,m){
    int pom;
    cin >> pom;
    pom--;
    a[pom] = p2[i];
    b[pom] = odw2[i + 1];
    sub(c[pom * 2], odw2[1]);
    add(odl, mul(odw2[i+1], (2 * pom + 1)));
  }
  
    debug("aaaa");
  for(int el:a){
    debug(mul(el,4));
  }
cerr << "\n\n";
debug("bbbb");
  for(int el:b){
    debug(mul(el,4));
  }
cerr << "\n\n";
  
  
  debug(mul(odl, 4));
  licz(0, n);
  debug("cccccc");
  for(int el:c){
    debug(mul(el,4));
  }
cerr << "\n\n";
  
  int praw = 1;
  sub(praw, odw2[m]);
  int lewo = 0;
  
  int res = 0;
  R(i,n){
    debug(i,"-----------");
    debug(mul(praw,4));
    debug(mul(lewo,4));
    sub(odl, praw);
    add(odl, lewo);
    
    debug(mul(odl,4));
    add(res, mul(odl,val[i]));
    sub(lewo, c[i * 2]);
    add(praw, c[i * 2]);
    
    
    debug(mul(praw,4));
    debug(mul(lewo,4));
    sub(odl, praw);
    add(odl, lewo);
    sub(lewo, c[i * 2 + 1]);
    add(praw, c[i * 2 + 1]);
  }
  debug(mul(res,4));
  
  res = mul(res, p2[m]);
  debug(res);
  res = mul(res, odw2[1]);
  debug(res);
  int pom = p2[m];
  sub(pom, 1);
  cout << mul(res, pot(pom,p-2)) << "\n";
  
}
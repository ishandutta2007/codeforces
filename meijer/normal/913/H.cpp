#include <bits/stdc++.h>
using namespace std;
 
// macros
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define FOR(a,b) for(auto& a : b)
#define all(a) a.begin(), a.end()
#define INF 1e18
#define EPS 1e-9
#define pb push_back
#define popb pop_back
#define fi first
#define se second
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// input
template<class T> void IN(T& x) {cin >> x;}
template<class H, class... T> void IN(H& h, T&... t) {IN(h); IN(t...); }
 
// output
template<class T1, class T2> void OUT(const pair<T1,T2>& x);
template<class T> void OUT(const vector<T>& x);
template<class T> void OUT(const T& x) {cout << x;}
template<class H, class... T> void OUT(const H& h, const T&... t) {OUT(h); OUT(t...); }
template<class T1, class T2> void OUT(const pair<T1,T2>& x) {OUT(x.fi,' ',x.se);}
template<class T> void OUT(const vector<T>& x) {RE(i,x.size()) OUT(i==0?"":" ",x[i]);}
template<class... T> void OUTL(const T&... t) {OUT(t..., "\n"); }
template<class H> void OUTLS(const H& h) {OUTL(h); }
template<class H, class... T> void OUTLS(const H& h, const T&... t) {OUT(h,' '); OUTLS(t...); }
 
// dp
template<class T> bool ckmin(T&a, T&b) { bool bl = a > b; a = min(a,b); return bl;}
template<class T> bool ckmax(T&a, T&b) { bool bl = a < b; a = max(a,b); return bl;}
 
void program();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    program();
}
 

// mod library
ll MOD=998244353;

inline ll mod(ll x_) {
    return (x_)%MOD;
}
ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}
class mi {
public:
    mi(ll v=0) {value = v;}
    mi  operator+ (ll rs) {return mod(value+rs);}
    mi  operator- (ll rs) {return mod(value-rs+MOD);}
    mi  operator* (ll rs) {return mod(value*rs);}
    mi  operator/ (ll rs) {return mod(value*inv(rs));}
    mi& operator+=(ll rs) {*this = (*this)+rs; return *this;}
    mi& operator-=(ll rs) {*this = (*this)-rs; return *this;}
    mi& operator*=(ll rs) {*this = (*this)*rs; return *this;}
    mi& operator/=(ll rs) {*this = (*this)/rs; return *this;}
    operator ll&() {return value;}
    operator ll() const {return value;}

    ll value;
};
typedef vector<mi> vmi;

//===================//
//   begin program   //
//===================//
 
const int MX = 100;
const int N = (1<<20);
const int MULT = 1e6;

int n, m;

mi C[MX][MX];

struct Polynomial {
    vector<mi> a;
    Polynomial integrate() {
        Polynomial res;
        res.a = {0};
        RE(i,a.size())
            res.a.pb(a[i]/mi(i+1));
        return res;
    }
    Polynomial& operator-=(const Polynomial& rhs) {
        while(a.size() < rhs.a.size())
            a.pb(0);
        RE(i,rhs.a.size())
            a[i] -= rhs.a[i];
        return *this;
    }
    mi eval(mi x) {
        mi res = 0;
        mi fact = 1;
        RE(i,a.size()) {
            res += a[i]*fact;
            fact *= x;
        }
        return res;
    }
    Polynomial getXShift(int shift) {
        Polynomial res;
        res.a.assign(a.size(),0);
        RE(i,a.size())
            RE(j,i+1)
                res.a[j] += a[i]*C[i][j]*modpow(shift, i-j);
        return res;
    }
};

void program() {
    // pre calc
    mi invMult = mi(1)/mi(MULT);
    RE(i,MX) RE(j,MX)
        C[i][j] = (j == 0 ? mi(1) : (i == 0 ? mi(0) : C[i-1][j] + C[i-1][j-1]));

    vector<int> frac = {0};
    vector<int> x;
    vector<int> points;
    vector<int> xpos;

    IN(n);
    RE(i,n) {
        double cx; IN(cx);
        int res = (cx*double(MULT) + 0.5);
        x.pb(res);
        frac.pb(res%MULT);
    }
    sort(all(frac));
    frac.erase(unique(all(frac)),frac.end());
    m = frac.size();

    { // fill points
        points.resize(n*m+1);
        RE(i,n*m+1) {
            points[i] = (mi(i/m)*mi(MULT) + (mi)frac[i%m])*invMult;
        }
    }

    { // fill xpos
        xpos.assign(n,0);
        RE(i,n) RE(j,points.size()) {
            if(points[j] == mi(x[i])*invMult)
                xpos[i] = j;
        }
    }

    vector<Polynomial> f(n*m);
    RE(i,n*m)
        f[i].a = {i < min(m, xpos[0]) ? 1 : 0};
    REP(curX,1,n) {
        FOR(p,f) p = p.integrate();
        REV(i,0,n*m) {
            f[i].a[0] -= f[i].eval(points[i]);
            REV(j,max(0,i-m),i) {
                f[i].a[0] += f[j].eval(points[j+1]);
                if(j != i-m) {
                    f[i].a[0] -= f[j].eval(points[j]);
                } else {
                    f[i] -= f[i-m].getXShift(mi(0) - 1ll);
                }
            }
        }
        REP(i,xpos[curX],n*m)
            f[i].a = {0};
    }
    FOR(p,f) p = p.integrate();

    mi ans = 0;
    RE(i,n*m) {
        ans += f[i].eval(points[i+1]);
        ans -= f[i].eval(points[i  ]);
    }
    OUTL(ll(ans));
}
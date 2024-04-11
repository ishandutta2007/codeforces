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
#define INF 1e9
#define EPS 1e-9
#define pb push_back
#define popb pop_back
#define fi first
#define se second
#define sz size()

// input
template<class T> void IN(T& x) {cin >> x;}
template<class H, class... T> void IN(H& h, T&... t) {IN(h); IN(t...); }

// output
template<class T1, class T2> void OUT(const pair<T1,T2>& x);
template<class T> void OUT(const T& x) {cout << x;}
template<class H, class... T> void OUT(const H& h, const T&... t) {OUT(h); OUT(t...); }
template<class T1, class T2> void OUT(const pair<T1,T2>& x) {OUT(x.fi," ",x.se);}
template<class... T> void OUTL(const T&... t) {OUT(t..., "\n"); }

//===================//
//  Added libraries  //
//===================//

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
    mi  operator+ (ll rs) {
        ll res = value+rs;
        if(res > MOD) res -= MOD;
        return res;
    }
    mi  operator- (ll rs) {return mod(value-rs+MOD);}
    mi  operator* (ll rs) {return mod(value*rs);}
    mi  operator/ (ll rs) {return mod(value*inv(rs));}
    mi& operator+=(ll rs) {*this = (*this)+rs; return *this;}
    mi& operator-=(ll rs) {*this = (*this)-rs; return *this;}
    mi& operator*=(ll rs) {*this = (*this)*rs; return *this;}
    mi& operator/=(ll rs) {*this = (*this)/rs; return *this;}
    operator ll&() {return value;}

    ll value;
};
typedef vector<mi> vmi;

//===================//
//end added libraries//
//===================//

void program();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    program();
}


//===================//
//   begin program   //
//===================//

const int MX = (1<<18)+2;
int n, m, BIT;
int N[18];
int LSB[MX];
map<int,int> dp[MX];

void program() {
    IN(n,m);
    RE(i,n) N[i] = 0;
    RE(i,m) {
        int u, v;
        IN(u,v);
        u--; v--;
        N[u] |= (1<<v);
        N[v] |= (1<<u);
    }
    BIT = (1<<n);
    RE(i,n) LSB[1<<i]=i;

    dp[0][BIT-1] = 1;
    RE(a,BIT) {
        FOR(p,dp[a]) {
            int b=p.fi;
            mi curDP = p.se;
            int nb=b;
            while(nb) {
                int lsb=(nb&-nb);
                int i=LSB[lsb];
                nb -= lsb;
                int A = a|(1<<i);
                int B = b&(~((1<<(i+1))-1)) | (N[i]&(~a));
                auto& DP = dp[A][B];
                DP = mi(DP)+curDP;
            }
        }
        if(a != BIT-1) dp[a].clear();
    }
    OUTL(ll((mi)dp[BIT-1][0]*mi(m)/mi(2)));
}
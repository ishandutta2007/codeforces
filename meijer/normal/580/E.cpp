#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> lll;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

// mod library
ll MOD=1e9+7;

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

const ll MX = 5e5;
ll n, m, k;
string s;
mi has[10];
mi a[MX];
mi SEG[MX*4], LAZY[MX*4];
mi sumPower[MX];
mi sd;

mi power(ll x) {
    if(x == 0) return 1;
    mi a=power(x/2);
    a = a*a;
    if(x%2) a*=sd;
    return a;
}
void buildSeg(ll p=0, ll l=0, ll r=n-1) {
    LAZY[p] = 0;
    if(l == r) {
        SEG[p] = a[l];
        return;
    }
    ll m=(l+r)/2;
    buildSeg(p*2+1,l,m);
    buildSeg(p*2+2,m+1,r);
    SEG[p] = SEG[p*2+1]+SEG[p*2+2]*power(m-l+1);
}
mi getSeg(ll i, ll j, mi lazy=0, ll p=0, ll l=0, ll r=n-1) {
    if(lazy != 0) {
        SEG [p] = lazy*sumPower[r-l];
        LAZY[p] = lazy;
    }
    if(j < l || i > r) return 0;
    if(i <= l && j >= r) return SEG[p];
    ll m=(l+r)/2;
    mi a=getSeg(i,j,LAZY[p],p*2+1,l,m);
    mi b=getSeg(i,j,LAZY[p],p*2+2,m+1,r);
    LAZY[p] = 0;
    if(i > m) return b;
    return a+b*power(m-max(i,l)+1);
}
void setSeg(ll i, ll j, mi value, mi lazy=0, ll p=0, ll l=0, ll r=n-1) {
    if(lazy != 0) {
        SEG [p] = lazy*sumPower[r-l];
        LAZY[p] = lazy;
    }
    if(j < l || i > r) return;
    if(i <= l && j >= r) {
        SEG [p] = value*sumPower[r-l];
        LAZY[p] = value;
        return;
    }
    ll m=(l+r)/2;
    setSeg(i,j,value,LAZY[p],p*2+1,l,m);
    setSeg(i,j,value,LAZY[p],p*2+2,m+1,r);
    SEG [p] = SEG[p*2+1]+SEG[p*2+2]*power(m-l+1);
    LAZY[p] = 0;
}

void program() {
    cin>>n>>m>>k>>s;
    RE(i,n) s[i]-='0';
    RE(i,10) has[i] = rng()%MOD;
    sd = rng()%MOD;
    RE1(i,n) a[i] = has[s[i-1]];
    n++;
    buildSeg();
    sumPower[0] = 1;
    REP(i,1,n+10) {
        sumPower[i] = sumPower[i-1]+power(i);
    }
    RE(i,m+k) {
        ll t, l, r, c; cin>>t>>l>>r>>c;
        if(t == 2) {
            bool pos = getSeg(l, r-c) == getSeg(l+c, r);
            cout<<(pos ? "YES" : "NO")<<endl;
        } else {
            setSeg(l,r,has[c]);
        }
    }
}
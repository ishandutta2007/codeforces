#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
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

const int MX = 5e5;
int n, m, a[MX];
mi f[MX];

void program() {
    cin>>n;
    RE(i,n) cin>>a[i];
    m = 0; RE(i,n) m+=a[i];
    f[0] = n-1;
    mi mINV = mi(1)/mi(m);
    mi n1INV = mi(1)/mi(n-1);
    REP(i,1,m) {
        f[i] = (mi(i)*mi(n-1)*(f[i-1]+mi(1))+mi(m-i)*mi(n-1))/mi(m-i);
    }
    REV(i,0,m-1) f[i] += f[i+1];
    mi ans = 0;
    RE(i,n) ans += f[a[i]];
    ans -=  mi(n-1)*f[0];
    ans /= mi(n);
    cout<<ans<<endl;
}
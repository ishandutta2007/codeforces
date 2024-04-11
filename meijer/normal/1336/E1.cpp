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

const ll MX = 5e5, BITS=36, BM=(1<<15);
ll n, m, a[MX];
ll basis[BITS], b[BITS], k=0;
mi f[BITS][BITS][BM];
mi p[BITS], ans[BITS];

void addBasis(ll x) {
    RE(i,m) {
        if(!(x&(1LL<<i))) continue;
        if(!basis[i]) {
            basis[i] = x;
            k++;
            return;
        }
        x ^= basis[i];
    }
}

void program() {
    cin>>n>>m;
    RE(i,n) cin>>a[i];
    RE(i,n) addBasis(a[i]);
    REV(i,0,m) {
        if(!basis[i]) continue;
        REP(j,i+1,m) {
            if(!basis[j]) continue;
            if(!(basis[i]&(1LL<<j))) continue;
            basis[i] ^= basis[j];
        }
    }
    ll N = m-k;
    if(k <= 23) {
        vll BAS;
        RE(i,m) if(basis[i]) BAS.pb(basis[i]);
        RE(bm,(1LL<<k)) {
            ll cur=0;
            RE(i,k) if(bm&(1LL<<i)) cur ^= BAS[i];
            p[__builtin_popcountll(cur)]++;
        }
    } else {
        ll BMN = (1LL<<N);
        RE(i,m) {
            b[i] = 0;
            ll x=0;
            RE(j,m) {
                if(basis[j]) continue;
                if(basis[i]&(1LL<<j)) b[i] |= (1LL<<x);
                x++;
            }
        }
        f[0][1][b[0]] = (basis[0] ? 1 : 0);
        RE(i,m) f[i][0][0] = 1;
        REP(i,1,m) REP(j,1,k+1) RE(bm,BMN) {
            f[i][j][bm] = f[i-1][j][bm] + (basis[i] ? f[i-1][j-1][bm^b[i]] : mi(0));
        }
        RE(j,k+1) RE(bm,BMN) if(j+__builtin_popcountll(bm) <= m)
            p[j+__builtin_popcountll(bm)] += f[m-1][j][bm];
    }
    mi mp = modpow(2,n-k);
    RE(i,m+1) ans[i] = p[i]*mp;
    RE(i,m+1) cout<<(i==0?"":" ")<<ans[i]; cout<<endl;
}
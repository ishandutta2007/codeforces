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

const int MX = 7e5;
int n, q, m;
mi p[MX];
mi pow2[MX];
mi pow2n[MX];
mi twoInv;
mi I[MX], X[MX];

mi val[MX*4], lVal[MX*4], rVal[MX*4];
int cnt[MX*4];
int SA[MX], RSA[MX];
int curSA[MX];

void buildSeg(int p=0, int l=0, int r=m-1) {
    val[p] = 0;
    lVal[p] = 0;
    rVal[p] = 0;
    cnt[p] = 0;
    if(l == r) {
        return;
    }
    int m=(l+r)/2;
    buildSeg(p*2+1,l,m);
    buildSeg(p*2+2,m+1,r);
}
void setSeg(int i, mi v, int p=0, int l=0, int r=m-1) {
    if(i < l || i > r) return;
    if(l == r) {
        if(v) {
            val[p] = 0;
            lVal[p] = v;
            rVal[p] = v*twoInv;
            cnt[p] = 1;
        } else {
            val[p] = 0;
            lVal[p] = 0;
            rVal[p] = 0;
            cnt[p] = 0;
        }
        return;
    }
    int m=(l+r)/2;
    setSeg(i, v, p*2+1, l, m);
    setSeg(i, v, p*2+2, m+1, r);
    val[p] = val[p*2+1]+val[p*2+2]+lVal[p*2+1]*rVal[p*2+2]*pow2n[cnt[p*2+1]];
    lVal[p] = lVal[p*2+1]+lVal[p*2+2]*pow2[cnt[p*2+1]];
    rVal[p] = rVal[p*2+1]+rVal[p*2+2]*pow2n[cnt[p*2+1]];
    cnt[p] = cnt[p*2+1]+cnt[p*2+2];
}

void program() {
    cin>>n;
    RE(i,n) cin>>p[i];
    cin>>q;
    RE(i,q) cin>>X[i]>>p[n+i], X[i]--;
    m = n+q;

    pow2[0] = pow2n[0] = 1;
    twoInv = mi(1)/mi(2);
    REP(i,1,m+5) pow2[i] = pow2[i-1]*mi(2);
    REP(i,1,m+5) pow2n[i] = pow2n[i-1]*twoInv;
    
    RE(i,m) SA[i] = i;
    sort(SA, SA+m, [](int i, int j) {
        return p[i] < p[j];
    });
    RE(i,m) RSA[SA[i]] = i;
    buildSeg();
    RE(i,n) setSeg(RSA[i], p[i]);
    RE(i,n) curSA[i] = RSA[i];
    cout<<val[0]<<endl;
    RE(i,q) {
        setSeg(curSA[X[i]], 0);
        setSeg(RSA[n+i], p[n+i]);
        curSA[X[i]] = RSA[n+i];
        cout<<val[0]<<endl;
    }
}
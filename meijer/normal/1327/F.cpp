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

const int MX = 6e5;
int n, k, m, l[MX], r[MX], x[MX];
int a[MX];
int cb;
int SEGA[MX*4];
int mn[MX];
ll dpSum[MX];

void addSegA(int i, int j, int x, int p=0, int l=0, int r=n) {
	if(j < l || i > r) return;
	if(i <= l && j >= r) {
		SEGA[p] |= x;
		return;
	}
	int m=(l+r)/2;
	addSegA(i,j,x,p*2+1,l,m);
	addSegA(i,j,x,p*2+2,m+1,r);
}
int getSegA(int i, int p=0, int l=0, int r=n) {
	if(i < l || i > r) return 0;
	if(l == r) return SEGA[p];
	int m=(l+r)/2;
	int a=getSegA(i,p*2+1,l,m);
	int b=getSegA(i,p*2+2,m+1,r);
	return a|b|SEGA[p];
}

void program() {
	cin>>n>>k>>m;
	RE(i,m) cin>>l[i]>>r[i]>>x[i], l[i]--, r[i]--;
	RE(i,(n+1)*4) SEGA[i]=0;
	RE(i,m) addSegA(l[i], r[i], x[i]);
	REI(i,0,n) a[i] = getSegA(i);

	mi ans = 1;
	RE(currentBit,k) {
		cb=currentBit;
		REI(i,0,n) mn[i]=-1;
		RE(i,m) {
			if(x[i] & (1<<cb)) continue;
			mn[r[i]+1] = max(mn[r[i]+1], l[i]);
		}
		RE1(i,n) mn[i]=max(mn[i],mn[i-1]);
		REI(i,0,n) {
			ll cur=0;
			if((a[i]&(1<<cb)) == 0) {
				if(i != 0) cur=dpSum[i-1];
				if(mn[i] >= 1) cur-=dpSum[mn[i]-1];
				if(mn[i] == -1) cur++; // all ones
				cur %= MOD;
			}
			if(i == 0) dpSum[i] = cur;
			else dpSum[i] = dpSum[i-1]+cur;
		}
		mi mult = dpSum[n]-dpSum[n-1];
		ans *= mult;
	}
	cout<<ans<<endl;
}
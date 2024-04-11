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
    operator const ll&() const {return value;}

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

const int MX = 3e5;
int n, q;
string t;
int cnt[MX];
int start=0;
ll seed;
ll invSeed;
mi modPowSeed[MX];

struct State {
	int l=0, r=0, length=0;
	mi hash=0;

	void print() {
		cout<<l<<" "<<r<<" "<<length<<" "<<hash<<endl;
	}
	bool operator!=(const State& O) const {
		return l!=O.l || r!=O.r || length!=O.length || hash!=O.hash;
	}
};

State merge(State L, State R) {
	if(L.r == 1 && R.l == 1) {
		L.length--; R.length--;
		R.hash *= invSeed;
		L.r = 0; R.l = 0;
		if(L.length == 0) L.l=0;
		if(R.length == 0) R.r=0;
	}
	if(R.length != 0 && L.length != 1 && L.r) {
		L.hash += modPowSeed[L.length-1];
	}
	if(L.length != 0 && R.length != 1 && R.l) {
		R.hash += 1LL;
	}
	State n;
	n.l = L.l;
	n.r = R.r;
	if(L.length == 0) n.l = R.l;
	if(R.length == 0) n.r = L.r;
	n.length = L.length + R.length;
	n.hash 	 = L.hash + R.hash*modPowSeed[L.length];
	return n;
}

State SEG[MX*4];
void buildSeg(int p=0, int l=0, int r=n-1) {
	if(l == r) {
		SEG[p].length 	= 1;
		SEG[p].l 		= t[l];
		SEG[p].r 		= t[l];
		SEG[p].hash 	= 0;
		return;
	}
	int m=(l+r)/2;
	buildSeg(p*2+1,l,m);
	buildSeg(p*2+2,m+1,r);
	SEG[p] = merge(SEG[p*2+1], SEG[p*2+2]);
}
State getSeg(int i, int j, int p=0, int l=0, int r=n-1) {
	if(j < l || i > r) return {};
	if(i <= l && j >= r) return SEG[p];
	int m=(l+r)/2;
	State a = getSeg(i,j,p*2+1,l,m);
	State b = getSeg(i,j,p*2+2,m+1,r);
	return merge(a,b);
}

void program() {
	cin>>n>>t;
	RE(i,n) t[i]-='0';
	cnt[0] = 0;
	RE(i,n) cnt[i+1]=cnt[i]+t[i];

	seed = 2;
	invSeed = inv(seed);
	modPowSeed[0] = 1;
	REP(i,1,n+1) modPowSeed[i] = modPowSeed[i-1]*seed;
	buildSeg();

	cin>>q;
	RE(i,q) {
		int l1, l2, len; cin>>l1>>l2>>len; l1--; l2--;
		bool pos=1;
		if(cnt[l1+len]-cnt[l1] != cnt[l2+len]-cnt[l2]) pos = 0;
		if(getSeg(l1,l1+len-1) != getSeg(l2,l2+len-1)) pos = 0;
		cout<<(pos?"Yes":"No")<<endl;
	}
}
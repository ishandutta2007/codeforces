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
int n;
vi adj[MX], chl[MX];
mi dp[MX][3];
mi ways[MX][3];

void dfsChl(int u=1, int p=0) {
	for(int v:adj[u]) if(v != p) dfsChl(v,u), chl[u].pb(v);
}
mi getAns(int u=1, int j=0) {
	if(j==0) {
		for(int v:chl[u]) {
			getAns(v,0);
			getAns(v,1);
			getAns(v,2);
		}
	}
	mi ans=0;

	// not yellow
	mi totWays=1;
	for(int v:chl[u]) totWays *= (ways[v][0]+ways[v][1]);
	for(int v:chl[u]) {
		mi curWays = totWays / (ways[v][0]+ways[v][1]);
		ans += curWays*dp[v][0];
		ans += curWays*dp[v][1];
	}
	if(j == 0) {
		mi impWays=1;
		for(int v:chl[u]) impWays *= ways[v][0];
		ans -= impWays;
	}
	ways[u][j] = totWays;

	// is yellow
	if(j == 0) {
		mi totWays=1;
		mi impWays=1;
		for(int v:chl[u]) totWays *= (ways[v][0]+ways[v][2]);
		for(int v:chl[u]) impWays *= ways[v][0];
		for(int v:chl[u]) {
			mi curWays = totWays / (ways[v][0]+ways[v][2]);
			ans += curWays*dp[v][0];
			ans += curWays*dp[v][2];
			ans -= (impWays/ways[v][0])*dp[v][0];
		}
		ways[u][j] += totWays-impWays;
	}
	if(j == 1) {
		mi totWays=1;
		for(int v:chl[u]) totWays *= (ways[v][0]+ways[v][2]);
		for(int v:chl[u]) {
			mi curWays = totWays / (ways[v][0]+ways[v][2]);
			ans += curWays*dp[v][0];
			ans += curWays*dp[v][2];
		}
		ways[u][j] += totWays;
	}

	if(j == 0) ans += ways[u][j];
	dp[u][j]=ans;
	return ways[u][j];
}

void program() {
	cin>>n;
	RE(i,n-1) {
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfsChl();
	cout<<getAns(1,0)-(mi)1<<endl;
}
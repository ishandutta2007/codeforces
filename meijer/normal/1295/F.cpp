#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vi;
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

//===================//
//  Added libraries  //
//===================//

// mod library
const ll MOD=998244353;

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

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	program();
}



//===================//
//   begin program   //
//===================//

const int MX = 200;
int n, l[MX], r[MX], m=0;
int lSeg[MX], rSeg[MX];
set<int> segPoints;
int segBeg[MX];
mi dp[MX][MX];

mi bico(mi n, mi k) {
	if(k == 0) return 1;
	return bico(n,k-mi(1))*mi(n-k+mi(1))/k;
}
mi getAns(int i, int j) {
	// dp[i][j] = number of prefixes of length i where all the elements belong to one of the first j segments
	if(dp[i][j] == -1) {
		if(i == 0) return dp[i][j] = 1;
		if(j == 0) return dp[i][j] = 0;

		mi ans=getAns(i,j-1);
		RE1(k,i) {
			if(lSeg[i-k] >= m-j || rSeg[i-k] < m-j) break;
			ans += getAns(i-k, j-1) * bico(segBeg[m-j]-segBeg[m-j-1]+k-1,k);
		}
		dp[i][j] = ans;
	}
	return dp[i][j];
}

void program() {
	cin>>n;
	RE(i,n) cin>>l[i]>>r[i], r[i]++;
	RE(i,n) segPoints.insert(l[i]), segPoints.insert(r[i]);
	for(int i:segPoints) segBeg[m++] = i;
	RE(i,MX) RE(j,MX) dp[i][j] = -1;
	
	RE(i,n) {
		RE(j,m) {
			if(segBeg[j] == l[i]) lSeg[i] = j;
			if(segBeg[j] == r[i]) rSeg[i] = j;
		}
	}

	mi correct = getAns(n,m-1);
	mi total = 1;
	RE(i,n) total *= mi(r[i]-l[i]);

	cout << correct/total << endl;
}
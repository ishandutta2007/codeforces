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

//===================//
//  Added libraries  //
//===================//

// mod library
const ll MOD=1e9+7;

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

const int MX = 5e5;
int N, M;
mi dp[1005][1005][11];
mi sm[1005][1005][11];

mi getDP(int a, int b, int m) {
	if(dp[a][b][m] == -1) {
		if(m == 0) {
			return dp[a][b][m] = 1;
		} else {
			if(a > b) return dp[a][b][m] = 0;
			mi ans = getDP(a, b-1, m);
			REP(i,a,b+1) {
				ans += getDP(i,b,m-1);
			}
			dp[a][b][m] = ans;
		}
	}
	return dp[a][b][m];
}

void program() {
	cin>>N>>M;
	RE(m,M+1) {
		RE1(b,N) {
			REV(a,1,N+1) {
				if(m == 0) dp[a][b][m] = 1;
				else if(a > b) dp[a][b][m] = 0;
				else {
					mi ans = dp[a][b-1][m];
					ans += sm[b][b][m-1] - sm[a-1][b][m-1];
					dp[a][b][m] = ans;
				}
			}
			sm[0][b][m] = 0;
			RE1(a,N) sm[a][b][m] = sm[a-1][b][m]+dp[a][b][m];
		}
	}
	cout<<dp[1][N][M]<<endl;
}
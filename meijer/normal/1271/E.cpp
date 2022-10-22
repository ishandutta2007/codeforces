#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
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

//===================//
//  Added libraries  //
//===================//

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

const ll MX=4e5;
ll k, n;

ll getWays(ll y) {
	ll ans=0LL;
	bool even = !(y&1LL);
	RE(i,63) {
		ll x = y<<i;
		if(x > n || x < y) break;
		ll lb = x, ub = x + (1LL<<(i+even)) - 1LL;
		ub = min(ub, n);
		ans += ub-lb+1LL;
	}
	return ans;
}
ll getBestEven() {
	ll lb=0LL, ub=n/2LL;
	while(lb != ub) {
		ll mid=(lb+ub+1LL)/2LL;
		if(getWays(mid*2LL) >= k) lb = mid;
		else ub = mid-1LL;
	}
	return lb*2LL;
}
ll getBestOdd() {
	ll lb=0LL, ub=(n-1LL)/2LL;
	while(lb != ub) {
		ll mid=(lb+ub+1LL)/2LL;
		if(getWays(mid*2LL+1LL) >= k) lb = mid;
		else ub = mid-1LL;
	}
	return lb*2+1;
}

void program() {
	cin>>n>>k;
	ll bestE=getBestEven(), bestO=getBestOdd();
	cout<<max(bestE,bestO)<<endl;
}
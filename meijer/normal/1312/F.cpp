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

const ll MX = 5e5;
ll t, n, x, y, z, a[MX], nim[MX];
ll dp[MX][3];
ll Beg, End;

ll minEx(set<ll>& s) {
	ll i=0;
	while(s.count(i)) i++;
	return i;
}
ll getDP(ll i, ll j) {
	if(i < 0) return 0;
	return dp[i][j];
}
ll getNim(ll x, ll j=0) {
	if(x > End) {
		ll y = x-Beg;
		y %= (End-Beg);
		return dp[y+Beg][j];
	} else {
		if(x < 0) return 0;
		return dp[x][j];
	}
}
ll mostSignBit(ll x) {
	REV(i,0,20) if(x&(1<<i)) return i;
}

void program() {
	cin>>t;
	while(t--) {
		cin>>n>>x>>y>>z;
		RE(i,3) dp[0][i] = 0;
		map<ll, ll> last;
		last[0] = 0;
		ll cur = 0;
		REP(i,1,MX) {
			RE(j,3) {
				set<ll> s;
				s.insert(getDP(i-x,0));
				if(j != 1) s.insert(getDP(i-y,1));
				if(j != 2) s.insert(getDP(i-z,2));
				dp[i][j] = minEx(s);
			}
			cur *= 36;
			cur = cur%ll(60466176);
			cur += dp[i][0];
			cur += dp[i][1]*4;
			cur += dp[i][2]*12;
			if(last.find(cur) != last.end()) {
				Beg = last[cur];
				End = i;
				break;
			} else {
				last[cur] = i;
			}
		}
		RE(i,n) cin>>a[i];
		ll xOr = 0;
		RE(i,n) {
			nim[i] = getNim(a[i]);
			xOr ^= nim[i];
		}
		if(xOr == 0) {
			cout<<0<<endl;
		} else {
			ll cnt=0;
			RE(i,n) RE(j,3) {
				ll rem = x;
				if(j == 1) rem = y;
				if(j == 2) rem = z;
				ll nXOR = xOr ^ nim[i] ^ getNim(a[i]-rem,j);
				if(nXOR == 0) cnt++;
			}
			cout<<cnt<<endl;
		}
	}
}
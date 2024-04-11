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
ll T;
ll a, m;
map<ll, ll> getPrimeFact(ll x) {
	map<ll, ll> ans;
	for(ll i=2; i*i<=x; i++) {
		while((x % i) == 0) {
			x /= i;
			ans[i]++;
		}
	}
	if(x != 1) ans[x]++;
	return ans;
}
ll Pow(ll x, ll y) {
	ll ans=1;
	RE(i,y) ans *= x;
	return ans;
}
ll calculateLess(map<ll, ll>& M, ll v) {
	int x = 0;
	for(ii p : M) if(p.se >= 0) x++;
	int BS = (1<<x);
	ll tot = 0;
	RE(i,BS) {
		ll y=1;
		int j=0;
		int cnt=0;
		for(ii p : M) {
			if(p.se >= 0) {
				if(i & (1<<j)) 	y *= Pow(p.fi, p.se+1), cnt++;
				else			y *= Pow(p.fi, p.se);
				j++;	
			} else {
				y *= Pow(p.fi, -p.se);
			}
		}
		if(cnt % 2) tot -= v/y;
		else		tot += v/y;
	}
	return tot;
}

void program() {
	cin>>T;
	while(T--) {
		cin>>a>>m;
		auto pfm = getPrimeFact(m);
		auto pfa = getPrimeFact(a);
		for(ii p : pfm) {
			if(p.se <= pfa[p.fi]) {
				pfm[p.fi] = -p.se;
			} else {
				pfm[p.fi] = pfa[p.fi];
			}
		}
		ll ans = calculateLess(pfm, a+m-1)-calculateLess(pfm, a-1);
		cout << ans << endl;
	}
}
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
 
const ll MX = 3e5, MP=5e6;
ll n, a[MX];
ll ans=INF;
set<ll> lookedAt;
mt19937 rng(time(NULL));

void findAns(ll x) {
	if(lookedAt.count(x)) return;
	lookedAt.insert(x);
	ll cur=0;
	RE(j,n) {
		ll dif = a[j]%x;
		if(dif == 0) continue;
		if(dif == a[j]) {
			cur += x - dif;
		} else {
			cur += min(dif, x-dif);
		}
		if(cur > ans) break;
	}
	ans = min(ans, cur);
}
vll primeFact(ll x) {
	vll ans;
	for(ll i=2; i*i<=x; i++) {
		if(x % i == 0) {
			ans.pb(i);
			while(x % i == 0) x/=i;
		}
	}
	if(x != 1) ans.pb(x);
	return ans;
}
void findAnsBetter(ll x) {
	if(x <= 1) return;
	vi a = primeFact(x);
	for(ll i:a) findAns(i);
}
 
void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	findAns(2);

	RE(i,32) {
		ll v = a[rng()%n];
		findAnsBetter(v);
		findAnsBetter(v+1);
		findAnsBetter(v-1);
	}

	cout<<ans<<endl;
}
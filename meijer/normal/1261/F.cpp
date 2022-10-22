#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
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

const ll MX=(1LL<<60), MOD=998244353;
ll n, INV;
ll bm;
vector<ii> segments;
struct Seg {
	vll x[61], y[61];
	void add(ll l, ll r, ll i=0, ll j=MX-1, ll d=60) {
		if(r < i || l > j) return;
		y[d].pb(i);
		if(l <= i && r >= j) {
			x[d].pb(i);
		} else {
			ll m=(i+j)/2;
			add(l,r,i,m,d-1);
			add(l,r,m+1,j,d-1);
		}
	}
} segA, segB;

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
ll calcSum(ll x) {
	return (x%MOD)*(x%MOD+1)%MOD * INV % MOD;
}
ll calcSum(ll x, ll y) {
	return (calcSum(y)-calcSum(x)+MOD)%MOD;
}
ll addSeg(ll a, ll b) {
	ll c = ((a^b)|bm);
	ll d = (c^bm);
	segments.pb({d,c});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n; INV = inv(2);
    RE(i,n) {
    	ll l, r; cin>>l>>r;
    	segA.add(l,r);
    }
    cin>>n;
    RE(i,n) {
    	ll l, r; cin>>l>>r;
    	segB.add(l,r);
    }
    RE(i,61) {
    	bm = ((1LL<<i)-1);;
    	for(ll a:segA.x[i])
    		for(ll b:segB.x[i])
    			addSeg(a,b);
    	for(ll a:segA.x[i])
    		for(ll b:segB.y[i])
    			addSeg(a,b);
    	for(ll a:segA.y[i])
    		for(ll b:segB.x[i])
    			addSeg(a,b);
    }
    sort(segments.begin(), segments.end());
    ll mostR = 0, ans=0;
    for(ii p : segments) {
    	mostR = max(mostR, p.fi-1);
    	if(mostR > p.se) continue;
    	ans += calcSum(mostR, p.se);
    	mostR = p.se;
    }
    ans %= MOD;
    cout<<ans<<endl;
}
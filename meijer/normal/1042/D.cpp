#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=3e5;

ll n, a[MX], sum[MX], dif[MX], m, t;
ll f[MX];

void addF(ll x) {
	for(++x; x<=m; x += (x&(-x)))
		f[x]++;
}
void remF(ll x) {
	for(++x; x<=m; x += (x&(-x)))
		f[x]--;
}
ll getF(ll x) {
	ll ans=0;
	for(++x; x; x -= (x&(-x)))
		ans += f[x];
	return ans;
}
ll lb(ll x) {
	return lower_bound(dif,dif+m,x)-dif;
}
ll ub(ll x) {
	return upper_bound(dif,dif+m,x)-dif;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>t;
	RE(i,n) cin>>a[i];

	sum[0] = 0;
	RE(i,n) sum[i+1] = sum[i]+a[i];

	m = n+1;
	RE(i,m) dif[i] = sum[i];
	sort(dif, dif+m);
	m = unique(dif, dif+m)-dif;

	ll ans=0;
	RE(i,n+1) addF(lb(sum[i]));

	RE(i,n) {
		remF(lb(sum[i]));
		ans += getF(lb(t+sum[i])-1);
	}
	cout<<ans<<endl;
}
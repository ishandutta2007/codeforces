#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
ll f[5008];
ll g[5008];
ll a[5008];
int main() {
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(300);
	ll n; cin >> n;
	for (ll i=0;i<n;i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	for (ll x=0;x<5008;x++) f[x]=0;
	ll total=0;
	for (ll i=0;i<n;i++) {
		for (ll j=i+1;j<n;j++) {
			ll x=a[j]-a[i];
			f[x]++;
			total++;
		}
	}
	ld norm = total*total*total;
	g[5002]=0;
	for (ll x=4999;x>=0;x--) {
		g[x] = g[x+1]+f[x+1];
	}
	ld ans = 0;
	for (ll x=1;x<=5002;x++) {
		for (ll y=1;y<=5002;y++) {
			ll v=x+y;
			if (x+y>5002) continue;
			ld add = f[x]*f[y]*g[v];
			//if (x==1&&y==1) printf("%d %d %d: %d %d %d %f %f\n",x,y,v,f[x],f[y],g[v],add,add/norm);
			ans += add/norm;
		}
	}
	cout << ans << endl;
}
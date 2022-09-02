#include <bits/stdc++.h>
using namespace std;
 
#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;
 
int n;
ll a[200020];
pll A[200020];
const int L = 1e6 + 5;
bitset <L+10> isp;
ll XT[400040];
 
void solve() {
	isp.reset();
	for(int i=2;i<=L;i++) isp[i] = true;
	for(int i=2;i<=L;i++) if(isp[i]) {
		for(int j=i+i;j<=L;j+=i) isp[j] = false;
	}
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%lld", a + i);
	int ans = 0;
	for(int i=1;i<=n;i++) if(a[i] % 2) ++ans;
	map <ll, ll> Mx;
	for(int i=1;i<=n;i++) Mx[a[i]]++;
	int m = 0;
	for(auto e : Mx) A[++m] = e;
 
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(A+1, A+1+m, rng);
 
	ll lv = max(1ll, a[1] - (n-1));
	ll rv = a[1] + (n-1);
	for(int i=0;i<=rv-lv;i++) XT[i] = lv + i;
	vector <ll> PL;
	for(int i=2;i<=L;i++) if(isp[i]) {
		ll t = (lv + i - 1) / i * i;
		int ok = 0;
		for(ll j=t;j<=rv;j+=i) {
			ok = 1;
			while(XT[j-lv] % i == 0) XT[j-lv] /= i;
		}
		if(ok) PL.pb(i);
	}
	for(int i=0;i<=rv-lv;i++) if(XT[i] > 1) PL.pb(XT[i]);
 
	shuffle(all(PL) ,rng);
	for(ll p : PL) {
		ll c = 0;
		for(int i=1;i<=m;i++) {
			ll a = A[i].Fi, mul = A[i].Se;
			ll v = -1;
			if(a < p) v = p - a;
			else {
				a %= p;
				v = min(a, p-a);
			}
			c += mul * v;
			if(c >= ans) break;
		}
		if(ans > c) ans = c;
	}
 
	printf("%d\n", ans);
}
 
int main() {
	int t = 1; //scanf("%d", &t);
	rep(tt, t) {
		solve();
	}
	return 0;
}
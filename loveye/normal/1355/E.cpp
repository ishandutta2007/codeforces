#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,a,b,m,h[N];
long long sum[N],ans = 9e18;
typedef long long ll;
long long calc(ll i,ll l,ll r) {
	ll k0 = m*i-b*n,b0 = b*sum[n] - m*sum[i];
	if(k0 < 0) return k0*r + b0;
	else return k0*l + b0;
}
long long calc2(ll i,ll l,ll r) {
	ll k0 = a*n-m*n+m*i,b0 = m*sum[n]-a*sum[n]-m*sum[i];
	if(k0 < 0) return k0*r + b0;
	else return k0*l + b0;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> a >> b >> m;m = min(m,a+b);
	for(int i = 1;i <= n;++i)
		cin >> h[i];
	sort(h+1,h+n+1);
	for(int i = 1;i <= n;++i)
		sum[i] = sum[i-1] + h[i];
	double mean = sum[n] / (double)(n);
	int p = upper_bound(h+1,h+n+1,(int)(mean)) - h - 1;
	for(int i = 1;i < n;++i) {
		if(i == p) continue;
		if(h[i] < mean) ans = min(ans,calc(i,h[i],h[i+1]));
		else ans = min(ans,calc2(i,h[i],h[i+1]));
	}
	ans = min(ans,min(calc(p,h[p],floor(mean)),calc2(p,ceil(mean),h[p+1])));
	cout << ans << endl;	
	return 0;
}
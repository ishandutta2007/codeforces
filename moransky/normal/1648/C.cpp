#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000100
#define inf 1<<30
#define ll long long
const ll mod = 998244353;
ll n, m, cnt[MAXN], last, len, b[MAXN], cntb, c[MAXN], mx, tw[MAXN];
ll rmx[MAXN];
ll ans, a[MAXN];
void change(ll i, ll s){for(;i<=mx;i+=(i&(-i))) c[i]+=s;}
ll Sum(ll i){ll sum=0; for(;i;i-=(i&(-i))) sum += c[i]; return sum;}
int main()
{
	ll u;
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) 
		scanf("%lld",&u), cnt[u]++, mx = max(mx, u);
	mx = max(mx, max(n, m));
	for(ll i=1;i<=m;i++) scanf("%lld",&b[i]), mx = max(mx, b[i]);
	tw[1] = tw[0] = 1;
	for(ll i=2;i<=mx;i++) 
		tw[i] = (mod - mod/i) * tw[mod%i] % mod;
	rmx[0] = 1;
	for(ll i=1;i<=mx;i++) rmx[i] = rmx[i-1] * tw[i] % mod;
	ll sum = 1;
	for(ll i=1;i<=mx;i++) change(i, cnt[i]);
	for(ll i=1;i<=n;i++) sum = sum*i % mod;
	for(ll i=1;i<=mx;i++)
		sum = sum*rmx[cnt[i]]%mod;
//	cout<<sum<<endl;
	for(ll i=1;i<=m;i++)
	{
		ans = (ans + sum * Sum(b[i]-1) % mod * tw[n-i+1] % mod) % mod;
		if(cnt[b[i]] == 0) break;
		if(i == n && n < m) {
			ans++;
		}
		
		sum = sum * tw[n-i+1] % mod * cnt[b[i]] % mod;
//		printf("%lld %lld\n",sum,sum * Sum(b[i]-1) % mod * tw[n-i+1] % mod);
		change(b[i], -1);
	//	if (!cnt[b[i]]) break;
		cnt[b[i]]--;
	}
	printf("%lld\n",ans%mod);

	return 0;
}
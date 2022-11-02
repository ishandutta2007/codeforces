#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;

ll inv=500000004;

ll n,m;

ll rc(ll a, ll b1, ll b2){
	b1=max(b1, a+1);
	b2=min(b2, m);
	if (b1>b2) return 0;
	ll s0=n%(a*b1);
	s0%=mod;
	ll k=(b2-b1+1);
	k%=mod;
	ll s=k*((s0+s0-((k-1+mod)%mod)*(a%mod)+mod)%mod);
	s%=mod;
	s*=inv;
	s%=mod;
	return s;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	ll b=n;
	ll v=0;
	if(m>n){
		v=((m-n)%mod)*(n%mod);
		v%=mod;
		m=n;
	}
	for (ll i=1;i<=n;i++){
		ll mi=0;
		ll ma=b;
		while(mi<=ma){
			ll mid=(mi+ma)/2;
			if (mid*i<=n){
				mi=mid+1;
			}
			else{
				ma=mid-1;
			}
		}
		//cout<<i<<" "<<ma<<endl;
		//cout<<i-1<<" "<<ma+1<<" "<<b<<" "<<rc(i-1, ma+1, b)<<endl;
		if (i>1) v+=rc(i-1, ma+1, b);
		v%=mod;
		b=ma;
		if (i<=b&&i<=m){
			v+=n%i;
			v%=mod;
		}
		else{
			break;
		}
	}
	cout<<v<<endl;
}
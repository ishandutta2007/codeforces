#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int N=2e5;
const ll md=1e9+7;

ll a[N+5],f[N+5];
pll b[N+5];

map<ll,int> mp;

int main() {
	std::ios::sync_with_stdio(false);
	
	ll T=1;
	while(T--) {
		ll n,p;
		cin>>n>>p;
		
		f[0]=1,f[1]=1;
		for(int i=2;i<=p;i++) f[i]=(f[i-1]+f[i-2])%md;
		for(int i=1;i<=p;i++) f[i]=(f[i]+f[i-1])%md;
		
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		
		for(int i=1;i<=n;i++) {
			ll x=a[i];
			bool flg=true;
			while(x) {
				if(mp.count(x)) flg=false; 
				if(x&1) x>>=1LL;
				else if(x%4==0) x>>=2LL;
				else break;
			} 
			if(!flg) a[i]=0;
			else mp[a[i]]++;
		}
		
		ll ans=0;
		for(int i=1;i<=n;i++) {
			if(a[i]==0) continue;
			ll s=log2(a[i])+1;
			if(s<=p) ans=(ans+f[p-s])%md;
		}
		
		cout<<ans<<'\n';
		
	} 
	
	return 0;
}

/*

5 10
4 8 9 16 17
7 10
1 4 5 8 16 9 17

*/
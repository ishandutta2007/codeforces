#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

bool can(ll m, vector<ll> a){
	vector<ll> b(SZ(a));
	for(ll i=SZ(a)-1;i>=2;i--){
		ll c=(a[i]+b[i]-m)/3;
		if(c>=0){
			c=min(c,a[i]/3);
			a[i]-=3ll*c;
			b[i-1]+=c;
			b[i-2]+=2ll*c;
		}
	}
	fore(i,0,SZ(a))if(a[i]+b[i]<m)return 0;
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll l=0,r=2e9;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m,a))l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	
	return 0;
}
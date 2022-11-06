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

vector<ll> a;

ll xx;

ll getn(ll x){
	ll mini=a[x],maxi=a[x];
	fore(i,x+1,SZ(a)){
		mini=min(mini,a[i]);
		maxi=max(maxi,a[i]);
		if(maxi-mini>2ll*xx)return i;
	}
	return SZ(a);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>xx;
		a.clear();
		a.resize(n);
		fore(i,0,n)cin>>a[i];
		ll pos=0,res=0;
		while(pos<n){
			pos=getn(pos);
			res++;
		}
		res--;
		cout<<res<<"\n";
	}
	
	return 0;
}
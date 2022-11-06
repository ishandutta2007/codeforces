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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll maxi=-1e18,mini=1e18;
		ll res=1e18,vmx=1e18,vmn=1e18;
		fore(i,0,n){
			ll l,r,c; cin>>l>>r>>c;
			if(maxi<r||l<mini)res=1e18;
			if(maxi<r)vmx=1e18;
			maxi=max(maxi,r);
			if(r==maxi)vmx=min(vmx,c);
			if(l<mini)vmn=1e18;
			mini=min(mini,l);
			if(l==mini)vmn=min(vmn,c);
			res=min(res,vmx+vmn);
			if(l==mini&&r==maxi)res=min(res,c);
			cout<<res<<"\n";
		}
	}
	
	return 0;
}
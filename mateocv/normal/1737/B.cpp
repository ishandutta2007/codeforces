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

ll calc(ll x, ll ty){
	ll l=0,r=1000000009;
	while(l<=r){
		ll m=(l+r)/2;
		ll val=m*m+ty*m;
		if(val<=x)l=m+1;
		else r=m-1;
	}
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r;
		ll res=0;
		fore(k,0,3)res+=calc(r,k);
		fore(k,0,3)res-=calc(l-1,k);
		cout<<res<<"\n";
	}
	
	return 0;
}
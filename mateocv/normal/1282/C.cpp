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
	ll m; cin>>m;
	while(m--){
		ll n,t,aa,bb; cin>>n>>t>>aa>>bb;
		pair<ll,ll> a[n];
		fore(i,0,n)cin>>a[i].snd;
		fore(i,0,n)cin>>a[i].fst;
		//cout<<"LISTO\n";
		sort(a,a+n);
		ll e=0,h=0;
		fore(i,0,n){
			e+=(a[i].snd==0);
			h+=(a[i].snd==1);
		}
		ll te=0,th=0;
		ll resp=0,res=0;
		ll ttt=a[0].fst-1;
		if(ttt>0){
			resp+=min(e,ttt/aa);
			ttt-=min(e,ttt/aa)*aa;
			resp+=min(h,ttt/bb);
			ttt-=min(h,ttt/bb)*bb;
			res=max(res,resp);
		}
		fore(i,0,n){
			te+=(a[i].snd==0);
			th+=(a[i].snd==1);
			if(i<n-1&&a[i].fst==a[i+1].fst)continue;
			ll tt;
			if(i==n-1)tt=t;
			else tt=a[i+1].fst-1;
			ll tot=te*aa+th*bb;
			if(tot>tt)continue;
			ll q=tt-tot;
			resp=te+th;
			resp+=min(e-te,q/aa);
			q-=min(e-te,q/aa)*aa;
			resp+=min(h-th,q/bb);
			q-=min(h-th,q/bb)*bb;
			res=max(res,resp);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
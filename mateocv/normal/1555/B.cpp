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

ll INF=1e18;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll x,xx,y,yy; cin>>x>>y>>xx>>yy;
		ll w,h; cin>>w>>h;
		ll dx=xx-x,dy=yy-y;
		ll res=INF;
		if(dx+w<=n&&max(dy,h)<=m){
			res=min(res,max(w-x,0ll));
			res=min(res,max(xx-(n-w),0ll));
		}
		swap(n,m);
		swap(x,y);
		swap(xx,yy);
		swap(w,h);
		swap(dx,dy);
		if(dx+w<=n&&max(dy,h)<=m){
			res=min(res,max(w-x,0ll));
			res=min(res,max(xx-(n-w),0ll));
		}
		if(res==INF)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	
	return 0;
}
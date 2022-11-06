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

ll cu(ll x, ll y, ll z){
	return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll x,y,z; cin>>x>>y>>z;
		ll a[x],b[y],c[z];
		fore(i,0,x)cin>>a[i];
		fore(i,0,y)cin>>b[i];
		fore(i,0,z)cin>>c[i];
		sort(a,a+x);
		sort(b,b+y);
		sort(c,c+z);
		ll res=4e18;
		fore(i,0,x){
			auto ly=lower_bound(b,b+y,a[i]);
			auto uy=upper_bound(b,b+y,a[i]);
			auto lz=lower_bound(c,c+z,a[i]);
			auto uz=upper_bound(c,c+z,a[i]);
			if(ly!=b+y&&uz!=c){
				res=min(res,cu(a[i],*ly,*(uz-1)));
			}
			if(lz!=c+z&&uy!=b){
				res=min(res,cu(a[i],*lz,*(uy-1)));
			}
		}
		fore(i,0,y){
			auto lx=lower_bound(a,a+x,b[i]);
			auto ux=upper_bound(a,a+x,b[i]);
			auto lz=lower_bound(c,c+z,b[i]);
			auto uz=upper_bound(c,c+z,b[i]);
			if(lx!=a+x&&uz!=c){
				res=min(res,cu(*lx,b[i],*(uz-1)));
			}
			if(lz!=c+z&&ux!=a){
				res=min(res,cu(*lz,b[i],*(ux-1)));
			}
		}
		fore(i,0,z){
			auto lx=lower_bound(a,a+x,c[i]);
			auto ux=upper_bound(a,a+x,c[i]);
			auto ly=lower_bound(b,b+y,c[i]);
			auto uy=upper_bound(b,b+y,c[i]);
			if(ly!=b+y&&ux!=a){
				res=min(res,cu(c[i],*ly,*(ux-1)));
			}
			if(lx!=a+x&&uy!=b){
				res=min(res,cu(c[i],*lx,*(uy-1)));
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
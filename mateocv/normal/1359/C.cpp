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
	ll tt; cin>>tt;
	while(tt--){
		ll h,c,t; cin>>h>>c>>t;
		ll l=0,r=1e9;
		while(l<=r){
			ll m=(l+r)/2;
			if((m+1)*h+m*c>=t*(2*m+1))l=m+1;
			else r=m-1;
		}
		//cout<<l<<" "<<r<<"\n";
		__int128 a[3]={abs(h+c-2*t),abs((l+1)*h+l*c-(2*l+1)*t),abs((r+1)*h+r*c-(2*r+1)*t)};
		__int128 b[3]={2,2*l+1,2*r+1};
		//fore(i,0,3)cout<<(ll)a[i]<<" "<<(ll)b[i]<<"\n";
		ll res=1e18;
		if(a[0]*b[1]<=a[1]*b[0]&&a[0]*b[2]<=a[2]*b[0]){
			res=min(res,2ll);
		}
		if(a[2]*b[0]<=a[0]*b[2]&&a[2]*b[1]<=a[1]*b[2]){
			res=min(res,2*r+1);
		}
		if(a[1]*b[0]<=a[0]*b[1]&&a[1]*b[2]<=a[2]*b[1]){
			res=min(res,2*l+1);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
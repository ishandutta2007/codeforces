#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x,y,d; cin>>n>>x>>y>>d;
		ll res=1e18;
		if((x-y+n*d)%d==0){
			res=min(res,abs(x-y)/d);
		}
		if(y%d==1){
			res=min(res,(x+d-2)/d+(y-1)/d);
		}
		if(y%d==n%d){
			res=min(res,(n-x+d-1)/d+(n-y)/d);
		}
		if(res>=1ll*1e17)cout<<-1<<"\n";
		else cout<<res<<"\n";
	}
	
	return 0;
}
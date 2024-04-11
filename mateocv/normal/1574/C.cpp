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
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	ll s=0;
	for(auto i:a)s+=i;
	ll t; cin>>t;
	while(t--){
		ll x,y; cin>>x>>y;
		ll posx=lower_bound(ALL(a),x)-a.begin();
		ll posy=lower_bound(ALL(a),s-y+1)-a.begin()-1;
		ll res=2e18;
		//cout<<posx<<" "<<posy<<"\n";
		if(posx<n)res=min(res,max(0ll,y-(s-a[posx])));
		if(posy>=0)res=min(res,max(0ll,x-a[posy]));
		if(posy+1<posx)res=min(res,max(0ll,x+y-s));
		cout<<res<<"\n";
	}
	
	return 0;
}
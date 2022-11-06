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

ll solve(ll f, ll cs, ll cw, ll s, ll w){
	//cout<<f<<" "<<cs<<" "<<cw<<" "<<s<<" "<<w<<"\n";
	if(s>w){
		ll res=min(f/w,cw);
		f-=res*w;
		res+=min(f/s,cs);
		//cout<<res<<"\n";
		return res;
	}else{
		ll res=min(f/s,cs);
		f-=res*s;
		res+=min(f/w,cw);
		//cout<<res<<"\n";
		return res;
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll p,f,cs,cw,s,w; cin>>p>>f>>cs>>cw>>s>>w;
		ll res=0;
		fore(i,0,cs+1){
			if(s*i<=p){
				ll uw=min((p-s*i)/w,cw);
				res=max(res,solve(f,cs-i,cw-uw,s,w)+i+uw);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
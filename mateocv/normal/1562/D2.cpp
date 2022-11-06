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
		ll n,q; cin>>n>>q;
		string s; cin>>s;
		vector<ll> sump={0};
		fore(i,0,SZ(s)){
			ll val=((s[i]=='+')?1:-1);
			sump.pb(sump.back()+((i&1)?-val:val));
		}
		while(q--){
			ll l,r; cin>>l>>r; l--;
			if(sump[r]==sump[l])cout<<"0\n";
			else{
				vector<ll> res;
				if(!((r-l)&1)){
					r--;
					res.pb(r);
				}
				ll s=sump[r]-sump[l];
				ll el=l,er=r-1;
				ll br=0;
				while(el<=er){
					ll m=(el+er)/2;
					if(sump[m]+sump[m+1]-2ll*sump[l]==s){
						res.pb(m);
						br++; break;
					}
					if(s>=0){
						if(sump[m]+sump[m+1]-2ll*sump[l]>s)er=m-1;
						else el=m+1;
					}else{
						if(sump[m]+sump[m+1]-2ll*sump[l]>s)el=m+1;
						else er=m-1;
					}
					
				}
				//cout<<el<<" "<<er<<"\n";
				//cout<<l<<" "<<r<<"\n";
				//for(auto i:sump)cout<<i<<" ";
				//cout<<"\n";
				if(!br){
					fore(i,max(l,er-1),min(r-1,el+1)+1){
						if(sump[i]+sump[i+1]-2ll*sump[l]==s){
							res.pb(i);
							br++; break;
						}
					}
				}
				assert(br);
				cout<<SZ(res)<<"\n";
				for(auto i:res)cout<<i+1<<" ";
				cout<<"\n";
			}
		}
	}
	
	return 0;
}
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
		ll n,m; cin>>n>>m;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<string> s(n);
		fore(i,0,n)cin>>s[i];
		ll maxi=0;
		vector<ll> res(m);
		fore(i,0,(1ll<<n)){
			vector<pair<ll,ll>> c(m);
			fore(j,0,n){
				ll p=1;
				if(i&(1ll<<j))p=-1;
				fore(ii,0,m){
					if(s[j][ii]=='1')c[ii].fst+=p;
				}
			}
			fore(ii,0,m)c[ii].snd=ii;
			sort(ALL(c));
			//for(auto i:c)cout<<i.fst<<" "<<i.snd<<"\n";
			ll val=0;
			fore(ii,0,m)val+=(ii+1)*c[ii].fst;
			fore(j,0,n){
				if(i&(1ll<<j))val+=a[j];
				else val-=a[j];
			}
			if(val>=maxi){
				maxi=val;
				fore(ii,0,m)res[c[ii].snd]=ii;
			}
		}
		//cout<<maxi<<"\n";
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}
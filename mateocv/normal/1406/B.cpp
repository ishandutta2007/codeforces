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
		ll n; cin>>n;
		vector<ll> v[2];
		ll c=0;
		fore(i,0,n){
			ll lle; cin>>lle;
			if(lle<0)v[0].pb(lle);
			if(lle>0)v[1].pb(lle);
			if(lle==0)c++;	
		}
		if(c+5>n){
			cout<<"0\n";
			continue;
		}
		fore(k,0,2)sort(ALL(v[k]));
		reverse(ALL(v[1]));
		//for(auto i:v[0])cout<<i<<" "; cout<<"\n";
		//for(auto i:v[1])cout<<i<<" "; cout<<"\n";
		ll res=-9e18;
		fore(i,0,6){
			if(SZ(v[0])>=i&&SZ(v[1])>=5-i){
				//cout<<i<<" "<<5-i<<"\n";
				ll vares=1;
				fore(j,0,i)vares*=v[0][j];
				fore(j,0,5-i)vares*=v[1][j];
				res=max(res,vares);
			}
		}
		fore(k,0,2)reverse(ALL(v[k]));
		fore(i,0,6){
			if(SZ(v[0])>=i&&SZ(v[1])>=5-i){
				//cout<<i<<" "<<5-i<<"\n";
				ll vares=1;
				fore(j,0,i)vares*=v[0][j];
				fore(j,0,5-i)vares*=v[1][j];
				res=max(res,vares);
			}
		}
		if(c==0)cout<<res<<"\n";
		else cout<<max(res,0ll)<<"\n";
	}
	
	
	return 0;
}
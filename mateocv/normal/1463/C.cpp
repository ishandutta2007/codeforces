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

vector<pair<ll,ll>> v;
ll pos[100005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		v.clear();
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			v.pb({x,y});
		}
		ll tl=0,obj=0,vv=0;
		fore(i,0,n){
			if(v[i].fst<tl){
				pos[i]=pos[i-1]+vv*(v[i].fst-v[i-1].fst);
			}else{
				pos[i]=obj;
				if(pos[i]>v[i].snd)vv=-1;
				else if(pos[i]<v[i].snd)vv=1;
				else vv=0;
				obj=v[i].snd;
				tl=v[i].fst+abs(pos[i]-obj);
			}
		}
		pos[n]=obj;
		//fore(i,0,n+1)cout<<pos[i]<<" "; cout<<"\n";
		ll res=0;
		fore(i,0,n){
			ll l=min({pos[i],pos[i+1]});
			ll r=max({pos[i],pos[i+1]});
			res+=(l<=v[i].snd&&v[i].snd<=r);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
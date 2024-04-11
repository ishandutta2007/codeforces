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
	vector<ll> ub(500005,-1),an(500005,-1);
	vector<ll> v;
	ll q; cin>>q;
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll x; cin>>x;
			if(ub[x]==-1){
				ub[x]=SZ(v);
				v.pb(x);
			}else{
				an[SZ(v)]=ub[x];
				v.pb(-1);
			}
		}else{
			ll x,y; cin>>x>>y;
			if(x==y)continue;
			if(ub[x]==-1)continue;
			if(ub[y]==-1){
				v[ub[x]]=y;
				ub[y]=ub[x];
				ub[x]=-1;
			}else{
				ll nu=min(ub[x],ub[y]);
				ll ot=ub[x]^ub[y]^nu;
				ub[x]=-1;
				ub[y]=nu;
				an[ot]=nu;
				v[nu]=y;
				v[ot]=-1;
			}
		}
	}
	vector<ll> res(SZ(v));
	fore(i,0,SZ(v)){
		if(an[i]==-1)res[i]=v[i];
		else res[i]=res[an[i]];
	}
	for(auto i:res)cout<<i<<" ";
	cout<<"\n";
	
	return 0;
}
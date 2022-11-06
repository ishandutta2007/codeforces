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

ll ask(ll a, ll b){
	cout<<"? "<<a+1<<" "<<b+1<<endl;
	ll resp; cin>>resp;
	return resp;
}

ll be(ll a, ll b){
	if(ask(a,b)==1)return a;
	return b;
}

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> v;
		fore(i,0,(1ll<<n))v.pb(i);
		while(SZ(v)%4==0){
			vector<ll> nv;
			fore(i,0,SZ(v)/4){
				auto a=ask(v[4*i],v[4*i+2]);
				if(a==0)nv.pb(be(v[4*i+1],v[4*i+3]));
				if(a==1)nv.pb(be(v[4*i],v[4*i+3]));
				if(a==2)nv.pb(be(v[4*i+1],v[4*i+2]));
			}
			v=nv;
		}
		if(SZ(v)==2){
			v={be(v[0],v[1])};
		}
		cout<<"! "<<v[0]+1<<endl;
	}
	
	return 0;
}
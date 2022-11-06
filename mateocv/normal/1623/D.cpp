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

const ll MOD=1000000007;

ll n,m;

pair<pair<ll,ll>,pair<ll,ll>> ne(pair<pair<ll,ll>,pair<ll,ll>> p){
	ll x=p.fst.fst,y=p.fst.snd,dx=p.snd.fst,dy=p.snd.snd;
	x+=dx;
	y+=dy;
	if(x+dx==-1||x+dx==n)dx=-dx;
	if(y+dy==-1||y+dy==m)dy=-dy;
	return {{x,y},{dx,dy}};
}

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll geo(ll x){
	return fpow((1+MOD-x)%MOD,MOD-2);
}

ll geo2(ll x){
	ll g=geo(x);
	return x*(g*g%MOD)%MOD;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll xi,yi,xf,yf,p; cin>>n>>m>>xi>>yi>>xf>>yf>>p;
		xi--; yi--; xf--; yf--;
		vector<pair<pair<ll,ll>,pair<ll,ll>>> v={{{xi,yi},{xi==n-1?-1:1,yi==m-1?-1:1}}};
		while(1){
			auto np=ne(v.back());
			if(np==v[0])break;
			v.pb(np);
		}
		//for(auto i:v)cout<<i.fst.fst<<" "<<i.fst.snd<<" "<<i.snd.fst<<" "<<i.snd.snd<<"\n";
		ll c=SZ(v);
		vector<ll> a;
		fore(i,0,SZ(v)){
			if(v[i].fst.fst==xf||v[i].fst.snd==yf)a.pb(i);
		}
		ll k=SZ(a);
		p=p*fpow(100,MOD-2)%MOD;
		ll q=(1+MOD-p)%MOD;
		ll res=0;
		fore(i,0,k){
			ll val=(c*geo2(fpow(q,k))+a[i]*geo(fpow(q,k)))%MOD;
			val=val*p%MOD;
			val=val*fpow(q,i)%MOD;
			res=(res+val)%MOD;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
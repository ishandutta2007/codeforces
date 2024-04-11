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

ll cont(vector<pair<ll,ll>> v){
	//cout<<"v\n";
	//for(auto i:v)cout<<i.fst<<" "<<i.snd<<"\n";
	sort(ALL(v));
	ll res=0;
	ll va=1;
	fore(i,1,SZ(v)){
		if(v[i].fst==v[i-1].fst){
			res+=va;
			va++;
		}else{
			va=1;
		}
	}
	va=1;
	fore(i,1,SZ(v)){
		if(v[i]==v[i-1]){
			res-=va;
			va++;
		}else{
			va=1;
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		vector<ll> x(n),y(m);
		fore(i,0,n)cin>>x[i];
		fore(i,0,m)cin>>y[i];
		set<ll> sx;
		for(auto i:x)sx.insert(i);
		set<ll> sy;
		for(auto i:y)sy.insert(i);
		vector<pair<ll,ll>> a(k);
		fore(i,0,k)cin>>a[i].fst>>a[i].snd;
		vector<pair<ll,ll>> cx,cy;
		fore(i,0,k){
			if(sx.count(a[i].fst)&&sy.count(a[i].snd))continue;
			ll posx=lower_bound(ALL(x),a[i].fst)-x.begin();
			ll posy=lower_bound(ALL(y),a[i].snd)-y.begin();
			if(sx.count(a[i].fst)){
				cx.pb({posx,posy});
			}else{
				cy.pb({posx,posy});
			}
		}
		fore(i,0,SZ(cx))swap(cx[i].fst,cx[i].snd);
		ll res=0;
		res+=cont(cx);
		res+=cont(cy);
		cout<<res<<"\n";
	}
	
	return 0;
}
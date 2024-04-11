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

double dist(pair<ll,ll> a, pair<ll,ll> b){
	ll dx=a.fst-b.fst;
	ll dy=a.snd-b.snd;
	return sqrt(1.*(dx*dx+dy*dy));
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pair<ll,ll>> a,b;
		fore(i,0,2*n){
			ll x,y; cin>>x>>y;
			x=abs(x); y=abs(y);
			if(x==0)a.pb({x,y});
			else b.pb({x,y});
		}
		sort(ALL(a));
		sort(ALL(b));
		double res0=0.;
		fore(i,0,n)res0+=dist(a[i],b[i]);
		reverse(ALL(b));
		double res1=0.;
		fore(i,0,n)res1+=dist(a[i],b[i]);
		double res=min(res0,res1);
		cout<<fixed<<setprecision(15)<<res<<"\n";
	}
	
	return 0;
}
#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

const ll INF = 1e18;
int f, T, t0;
ll as[2], ts[2], ps[2];

int main(){
	cin >> f >> T >> t0;
	ll ans=INF;
	fore(x,0,2)cin>>as[x]>>ts[x]>>ps[x];
	
	for(ll x=0, tT=T, tf=f, tp=0; x<=T; x+=ts[0]*as[0], tT-=ts[0]*as[0], tf-=as[0], tp+=ps[0]){
		int l=0, h=tT/(ts[1]*as[1]), m, tans=1e8;
		while(h>=l){
			m=(h+l)/2;
			int ttT=tT-ts[1]*as[1]*m;
			int ttF=tf-as[1]*m;
			if(ttF<=ttT/t0){tans=min(tans,m);h=m-1;}else l=m+1;
		}
		if(tans!=(int)1e8){
			ans=min(ans,tp+((ll)tans)*ps[1]);
		}else{
			ll ttT=tT-ts[1]*as[1]*(tT/(ts[1]*as[1]));
			ll ttF=tf-as[1]*(tT/(ts[1]*as[1]));
			if(ttF<=ttT/ts[1]){ans=min(ans,tp+((ll)(tT/(ts[1]*as[1])+1))*ps[1]);}
		}
	}
	ll tT=T-ts[0]*as[0]*(T/(ts[0]*as[0]));
	ll tF=f-as[0]*(T/(ts[0]*as[0]));
	if(tF<=tT/ts[0]){
		ans=min(ans, ps[0] * (ll)(T/(ts[0]*as[0])+1));
	}
	swap(as[0],as[1]); swap(ts[0],ts[1]); swap(ps[0],ps[1]);
		for(ll x=0, tT=T, tf=f, tp=0; x<=T; x+=ts[0]*as[0], tT-=ts[0]*as[0], tf-=as[0], tp+=ps[0]){
		int l=0, h=tT/(ts[1]*as[1]), m, tans=1e8;
		while(h>=l){
			m=(h+l)/2;
			int ttT=tT-ts[1]*as[1]*m;
			int ttF=tf-as[1]*m;
			if(ttF<=ttT/t0){tans=min(tans,m);h=m-1;}else l=m+1;
		}
		if(tans!=(int)1e8){
			ans=min(ans,tp+((ll)tans)*ps[1]);
		}else{
			ll ttT=tT-ts[1]*as[1]*(tT/(ts[1]*as[1]));
			ll ttF=tf-as[1]*(tT/(ts[1]*as[1]));
			if(ttF<=ttT/ts[1]){ans=min(ans,tp+((ll)(tT/(ts[1]*as[1])+1))*ps[1]);}
		}
	}
	tT=T-ts[0]*as[0]*(T/(ts[0]*as[0]));
	tF=f-as[0]*(T/(ts[0]*as[0]));
	if(tF<=tT/ts[0]){
		ans=min(ans, ps[0] * (ll)(T/(ts[0]*as[0])+1));
	}
	
	if(ans==INF)cout<<"-1\n";else cout<<ans<<"\n";
}
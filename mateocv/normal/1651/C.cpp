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
		vector<ll> a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		auto as=a;
		sort(ALL(as));
		auto bs=b;
		sort(ALL(bs));
		vector<pair<ll,ll>> v;
		v.pb({abs(a[0]-b[0]),1+4});
		v.pb({abs(a[0]-b[n-1]),1+8});
		v.pb({abs(a[n-1]-b[0]),2+4});
		v.pb({abs(a[n-1]-b[n-1]),2+8});
		vector<ll> vv={a[0],a[n-1],b[0],b[n-1]};
		fore(i,0,4){
			ll val=1e18;
			if(i>=2){
				auto pos=lower_bound(ALL(as),vv[i])-as.begin();
				if(pos<n&&abs(vv[i]-val)>abs(vv[i]-as[pos]))val=as[pos];
				pos--;
				if(pos>=0&&abs(vv[i]-val)>abs(vv[i]-as[pos]))val=as[pos];
			}else{
				auto pos=lower_bound(ALL(bs),vv[i])-bs.begin();
				if(pos<n&&abs(vv[i]-val)>abs(vv[i]-bs[pos]))val=bs[pos];
				pos--;
				if(pos>=0&&abs(vv[i]-val)>abs(vv[i]-bs[pos]))val=bs[pos];
			}
			v.pb({abs(vv[i]-val),(1ll<<i)});
		}
		//for(auto i:v)cout<<i.fst<<" "<<i.snd<<"\n";
		ll res=1e18;
		fore(i,0,(1ll<<SZ(v))){
			pair<ll,ll> ac={0,0};
			fore(j,0,SZ(v)){
				if(i&(1ll<<j)){
					ac.fst+=v[j].fst;
					ac.snd=(ac.snd|v[j].snd);
				}
			}
			//cout<<(bitset<8>)i<<" "<<ac.fst<<" "<<ac.snd<<"\n";
			if(ac.snd==15)res=min(res,ac.fst);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
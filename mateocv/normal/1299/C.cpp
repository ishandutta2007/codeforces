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
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	/*vector<pair<double,ll>> v;
	ll s=0;
	fore(i,0,n){
		s+=a[i];
		v.pb({1./(i+1)*s,i});
	}
	sort(ALL(v));
	vector<ll> ind;
	fore(i,0,n){
		if(i==0)ind.pb(v[0].snd);
		else{
			if(v[i].snd>ind.back())ind.pb(v[i].snd);
		}
	}
	//for(auto i:ind)cout<<i<<" ";
	ll va=0,van=0,vai=0;
	fore(i,0,n){
		va+=a[i];
		van++;
		if(ind[vai]==i){
			double c=1./van*va;
			fore(j,0,van)cout<<c<<" ";
			vai++;
			van=0;
			va=0;
		}
	}*/
	vector<pair<double,ll>> v;
	fore(i,0,n){
		if(SZ(v)==0){
			v.pb({a[i],1});
		}else{
			if(v.back().fst>a[i]){
				pair<double,ll> p=v.back();
				v.pop_back();
				v.pb({(p.fst*p.snd+a[i])/(p.snd+1),p.snd+1});
				while(SZ(v)>=2){
					pair<double,ll> p=v.back();
					v.pop_back();
					pair<double,ll> q=v.back();
					v.pop_back();
					if(p.fst<q.fst){
						v.pb({(p.fst*p.snd+q.fst*q.snd)/(p.snd+q.snd),p.snd+q.snd});
					}else{
						v.pb(q); v.pb(p); break;
					}
				}
			}else{
				v.pb({a[i],1});
			}
		}
	}
	for(auto i:v){
		fore(j,0,i.snd)cout<<fixed<<setprecision(9)<<i.fst<<"\n";
	}
	
	return 0;
}
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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)a[i]--;
		vector<ll> c(n);
		fore(i,0,n)c[a[i]]++;
		pair<ll,ll> maxi={0,-1};
		fore(i,0,n)maxi=max(maxi,{c[i],i});
		ll ex=2ll*maxi.fst-n;
		vector<ll> res(n,-1);
		fore(i,0,n){
			if(ex>0&&a[i]==maxi.snd){
				ex--;
				res[i]=maxi.snd;
			}
		}
		vector<pair<ll,pair<ll,ll>>> vp;
		fore(i,0,n){
			if(res[i]==-1){
				vp.pb({c[a[i]],{a[i],i}});
			}
		}
		sort(ALL(vp));
		reverse(ALL(vp));
		//for(auto i:vp)cout<<i.fst<<" "<<i.snd.fst<<" "<<i.snd.snd<<"\n";
		vector<ll> vpos;
		fore(i,0,SZ(vp)){
			if(i==0||vp[i-1].snd.fst!=vp[i].snd.fst)vpos.pb(i);
		}
		vector<pair<ll,pair<ll,ll>>> v;
		while(SZ(vpos)){
			for(auto i:vpos)v.pb(vp[i]);
			vector<ll> nvpos;
			for(auto i:vpos){
				if(i+1<SZ(vp)&&vp[i].snd.fst==vp[i+1].snd.fst)nvpos.pb(i+1);
			}
			vpos=nvpos;
		}
		//for(auto i:v)cout<<i.fst<<" "<<i.snd.fst<<" "<<i.snd.snd<<"\n";
		fore(i,0,SZ(v)){
			res[v[i].snd.snd]=v[(i+1)%SZ(v)].snd.fst;
		}
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}
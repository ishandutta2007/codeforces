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

ll a[100005];

vector<vector<ll>> v;

vector<pair<ll,ll>> vp;

ll cant[100005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i],a[i]--;
		vector<ll>va;
		v.clear();
		fore(i,0,n){
			va.pb(a[i]);
			if(i==n-1||a[i]==a[i+1]){
				v.pb(va);
				va.clear();
			}
		}
		vp.clear();
		for(auto i:v){
			vp.pb({i[0],i.back()});
		}
		/*
		for(auto i:v){
			for(auto j:i)cout<<j<<" ";
			cout<<"\n";
		}
		*/
		//or(auto i:vp)cout<<i.fst<<" "<<i.snd<<"\n";
		fore(i,0,n)cant[i]=0;
		for(auto i:vp){
			cant[i.fst]++;
			cant[i.snd]++;
		}
		pair<ll,ll> maxi={0,-1};
		fore(i,0,n)maxi=max(maxi,(pair<ll,ll>){cant[i],i});
		if(maxi.fst-2<=SZ(vp)-1){
			cout<<SZ(vp)-1<<"\n";
			continue;
		}
		ll ex[2]={0,0};
		for(auto i:v){
			fore(j,0,SZ(i)-1){
				if(i[j]==maxi.snd||i[j+1]==maxi.snd)ex[0]++;
				else ex[1]++;
			}
		}
		//cout<<ex[0]<<" "<<ex[1]<<"\n";
		ll cantf[2]={0,0};
		for(auto i:vp){
			if(i.fst==maxi.snd)cantf[1]++;
			else cantf[0]++;
			if(i.snd==maxi.snd)cantf[1]++;
			else cantf[0]++;
		}
		//cout<<cantf[0]<<" "<<cantf[1]<<"\n";
		ll res=SZ(vp)-1;
		ll br=0;
		while(ex[1]){
			cantf[0]++; cantf[0]++; res++; ex[1]--;
			if(cantf[1]-2<=(cantf[0]+cantf[1]-2)/2){
				br++; break;
			}
		}
		if(br){
			cout<<res<<"\n";
			continue;
		}
		while(ex[0]){
			cantf[0]++; cantf[1]++; res++; ex[0]--;
			if(cantf[1]-2<=(cantf[0]+cantf[1]-2)/2){
				br++; break;
			}
		}
		if(br){
			cout<<res<<"\n";
			continue;
		}
		cout<<"-1\n";
	}
	
	return 0;
}
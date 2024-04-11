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
	vector<pair<ll,ll>> a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	fore(i,0,n)a[i].snd++;
	vector<ll> res(33);
	fore(k,0,33){
		ll pot=(1ll<<k);
		vector<pair<ll,ll>> ev;
		for(auto i:a){
			if(i.snd-i.fst>=pot){
				ev.pb({0,1});
				ev.pb({pot,-1});
			}else if(i.fst%pot<i.snd%pot){
				ev.pb({i.fst%pot,1});
				ev.pb({i.snd%pot,-1});
			}else{
				ev.pb({i.fst%pot,1});
				ev.pb({pot,-1});
				if(i.snd%pot){
					ev.pb({0,1});
					ev.pb({i.snd%pot,-1});
				}
			}
		}
		sort(ALL(ev));
		ll maxi=0,va=0;
		for(auto i:ev){
			va+=i.snd;
			maxi=max(maxi,va);
		}
		res[k]=maxi;
	}
	ll q; cin>>q;
	while(q--){
		ll w; cin>>w;
		fore(k,0,33){
			if((1ll<<k)&w){
				cout<<res[k]<<"\n";
				break;
			}
		}
	}
	
	return 0;
}
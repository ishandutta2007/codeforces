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
typedef int ll;

ll a[300005];

vector<bool> g[300005];
vector<ll> gid[300005];

pair<long long,long long> solve(ll id){
	pair<long long, long long> res={0,0};
	long long tot=0,va=0;
	for(auto i:g[id]){
		if(i)va++;
		else tot+=va;
	}
	res.fst=tot;
	tot=0,va=0;
	for(auto i:g[id]){
		if(!i)va++;
		else tot+=va;
	}
	res.snd=tot;
	return res;
}

vector<ll> gidc;
vector<bool> gc;

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	pair<long long,long long> res={0,0};
	ll va=0;
	for(ll j=29;j>=0;j--){
		if(j==29){
			va=1;
			fore(i,0,n){
				gid[0].pb(i);
				g[0].pb((a[i]>>j)&1);
			}
		}else{
			ll van=0;
			fore(i,0,va){
				//cout<<j<<" "<<i<<": \n";
				//cout<<"Antes: \n";
				//for(auto ii:gid[i])cout<<ii<<" "; cout<<"\n";
				//for(auto ii:g[i])cout<<ii<<" "; cout<<"\n";
				//gc=g[i];
				gc.clear();
				for(auto ii:g[i])gc.pb(ii);
				//gidc=gid[i];
				gidc.clear();
				for(auto ii:gid[i])gidc.pb(ii);
				g[i].clear();
				gid[i].clear();
				//cout<<"Despues: \n";
				//for(auto ii:gidc)cout<<ii<<" "; cout<<"\n";
				//for(auto ii:gc)cout<<ii<<" "; cout<<"\n";
				ll tot[2]={0,0};
				fore(ii,0,SZ(gc)){
					if(gc[ii])tot[1]++;
					else tot[0]++;
				}
				if(tot[0]==0||tot[1]==0){
					fore(ii,0,SZ(gc)){
						gid[i].pb(gidc[ii]);
						g[i].pb((a[gidc[ii]]>>j)&1);
					}
				}else{
					fore(ii,0,SZ(gc)){
						if(gc[ii]){
							gid[va+van].pb(gidc[ii]);
							g[va+van].pb((a[gidc[ii]]>>j)&1);
						}else{
							gid[i].pb(gidc[ii]);
							g[i].pb((a[gidc[ii]]>>j)&1);
						}
					}
					van++;
				}
			}
			va+=van;
		}
		//cout<<va<<"\n";
		//for(auto i:gid[0])cout<<i<<" "; cout<<"\n";
		//for(auto i:g[0])cout<<i<<" "; cout<<"\n";
		pair<long long,long long> par={0,0};
		fore(i,0,va){
			auto sol=solve(i);
			par.fst+=sol.fst;
			par.snd+=sol.snd;
		}
		if(par.fst<=par.snd){
			res.fst+=par.fst;
		}else{
			res.fst+=par.snd;
			res.snd|=(1ll<<j);
		}
		//fore(i,0,va)g[i].clear();
	}
	cout<<res.fst<<" "<<res.snd<<"\n";
	return 0;
}
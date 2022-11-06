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
		ll n,m; cin>>n>>m;
		string s; cin>>s;
		string DRUL="DRUL";
		vector<pair<ll,ll>> dir={{1,0},{0,1},{-1,0},{0,-1}};
		pair<ll,ll> va={0,0};
		ll minx=0,maxx=0,miny=0,maxy=0;
		pair<ll,ll> res={0,0};
		for(auto i:s){
			fore(j,0,SZ(dir)){
				if(i==DRUL[j]){
					va.fst+=dir[j].fst;
					va.snd+=dir[j].snd;
					minx=min(minx,va.fst);
					maxx=max(maxx,va.fst);
					miny=min(miny,va.snd);
					maxy=max(maxy,va.snd);
					if(maxx-minx<n&&maxy-miny<m){
						res={-minx,-miny};
					}
				}
			}
		}
		cout<<res.fst+1<<" "<<res.snd+1<<"\n";
	}
	
	return 0;
}
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

vector<ll> div(ll n){
	vector<ll> res;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			res.pb(i);
			if(i!=n/i)res.pb(n/i);
		}
	}
	sort(ALL(res));
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll p[n],c[n];
		fore(i,0,n)cin>>p[i],p[i]--;
		fore(i,0,n)cin>>c[i];//c[i]--;
		ll vis[n];
		mset(vis,0);
		ll res=n+1;
		fore(i,0,n){
			if(vis[i])continue;
			vector<pair<ll,ll>> v;
			ll va=i;
			while(!vis[va]){
				vis[va]=1;
				v.pb({va,c[va]});
				va=p[va];
			}
			auto d=div(SZ(v));
			ll br=0;
			for(auto j:d){
				ll can[j];
				fore(ii,0,j)can[ii]=1;
				fore(ii,0,SZ(v)){
					if(v[ii].snd!=v[ii%j].snd)can[ii%j]=0;
				}
				fore(ii,0,j){
					if(can[ii])res=min(res,j),br++;
					if(br)break;
				}
				if(br)break;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
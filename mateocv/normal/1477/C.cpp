#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=5050;

ll d[MAXN][MAXN];

vector<pair<ll,ll>> p;

ll dist(pair<ll,ll> a, pair<ll,ll> b){
	ll dx=a.fst-b.fst,dy=a.snd-b.snd;
	return dx*dx+dy*dy;
}

ll vis[MAXN];

vector<ll> res;

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		p.pb({x,y});
	}
	pair<ll,ll> maxi={0,-1};
	fore(i,0,n){
		fore(j,0,n){
			d[i][j]=dist(p[i],p[j]);
			maxi=max(maxi,{d[i][j],MAXN*i+j});
		}
	}
	ll a=maxi.snd/MAXN,b=maxi.snd%MAXN;
	res.pb(a);
	res.pb(b);
	vis[a]=1;
	vis[b]=1;
	while(SZ(res)<n){
		maxi={0,-1};
		fore(i,0,n){
			if(!vis[i])maxi=max(maxi,{d[b][i],i});
		}
		res.pb(maxi.snd);
		vis[maxi.snd]=1;
		b=maxi.snd;
	}
	for(auto i:res)cout<<i+1<<" ";
	cout<<"\n";
	
	return 0;
}
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

const int MAXN=3030;

vector<ll> g[MAXN];

ll vis[MAXN],d[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto i:g[x]){
		if(!vis[i]){
			d[i]=d[x]+1;
			dfs(i);
		}
	}
}

vector<ll> d0;

ll n;

vector<ll> solve(ll x){
	vector<ll> res(n),vr(n);
	fore(i,0,n)vis[i]=0,d[i]=0;
	dfs(x);
	fore(i,0,n){
		if(d[i]<d0[i]){
			res[d0[i]-d[i]-1]=max(res[d0[i]-d[i]-1],d[i]);
			vr[d0[i]-d[i]]=max(d0[i],vr[d0[i]-d[i]]);
		}else{
			vr[0]=max(vr[0],d0[i]);
		}
	}
	//fore(i,0,n)cout<<res[i]<<" "; cout<<"\n";
	//fore(i,0,n)cout<<vr[i]<<" "; cout<<"\n";
	for(ll i=n-2;i>=0;i--){
		res[i]=max(res[i],res[i+1]);
	}
	fore(i,1,n){
		vr[i]=max(vr[i],vr[i-1]);
	}
	fore(i,0,n){
		res[i]=max(res[i]+i+1,vr[i]);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll x,y; cin>>x>>y; x--; y--;
			g[x].pb(y);
			g[y].pb(x);
		}
		fore(i,0,n)vis[i]=0,d[i]=0;
		dfs(0);
		d0.clear();
		fore(i,0,n)d0.pb(d[i]);
		vector<ll> res(n);
		ll maxi=0;
		for(auto i:d0)maxi=max(maxi,i);
		fore(i,0,n)res[i]=maxi;
		fore(i,1,n){
			auto s=solve(i);
			//cout<<i<<":\n";
			//for(auto j:s)cout<<j<<" ";
			//cout<<"\n";
			fore(i,0,n)res[i]=min(res[i],s[i]);
		}
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}
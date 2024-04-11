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

ll calc(ll x){
	if(x<=1)return 0;
	ll pot=(1ll<<(32-__builtin_clz(x-1)));
	//cout<<x<<" "<<pot-x<<"\n";
	return pot-x;
}

const int MAXN=6000006;

vector<ll> g[6000006];

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

int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	map<ll,ll> mp;
	fore(i,0,n)mp[a[i]]=i+1;
	vector<ll> v={0};
	pair<ll,pair<ll,ll>> res={-1,{-1,-1}};
	fore(i,0,n){
		ll va=a[i],cant=0;
		while(va){
			v.pb(va);
			va=calc(va);
			cant++;
			if(mp.count(va))res=max(res,{cant,{mp[va],mp[a[i]]}});
		}
	}
	sort(ALL(v));
	v.erase(unique(ALL(v)), v.end());
	//for(auto i:v)cout<<i<<" ";
	//cout<<"\n";
	fore(i,1,SZ(v)){
		ll x=i;
		ll y=lower_bound(ALL(v),calc(v[i]))-v.begin();
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0);
	pair<ll,ll> maxi={-1,-1};
	fore(i,1,SZ(v)){
		if(SZ(g[i])==1)maxi=max(maxi,{d[i],i});
	}
	mset(vis,0);
	mset(d,0);
	dfs(maxi.snd);
	pair<ll,ll> maxi2={-1,-1};
	fore(i,1,SZ(v)){
		if(SZ(g[i])==1)maxi2=max(maxi2,{d[i],i});
	}
	res=max(res,{maxi2.fst,{mp[v[maxi.snd]],mp[v[maxi2.snd]]}});
	cout<<res.snd.fst<<" "<<res.snd.snd<<" "<<res.fst<<"\n";
	return 0;
}
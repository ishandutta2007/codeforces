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

const int MAXN=300005;

vector<ll> g[MAXN];

ll vis[MAXN],p[MAXN],d[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			d[i]=d[v]+1;
			p[i]=v;
			dfs(i);
		}
	}
}

vector<ll> tr[MAXN];

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll x,y; cin>>x>>y; x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	p[0]=-1;
	dfs(0);
	fore(i,1,n){
		tr[p[i]].pb(i);
	}
	vector<ll> c(n);
	vector<vector<ll>> res;
	ll q; cin>>q;
	while(q--){
		ll x,y; cin>>x>>y; x--; y--;
		vector<ll> wx,wy;
		while(d[x]>d[y]){
			wx.pb(x);
			c[x]^=1;
			x=p[x];
		}
		while(d[y]>d[x]){
			wy.pb(y);
			c[y]^=1;
			y=p[y];
		}
		while(x!=y){
			wx.pb(x);
			c[x]^=1;
			x=p[x];
			wy.pb(y);
			c[y]^=1;
			y=p[y];
		}
		vector<ll> w;
		for(auto i:wx)w.pb(i);
		w.pb(x);
		reverse(ALL(wy));
		for(auto i:wy)w.pb(i);
		res.pb(w);
	}
	ll br=0;
	fore(i,0,n){
		if(c[i])br++;
	}
	if(!br){
		cout<<"YES\n";
		for(auto i:res){
			cout<<SZ(i)<<"\n";
			for(auto j:i)cout<<j+1<<" ";
			cout<<"\n";
		}
		return 0;
	}
	//fore(i,0,n)cout<<p[i]<<" ";
	//cout<<"\n";
	vector<pair<ll,ll>> dv;
	fore(i,1,n)dv.pb({d[i],i});
	sort(ALL(dv));
	reverse(ALL(dv));
	ll cant=0;
	//for(auto i:c)cout<<i<<" ";
	//cout<<"\n";
	vector<ll> lz(n);
	for(auto i:dv){
		//cout<<i.fst<<" "<<i.snd<<"\n";
		c[i.snd]^=lz[i.snd];
		if(c[i.snd]){
			cant++;
			if(p[i.snd]!=-1){
				lz[p[i.snd]]^=1;
			}
		}
		lz[p[i.snd]]^=lz[i.snd];
		//for(auto i:c)cout<<i<<" ";
		//cout<<"\n";
	}
	cout<<"NO\n"<<(cant+1)/2<<"\n";
	
	return 0;
}
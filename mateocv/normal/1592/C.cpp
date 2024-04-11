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

const int MAXN=100005;

vector<ll> g[MAXN];

vector<ll> a;

ll vis[MAXN],d[MAXN],p[MAXN],xo[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			p[i]=v;
			d[i]=d[v]+1;
			dfs(i);
			xo[v]^=xo[i];
		}
	}
}

ll vis2[MAXN];

queue<ll> q;

void bfs() {
	while(q.size()) {
		int t=q.front(); q.pop();
		for(int i:g[t]) {
			if(!vis2[i]&&i!=p[t]) {
				vis2[i]=1;
				q.push(i);
			}
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		a.clear();
		a.resize(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll x,y; cin>>x>>y; x--; y--;
			g[x].pb(y);
			g[y].pb(x);
		}
		ll x=0;
		for(auto i:a)x^=i;
		if(k==2){
			if(x==0)cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		if(x==0){
			cout<<"YES\n";
			continue;
		}
		fore(i,0,n)vis[i]=0,d[i]=0,p[i]=-1,xo[i]=a[i];
		dfs(0);
		ll c=0;
		fore(i,0,n)c+=(xo[i]==x);
		pair<ll,ll> maxi={-1,-1};
		fore(i,0,n){
			if(xo[i]==x)maxi=max(maxi,{d[i],i});
		}
		if(maxi.snd!=-1){
			ll va=maxi.snd;
			while(va!=-1){
				if(xo[va]==x)c--;
				va=p[va];
			}
		}
		if(c>0){
			cout<<"YES\n";
			continue;
		}
		while(SZ(q))q.pop();
		fore(i,0,n)vis2[i]=0;
		fore(i,0,n){
			if(xo[i]==0)q.push(i),vis2[i]=1;
		}
		bfs();
		ll br=0;
		fore(i,0,n){
			if(xo[i]==x&&vis2[i])br++;
		}
		if(br)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
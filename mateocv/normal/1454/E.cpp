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

const ll MAXN=200005;
/*---------------- Union Find (DSU) ------------------*/
int pa[MAXN],sz[MAXN];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

vector<pair<ll,ll>> ed;
vector<ll> g[MAXN];

ll vis[MAXN],d[MAXN],p[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			p[i]=v;
			d[i]=d[v]+1;
			dfs(i);
		}
	}
}

ll tom2(ll n){
	return n*(n-1)/2;
}

set<ll> cy;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ed.clear();
		fore(i,0,n){
			ll u,v; cin>>u>>v; u--; v--;
			ed.pb({u,v});
		}
		dsu_init(n);
		fore(i,0,n)g[i].clear();
		pair<ll,ll> sb={-1,-1};
		for(auto i:ed){
			if(find_pa(i.fst)!=find_pa(i.snd)){
				join(i.fst,i.snd);
				g[i.fst].pb(i.snd);
				g[i.snd].pb(i.fst);
			}else{
				sb=i;
			}
		}
		fore(i,0,n)vis[i]=0,d[i]=0,p[i]=0;
		dfs(0);
		//fore(i,0,n)cout<<d[i]<<" "; cout<<"\n";
		//cout<<sb.fst<<" "<<sb.snd<<"\n";
		if(d[sb.fst]<d[sb.snd]){
			swap(sb.fst,sb.snd);
		}
		cy.clear();
		ll c=0;
		while(d[sb.fst]>d[sb.snd]){
			cy.insert(sb.fst);
			sb.fst=p[sb.fst];
			c++;
		}
		while(sb.fst!=sb.snd){
			cy.insert(sb.fst);
			sb.fst=p[sb.fst];
			cy.insert(sb.snd);
			sb.snd=p[sb.snd];
			c+=2;
		}
		c++;
		cy.insert(sb.snd);
		assert(c==SZ(cy));
		ll res=0;
		dsu_init(n);
		for(auto i:ed){
			if(!cy.count(i.fst)||!cy.count(i.snd)){
				join(i.fst,i.snd);
			}
		}
		fore(i,0,n)vis[i]=0;
		vector<ll> cant;
		fore(i,0,n){
			if(!vis[find_pa(i)]){
				vis[find_pa(i)]=1;
				cant.pb(sz[find_pa(i)]);
			}
		}
		ll sq=0,sum=0;
		//for(auto i:cant)cout<<i<<" "; cout<<"\n";
		for(auto i:cant)res+=tom2(i),sq+=i*i,sum+=i;
		res+=sum*sum-sq;
		//cout<<n<<" "<<c<<"\n";
		cout<<res<<"\n";
	}
	
	return 0;
}
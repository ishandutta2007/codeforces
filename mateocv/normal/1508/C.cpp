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

const int MAXN=200005;

vector<pair<ll,ll>> g[MAXN];

set<ll> gs[MAXN]; 

/*---------------- Union Find (DSU) ------------------*/
int pa[2*MAXN],sz[2*MAXN];
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

vector<pair<ll,pair<ll,ll>>> ed;

map<pair<ll,ll>,ll> edc;

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll x,y,w; cin>>x>>y>>w; x--; y--;
		g[y].pb({x,w});
		g[x].pb({y,w});
		gs[x].insert(y);
		gs[y].insert(x);
	}
	if(n*(n-1)/2-m>n-1){
		fore(i,0,n){
			for(auto j:g[i]){
				if(i<j.fst)edc[{i,j.fst}]=j.snd;
			}
		}
		vector<ll> v={0};
		set<ll>nvis;
		fore(i,1,n)nvis.insert(i);
		priority_queue<pair<ll,ll>> pq;
		dsu_init(n);
		ll res=0;
		while(SZ(nvis)){
			if(SZ(v)){
				auto b=v.back();
				v.pop_back();
				vector<ll> vc;
				for(auto i:nvis){
					if(gs[b].count(i)){
						pq.push({-edc[{min(b,i),max(b,i)}],i});
					}else{
						v.pb(i);
						vc.pb(i);
						join(i,b);
					}
				}
				for(auto i:vc)nvis.erase(i);
			}else{
				pair<ll,ll> f;
				while(1){
					assert(SZ(pq));
					f=pq.top();
					pq.pop();
					if(find_pa(0)!=find_pa(f.snd))break;
				}
				res-=f.fst;
				v.pb(f.snd);
				nvis.erase(f.snd);
				join(0,f.snd);
			}
		}
		cout<<res<<"\n";
	}else{
		ll xo=0;
		vector<pair<ll,ll>> z;
		fore(i,0,n){
			for(auto j:g[i]){
				if(i<j.fst)ed.pb({j.snd,{i,j.fst}}),xo^=j.snd;
			}
		}
		sort(ALL(ed));
		fore(i,0,n){
			fore(j,i+1,n){
				if(!gs[i].count(j))z.pb({i,j});
			}
		}
		ll br=0;
		dsu_init(2*n);
		for(auto i:z){
			if(find_pa(i.fst)==find_pa(i.snd))br++;
			join(i.fst,i.snd);
		}
		ll res=0;
		if(br){
			for(auto i:ed){
				ll x=i.snd.fst,y=i.snd.snd;
				if(find_pa(x)!=find_pa(y)){
					join(x,y);
					res+=i.fst;
				}
			}
		}else{
			res+=xo;
			for(auto i:ed){
				ll x=i.snd.fst,y=i.snd.snd;
				if(find_pa(x)!=find_pa(y)){
					join(x,y);
					join(n+x,n+y);
					res+=i.fst;
				}else{
					if(find_pa(x+n)!=find_pa(y+n)&&!br){
						if(i.fst<xo)res+=i.fst-xo;
						br++;
					}
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
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

const int MAXN=500005;

vector<int> g[MAXN];
vector<int> gc[MAXN];
bool valc[MAXN];

vector<ll> col[MAXN];

ll c[MAXN];
bool vis[MAXN];
ll bw[MAXN];

void dfs(ll v, ll p){
	if(vis[v])return;
	vis[v]=1;
	for(auto i:gc[v]){
		if(i!=p){
			if(!vis[i]){
				bw[i]=bw[v]^1;
				dfs(i,v);
			}
		}
	}
}

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

const int MAXM=2*MAXN+10;

// MAXM: max number of nodes or 2 * max number of variables (2SAT)
bool truth[MAXM]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return MAXM-1-x;} // (2SAT)
vector<int> gd[MAXM];
int nn,lw[MAXM],idx[MAXM],qidx,cmp[MAXM],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(int v:gd[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;if(min(x,neg(x))<nvar)l=x;}
		while(x!=u);
		if(l!=-1)truth[qcmp]=(cmp[neg(l)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	fore(i,0,nvar)idx[i]=0,idx[neg(i)]=0;
	qidx=0;
	fore(i,0,nvar)cmp[i]=-1,cmp[neg(i)]=-1;
	qcmp=0;
	fore(i,0,nvar)if(!idx[i])tjn(i);
	fore(i,0,nvar)if(!idx[neg(i)])tjn(neg(i));
}
// Only for 2SAT:
void addor(int a, int b){gd[neg(a)].pb(b);gd[neg(b)].pb(a);}
bool satisf(int _nvar){
	nvar=_nvar;nn=MAXM;scc();
	fore(i,0,nvar)if(cmp[i]==cmp[neg(i)])return false;
	return true;
}

map<pair<int,int>,int> mp;

set<pair<int,int>> q;

vector<pair<ll,ll>> vq[MAXN];

ll ar[MAXN];

vector<ll> comp(vector<ll> v){
	set<ll> s;
	for(auto i:v)s.insert(i);
	ll va=0;
	for(auto i:s){
		ar[va++]=i;
	}
	fore(i,0,SZ(v))v[i]=lower_bound(ar,ar+SZ(s),v[i])-ar;
	return v;
}

ll solve(ll id){
	vector<ll> v;
	for(auto i:vq[id]){
		v.pb(find_pa(i.fst));
		v.pb(find_pa(i.snd));
	}
	v=comp(v);
	fore(i,0,SZ(vq[id])){
		if(bw[vq[id][i].fst]==bw[vq[id][i].snd]){
			addor(v[2*i],v[2*i+1]);
			addor(neg(v[2*i]),neg(v[2*i+1]));
		}else{
			addor(v[2*i],neg(v[2*i+1]));
			addor(neg(v[2*i]),v[2*i+1]);
		}
	}
	ll cant=min(2*SZ(vq[id]),MAXN);
	ll res=satisf(cant);
	fore(i,0,cant)gd[i].clear();
	fore(i,0,cant)gd[neg(i)].clear();
	return res;
}

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	fore(i,0,n)cin>>c[i],c[i]--;
	fore(i,0,n)col[c[i]].pb(i);
	dsu_init(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
		if(c[u]==c[v]){
			gc[u].pb(v);
			gc[v].pb(u);
			join(u,v);
		}
	}
	fore(i,0,n)dfs(i,-1);
	//fore(i,0,n)cout<<bw[i]<<" "; cout<<"\n";
	fore(i,0,k){
		valc[i]=1;
		ll br=0;
		for(auto j:col[i]){
			for(auto jj:gc[j]){
				if(bw[j]==bw[jj]){
					valc[i]=0;
					br++; break;
				}
			}
			if(br)break;
		}
	}
	ll tot=0;
	fore(i,0,k)tot+=valc[i];
	//fore(i,0,k)cout<<valc[i]<<" "; cout<<"\n";
	ll res=tot*(tot-1)/2;
	fore(i,0,n){
		for(auto j:g[i]){
			if(valc[c[i]]&&valc[c[j]]&&c[i]!=c[j]){
				q.insert({min(c[i],c[j]),max(c[i],c[j])});
			}
		}
	}
	ll va=0;
	for(auto i:q)mp[i]=va++;
	fore(i,0,n){
		for(auto j:g[i]){
			if(valc[c[i]]&&valc[c[j]]&&c[i]!=c[j]){
				if(i<j)vq[mp[{min(c[i],c[j]),max(c[i],c[j])}]].pb({i,j});
			}
		}
	}
	fore(i,0,va)res-=!solve(i);
	cout<<res<<"\n";
	return 0;
}
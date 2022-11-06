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

/*---------------- Union Find (DSU) ------------------*/
const ll N=3e5+10;
int pa[N],sz[N];
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

vector<pair<ll,ll>> vp;
vector<ll> g[N];
vector<pair<ll,ll>> pc[N];

set<ll> st[2];
map<ll,ll> mp;
ll vis[N];
vector<ll> ch[N];

vector<ll> ord,ordc;
ll u[N];

ll visd[N];
void dfs(ll v){
	if(visd[v])return;
	visd[v]=1;
	for(auto i:g[v])dfs(i);
	ord.pb(v);
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll p[n];
	fore(i,0,n)cin>>p[i],p[i]--;
	dsu_init(n);
	fore(i,0,k){
		ll x,y; cin>>x>>y; x--; y--;
		vp.pb({x,y});
		if(find_pa(x)==find_pa(y)){
			cout<<"0\n"; return 0;
		}
		join(x,y);
	}
	for(auto i:vp){
		pc[find_pa(i.fst)].pb(i);
	}
	//fore(i,0,n)cout<<i<<" fp: "<<find_pa(i)<<endl;
	/*
	fore(i,0,n){
		cout<<"vp "<<i<<":\n";
		for(auto j:pc[i])cout<<j.fst<<" "<<j.snd<<endl;
	}
	*/
	fore(i,0,n){
		ll fp=find_pa(i);
		if(vis[fp])continue;
		vis[fp]=1;
		fore(k,0,2)st[k].clear();
		mp.clear();
		for(auto j:pc[fp]){
			st[0].insert(j.fst);
			st[1].insert(j.snd);
			mp[j.fst]=j.snd;
		}
		if(SZ(st[0])!=sz[fp]-1||SZ(st[1])!=sz[fp]-1){
			cout<<"0\n"; return 0;
		}
		ll s=-1;
		for(auto j:pc[fp]){
			if(!st[1].count(j.fst)){
				s=j.fst; break;
			}
		}
		if(sz[fp]==1){
			ch[fp].pb(fp);
		}else{
			assert(s!=-1);
			ch[fp].pb(s);
			while(st[0].count(s)){
				s=mp[s];
				ch[fp].pb(s);
			}
		}
	}
	//cout<<"HOLAAAAa"<<endl;
	/*
	fore(i,0,n){
		cout<<"ch "<<i<<": ";
		for(auto j:ch[i])cout<<j<<" ";
		cout<<endl;
	}
	*/
	fore(i,0,n){
		if(p[i]!=-1){
			g[find_pa(p[i])].pb(find_pa(i));
		}
	}
	fore(i,0,n){
		if(find_pa(i)==i){
			dfs(i);
		}
	}
	reverse(ALL(ord));
	for(auto i:ord){
		for(auto j:ch[i])ordc.pb(j);
	}
	fore(i,0,n)u[ordc[i]]=i;
	//for(auto i:ord)cout<<i+1<<" "; cout<<"\n";
	fore(i,0,n){
		if(p[i]!=-1&&u[p[i]]>=u[i]){
			cout<<"0\n"; return 0;
		}
	}
	for(auto i:ordc)cout<<i+1<<" "; cout<<"\n";
	
	return 0;
}
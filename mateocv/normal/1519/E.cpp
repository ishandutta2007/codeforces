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

pair<ll,ll> simp(pair<ll,ll> f){
	ll g=__gcd(f.fst,f.snd);
	return {f.fst/g,f.snd/g};
}

pair<ll,ll> ddiv(pair<ll,ll> a, pair<ll,ll> b){
	return simp({a.fst*b.snd,a.snd*b.fst});
}

pair<ll,ll> add1(pair<ll,ll> a){
	return {a.fst+a.snd,a.snd};
}

pair<pair<ll,ll>,pair<ll,ll>> trans(pair<pair<ll,ll>,pair<ll,ll>> p){
	pair<pair<ll,ll>,pair<ll,ll>> p1={add1(p.fst),p.snd};
	pair<pair<ll,ll>,pair<ll,ll>> p2={p.fst,add1(p.snd)};
	return {ddiv(p1.snd,p1.fst),ddiv(p2.snd,p2.fst)};
}

vector<pair<pair<ll,ll>,pair<ll,ll>>> v;

vector<pair<ll,ll>> vc;

set<pair<ll,ll>> st;

map<pair<ll,ll>,ll> mp;

const int MAXN=400005;

/*----------------DSU------------------*/
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

vector<ll> tr[MAXN];

ll vis[MAXN],p[MAXN],h[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:tr[v]){
		if(!vis[i]){
			p[i]=v;
			h[i]=h[v]+1;
			dfs(i);
		}
	}
}

set<ll> gd[MAXN];

bool cmp(ll a, ll b){
	return h[a]>h[b];
}

ll ub[MAXN];

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		ll a,b,c,d; cin>>a>>b>>c>>d;
		v.pb(trans({{a,b},{c,d}}));
		st.insert(v.back().fst);
		st.insert(v.back().snd);
	}
	ll va=0;
	for(auto i:st){
		mp[i]=va++;
	}
	fore(i,0,n){
		vc.pb({mp[v[i].fst],mp[v[i].snd]});
		//cout<<vc[i].fst<<" "<<vc[i].snd<<"\n";
	}
	dsu_init(va);
	fore(i,0,n){
		ll x=vc[i].fst,y=vc[i].snd;
		if(find_pa(x)!=find_pa(y)){
			tr[x].pb(y);
			tr[y].pb(x);
			join(x,y);
		}
	}
	fore(i,0,va){
		if(find_pa(i)==i){
			p[i]=-1;
			h[i]=0;
			dfs(i);
		}
	}
	mset(ub,-1);
	fore(i,0,SZ(vc)){
		ll x=vc[i].fst,y=vc[i].snd;
		if(p[x]==y){
			gd[y].insert(i);
			ub[x]=i;
		}else if(p[y]==x){
			gd[x].insert(i);
			ub[y]=i;
		}else{
			gd[x].insert(i);
		}
	}
	vector<ll> vo;
	fore(i,0,va)vo.pb(i);
	sort(ALL(vo),cmp);
	for(auto i:vo){
		if(h[i]==0)break;
		if(SZ(gd[i])&1){
			ll u=ub[i];
			assert(u!=-1);
			gd[i].insert(u);
			gd[p[i]].erase(u);
		}
	}
	ll res=0;
	fore(i,0,va){
		res+=SZ(gd[i])/2;
	}
	cout<<res<<"\n";
	fore(i,0,va){
		while(SZ(gd[i])>=2){
			ll a=*gd[i].begin();
			gd[i].erase(a);
			ll b=*gd[i].begin();
			gd[i].erase(b);
			cout<<a+1<<" "<<b+1<<"\n";
		}
	}
	
	return 0;
}
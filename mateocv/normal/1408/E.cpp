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

vector<pair<ll,pair<ll,ll>>> ed;

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

int main(){FIN;
	ll m,n; cin>>m>>n;
	ll a[m],b[n];
	fore(i,0,m)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	fore(i,0,m){
		ll k; cin>>k;
		fore(j,0,k){
			ll u; cin>>u; u--;
			ed.pb({a[i]+b[u],{n+i,u}});
			//ed.pb({a[i]+b[u],{u,n+i}});
		}
	}
	sort(ALL(ed));
	reverse(ALL(ed));
	dsu_init(n+m);
	ll res=0;
	for(auto i:ed){
		auto p=i.snd;
		if(find_pa(p.fst)!=find_pa(p.snd)){
			join(p.fst,p.snd);
		}else{
			res+=i.fst;
		}
	}
	cout<<res<<"\n";
	
	return 0;
}
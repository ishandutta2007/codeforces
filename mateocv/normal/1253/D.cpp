#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

/*---------------- Union Find (DSU) ------------------*/
const ll N=2e5+10;
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

ll mini[N],maxi[N];

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll u,vv;
	dsu_init(n);
	fore(i,0,m){
		cin>>u>>vv; u--; vv--;
		join(u,vv);
	}
	fore(i,0,n){
		mini[i]=N;
		maxi[i]=-1;
	}
	fore(i,0,n){
		mini[find_pa(i)]=min(mini[find_pa(i)],i);
		maxi[find_pa(i)]=max(maxi[find_pa(i)],i);
	}
	vector<pair<ll,ll>> v;
	fore(i,0,n){
		if(mini[i]!=N){
			v.pb({mini[i],maxi[i]});
		}
	}
	sort(ALL(v));
	ll res=0;
	ll maxr=-1;
	fore(i,0,SZ(v)){
		if(v[i].fst<=maxr){
			res++;
			maxr=max(maxr,v[i].snd);
		}else{
			maxr=max(maxr,v[i].snd);
		}
	}
	cout<<res;
	return 0;
}
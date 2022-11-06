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
ll pa[MAXN],sz[MAXN],c[MAXN];
vector<ll> el[MAXN];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b, int co){
	if((c[a]^c[b])==co)co=0;
	else co=1;
	int x=find_pa(a),y=find_pa(b);
	if(x!=y){
		if(sz[x]>=sz[y])swap(x,y);
		if(co){
			for(auto i:el[x])c[i]^=1;
		}
		for(auto i:el[x])el[y].pb(i);
		el[x].clear();
		sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1,c[i]=0,el[i]={i};}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<vector<ll>> a(n);
		fore(i,0,n){
			a[i].resize(n);
			fore(j,0,n)cin>>a[i][j];
		}
		dsu_init(n);
		fore(i,0,n){
			fore(j,i+1,n){
				ll pref=-1;
				if(a[i][j]>a[j][i])pref=1;
				if(a[i][j]<a[j][i])pref=0;
				if(find_pa(i)!=find_pa(j)&&pref!=-1)join(i,j,pref);
			}
		}
		fore(i,0,n){
			if(!c[i])continue;
			fore(j,0,n){
				if(i!=j)swap(a[i][j],a[j][i]);
			}
		}
		fore(i,0,n){
			fore(j,0,n){
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}
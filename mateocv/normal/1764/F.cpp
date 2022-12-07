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

const int MAXN=2020;

ll f[MAXN][MAXN];

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

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		fore(j,0,i+1){
			cin>>f[i][j];
		}
	}
	vector<pair<ll,pair<ll,ll>>> ed;
	fore(i,0,n){
		fore(j,0,i){
			ll val=f[i][i]+f[j][j]-2ll*f[i][j];
			if(val%n==0){
				ed.pb({val/n,{i,j}});
			}
		}
	}
	sort(ALL(ed));
	dsu_init(n);
	vector<pair<ll,pair<ll,ll>>> res;
	for(auto i:ed){
		auto x=i.snd.fst,y=i.snd.snd;
		if(find_pa(x)!=find_pa(y)){
			join(x,y);
			res.pb(i);
		}
	}
	for(auto i:res)cout<<i.snd.fst+1<<" "<<i.snd.snd+1<<" "<<i.fst<<"\n";
	return 0;
}
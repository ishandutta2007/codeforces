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

/*----------------DSU------------------*/
const int MAXN=1010;
int pa[2][MAXN],sz[2][MAXN];
ll find_pa(ll pos, ll k){
	if(pa[k][pos]!=pos)pa[k][pos]=find_pa(pa[k][pos],k);
	return pa[k][pos];
}
void join(int a, int b, ll k) {
	int x=find_pa(a,k),y=find_pa(b,k);
	if (x!=y) {
		if(sz[k][x]>=sz[k][y]) sz[k][x]+=sz[k][y],pa[k][y]=x;
		else sz[k][y]+=sz[k][x],pa[k][x]=y;
	}
}
void dsu_init(ll n, ll k){fore(i,0,n)pa[k][i]=i,sz[k][i]=1;}

int main(){FIN;
	ll n,m,mm; cin>>n>>m>>mm;
	dsu_init(n,0);
	dsu_init(n,1);
	fore(i,0,m){
		ll x,y; cin>>x>>y; x--; y--;
		join(x,y,0);
	}
	fore(i,0,mm){
		ll x,y; cin>>x>>y; x--; y--;
		join(x,y,1);
	}
	vector<pair<ll,ll>> res;
	fore(i,0,n){
		fore(j,i+1,n){
			if(find_pa(i,0)!=find_pa(j,0)&&find_pa(i,1)!=find_pa(j,1)){
				fore(k,0,2)join(i,j,k);
				res.pb({i,j});
			}
		}
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	
	return 0;
}
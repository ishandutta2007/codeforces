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
const ll N=5e5+10;
int pa[N],sz[N],c[N];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x,c[x]=max(c[x],c[y]);
		else sz[y]+=sz[x],pa[x]=y,c[y]=max(c[x],c[y]);
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

vector<ll> res;

ll MOD=1000000007;

int main(){FIN;
	ll n,m; cin>>n>>m;
	dsu_init(N);
	fore(i,0,n){
		ll k; cin>>k;
		if(k==1){
			ll x; cin>>x; x--;
			if(c[find_pa(x)]==0){
				c[find_pa(x)]=1;
				res.pb(i);
			}
		}else{
			assert(k==2);
			ll x,y; cin>>x>>y; x--; y--;
			if(find_pa(x)!=find_pa(y)){
				if(c[find_pa(x)]==0||c[find_pa(y)]==0){
					res.pb(i);
				}
				join(x,y);
			}
		}
	}
	ll cant=1;
	fore(i,0,SZ(res))cant=2ll*cant%MOD;
	cout<<cant<<" "<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<" ";
	cout<<"\n";
	
	return 0;
}
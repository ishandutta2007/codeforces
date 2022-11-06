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

ll t[505][505];

/*---------------- Union Find (DSU) ------------------*/
const ll N=1003;
int pa[N],sz[N];
vector<ll> vc[N];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]){
			sz[x]+=sz[y],pa[y]=x;
			for(auto i:vc[y])vc[x].pb(i);
		}
		else {
			sz[y]+=sz[x],pa[x]=y;
			for(auto i:vc[x])vc[y].pb(i);
		}
	}
}
void dsu_init(vector<ll> v){for(auto i:v)pa[i]=i,sz[i]=1,vc[i].clear(),vc[i]={i};}


ll us;
vector<ll> res;
vector<pair<ll,ll>> ed;

void solve(vector<ll> v, ll u){
	//for(auto i:v)cout<<i<<" ";
	//cout<<" con "<<u<<endl;
	if(SZ(v)==1)return;
	ll maxi=0;
	for(auto i:v){
		for(auto j:v){
			maxi=max(maxi,t[i][j]);
		}
	}
	res.pb(maxi);
	dsu_init(v);
	for(auto i:v){
		for(auto j:v){
			if(maxi!=t[i][j]){
				join(i,j);
			}
		}
	}
	vector<ll> f;
	for(auto i:v)if(find_pa(i)==i)f.pb(i);
	for(auto i:f){
		if(SZ(vc[i])>1){
			ed.pb({u,us}); us++;
			solve(vc[i],us-1);
		}else{
			ed.pb({u,vc[i][0]});
			solve(vc[i],vc[i][0]);
		}			
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		fore(j,0,n){
			cin>>t[i][j];
		}
	}
	us=n+1;
	fore(i,0,n)res.pb(t[i][i]);
	vector<ll> v;
	fore(i,0,n)v.pb(i);
	solve(v,us-1);
	cout<<us<<"\n";
	for(auto i:res)cout<<i<<" ";
	cout<<"\n"<<n+1<<"\n";
	for(auto i:ed)cout<<i.snd+1<<" "<<i.fst+1<<"\n";
	
	return 0;
}